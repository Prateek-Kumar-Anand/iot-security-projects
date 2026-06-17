#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "ESP32-Fan";
const char* password = "12345678";

WebServer server(80);

#define ENA 25
#define IN1 26
#define IN2 27

void handleRoot() {

String html = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>ESP32 Fan Control</title>
<style>
body{
font-family:Arial;
text-align:center;
margin-top:40px;
}
button{
width:150px;
height:60px;
font-size:18px;
margin:5px;
}
</style>
</head>
<body>

<h2>ESP32 Fan Controller</h2>

<a href="/off"><button>OFF</button></a><br><br>
<a href="/low"><button>LOW</button></a><br><br>
<a href="/medium"><button>MEDIUM</button></a><br><br>
<a href="/high"><button>HIGH</button></a>

</body>
</html>
)rawliteral";

server.send(200,"text/html",html);
}

void motorSpeed(int speedVal)
{
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
analogWrite(ENA,speedVal);
}

void setup()
{
Serial.begin(115200);

pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(ENA,OUTPUT);

WiFi.softAP(ssid,password);

Serial.print("IP Address: ");
Serial.println(WiFi.softAPIP());

server.on("/",handleRoot);

server.on("/off",[](){
analogWrite(ENA,0);
server.sendHeader("Location","/");
server.send(303);
});

server.on("/low",[](){
motorSpeed(85);
server.sendHeader("Location","/");
server.send(303);
});

server.on("/medium",[](){
motorSpeed(170);
server.sendHeader("Location","/");
server.send(303);
});

server.on("/high",[](){
motorSpeed(255);
server.sendHeader("Location","/");
server.send(303);
});

server.begin();
}

void loop()
{
server.handleClient();
}
