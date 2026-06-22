/*
 ESP32 Radar Project
 Hardware:
 - ESP32 DevKit V1
 - HC-SR04 Ultrasonic Sensor
 - SG90 Servo

 Connections:
 HC-SR04 TRIG -> GPIO 5
 HC-SR04 ECHO -> GPIO 18
 Servo Signal  -> GPIO 13

 Install:
 ESP32Servo library
*/

#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

WebServer server(80);
Servo radarServo;

#define TRIG_PIN 5
#define ECHO_PIN 18
#define SERVO_PIN 13

int angle = 0;
bool forwardSweep = true;

long getDistance() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  long distance = duration * 0.034 / 2;

  return distance;
}

const char WEBPAGE[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>ESP32 Radar</title>
<style>
body{
background:black;
margin:0;
overflow:hidden;
}
canvas{
display:block;
}
</style>
</head>
<body>

<canvas id="radar"></canvas>

<script>

const canvas=document.getElementById("radar");
const ctx=canvas.getContext("2d");

function resize(){
 canvas.width=window.innerWidth;
 canvas.height=window.innerHeight;
}
resize();
window.addEventListener("resize",resize);

let points=[];
let sweepAngle=0;

async function updateRadar(){

 try{

   const data=await fetch('/radar')
   .then(r=>r.json());

   sweepAngle=data.angle;

   points.push(data);

   if(points.length>400)
      points.shift();

 }catch(e){}
}

function draw(){

 ctx.fillStyle="rgba(0,0,0,0.25)";
 ctx.fillRect(0,0,
 canvas.width,
 canvas.height);

 let cx=canvas.width/2;
 let cy=canvas.height-40;

 ctx.strokeStyle="lime";
 ctx.lineWidth=2;

 for(let r=100;r<=400;r+=100){

   ctx.beginPath();
   ctx.arc(cx,cy,r,Math.PI,2*Math.PI);
   ctx.stroke();
 }

 for(let a=0;a<=180;a+=30){

   let rad=(a-180)*Math.PI/180;

   ctx.beginPath();
   ctx.moveTo(cx,cy);
   ctx.lineTo(
      cx+400*Math.cos(rad),
      cy+400*Math.sin(rad)
   );
   ctx.stroke();
 }

 let beam=(sweepAngle-180)*Math.PI/180;

 ctx.strokeStyle="#00ff00";

 ctx.beginPath();
 ctx.moveTo(cx,cy);
 ctx.lineTo(
   cx+400*Math.cos(beam),
   cy+400*Math.sin(beam)
 );
 ctx.stroke();

 points.forEach(p=>{

   let rad=(p.angle-180)*Math.PI/180;

   let dist=Math.min(p.distance*3,400);

   let x=cx+dist*Math.cos(rad);
   let y=cy+dist*Math.sin(rad);

   ctx.fillStyle="red";

   ctx.beginPath();
   ctx.arc(x,y,4,0,Math.PI*2);
   ctx.fill();
 });

 requestAnimationFrame(draw);
}

setInterval(updateRadar,50);

draw();

</script>

</body>
</html>
)rawliteral";

void handleRoot() {
  server.send(200, "text/html", WEBPAGE);
}

void handleRadar() {

  radarServo.write(angle);

  delay(20);

  long distance = getDistance();

  String json =
      "{\"angle\":" + String(angle) +
      ",\"distance\":" + String(distance) +
      "}";

  server.send(200, "application/json", json);

  if(forwardSweep){
      angle++;
      if(angle >= 180)
         forwardSweep = false;
  }
  else{
      angle--;
      if(angle <= 0)
         forwardSweep = true;
  }
}

void setup() {

  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  radarServo.attach(SERVO_PIN);

  WiFi.begin(ssid,password);

  Serial.print("Connecting");

  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/radar", handleRadar);

  server.begin();
}

void loop() {
  server.handleClient();
}
