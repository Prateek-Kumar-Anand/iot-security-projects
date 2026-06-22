#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

WebServer server(80);

const char page[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>Lissajous Curves</title>
<style>
body{margin:0;background:#000;overflow:hidden;}
canvas{display:block;}
</style>
</head>
<body>
<canvas id="cv"></canvas>
<script>
const c=document.getElementById("cv");
const ctx=c.getContext("2d");

function resize(){
 c.width=window.innerWidth;
 c.height=window.innerHeight;
}
resize();
window.addEventListener("resize",resize);

let t=0;

function draw(){
 ctx.fillStyle="rgba(0,0,0,0.05)";
 ctx.fillRect(0,0,c.width,c.height);

 const A=c.width*0.35;
 const B=c.height*0.35;

 ctx.beginPath();

 for(let i=0;i<2000;i++){
   let p=i*0.01+t;
   let x=c.width/2 + A*Math.sin(3*p);
   let y=c.height/2 + B*Math.sin(4*p);

   if(i===0) ctx.moveTo(x,y);
   else ctx.lineTo(x,y);
 }

 ctx.strokeStyle=`hsl(${(t*100)%360},100%,60%)`;
 ctx.lineWidth=2;
 ctx.stroke();

 t+=0.01;
 requestAnimationFrame(draw);
}

draw();
</script>
</body>
</html>
)rawliteral";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid,password);

  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println(WiFi.localIP());

  server.on("/", [](){
    server.send(200,"text/html",page);
  });

  server.begin();
}

void loop() {
  server.handleClient();
}
