#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

WebServer server(80);

const char webpage[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>ESP32 Math Animation</title>
<style>
body { margin:0; background:black; overflow:hidden; }
canvas { display:block; }
</style>
</head>
<body>
<canvas id="c"></canvas>
<script>
const canvas = document.getElementById("c");
const ctx = canvas.getContext("2d");

function resize(){
  canvas.width = window.innerWidth;
  canvas.height = window.innerHeight;
}
resize();
window.addEventListener("resize", resize);

let t = 0;

function animate(){
  ctx.fillStyle = "rgba(0,0,0,0.15)";
  ctx.fillRect(0,0,canvas.width,canvas.height);

  ctx.beginPath();

  for(let x = 0; x < canvas.width; x++){
      let y = canvas.height/2 +
              Math.sin((x*0.02)+t)*120 +
              Math.cos((x*0.01)-t)*60;

      if(x===0) ctx.moveTo(x,y);
      else ctx.lineTo(x,y);
  }

  ctx.strokeStyle = `hsl(${(t*50)%360},100%,60%)`;
  ctx.lineWidth = 2;
  ctx.stroke();

  t += 0.03;
  requestAnimationFrame(animate);
}

animate();
</script>
</body>
</html>
)rawliteral";

void handleRoot() {
  server.send(200, "text/html", webpage);
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected! IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
}
)