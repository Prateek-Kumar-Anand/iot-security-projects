#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "ESP32-Light";
const char* password = "12345678";

WebServer server(80);

const int ledPin = 2;

void handleRoot() {
  String html = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>ESP32 Light Control</title>
<style>
body{
  font-family: Arial;
  text-align:center;
  margin-top:50px;
}
button{
  width:120px;
  height:60px;
  font-size:20px;
  margin:10px;
}
</style>
</head>
<body>
<h2>ESP32 Light Control</h2>

<p>
<a href="/on"><button>ON</button></a>
<a href="/off"><button>OFF</button></a>
</p>

</body>
</html>
)rawliteral";

  server.send(200, "text/html", html);
}

void handleOn() {
  digitalWrite(ledPin, HIGH);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleOff() {
  digitalWrite(ledPin, LOW);
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  WiFi.softAP(ssid, password);

  Serial.println("Access Point Started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);

  server.begin();
}

void loop() {
  server.handleClient();
}
