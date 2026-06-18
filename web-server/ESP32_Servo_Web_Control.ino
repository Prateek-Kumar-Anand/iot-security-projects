#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

const char* ssid = "ESP32_Servo";
const char* password = "12345678";

WebServer server(80);
Servo myServo;
const int servoPin = 13;

String webpage = R"rawliteral(
<!DOCTYPE html>
<html>
<body style="text-align:center;">
<h2>ESP32 Servo Control</h2>
<input type="range" min="0" max="180" value="90" oninput="updateServo(this.value)">
<p>Angle: <span id="angle">90</span>°</p>
<script>
function updateServo(val){
 document.getElementById("angle").innerHTML=val;
 var xhr=new XMLHttpRequest();
 xhr.open("GET","/servo?angle="+val,true);
 xhr.send();
}
</script>
</body>
</html>
)rawliteral";

void handleRoot(){ server.send(200,"text/html",webpage); }

void handleServo(){
  if(server.hasArg("angle")){
    int angle=server.arg("angle").toInt();
    angle=constrain(angle,0,180);
    myServo.write(angle);
  }
  server.send(200,"text/plain","OK");
}

void setup(){
  myServo.attach(servoPin);
  myServo.write(90);
  WiFi.softAP(ssid,password);
  server.on("/",handleRoot);
  server.on("/servo",handleServo);
  server.begin();
}

void loop(){ server.handleClient(); }
