# 🌐 ESP32 Web Server Projects — ESP32 DevKit V1

A toolbox of **browser-based mini apps** that run entirely on an ESP32 — no cloud, no external server, just your microcontroller serving HTML/JS/CSS straight to any device on your Wi-Fi network. 📲💡

---

## 📦 Included Projects

### 🧮 Advanced Graphing Calculator — `ESP32_Advanced_Graphing_Calculator.ino`
A Chart.js-powered graphing calculator served from the ESP32. Type multiple functions (e.g. `Math.sin(x); x*x; Math.cos(x)`) separated by `;`, then plot, zoom in, and zoom out — all in your browser.

### 📐 Trigonometry Ratio Visualizer — `Trigonometry_ratio_on_web_server.ino`
An interactive canvas-based graphing tool for **trig and inverse trig functions** (sin, cos, tan, cosec, sec, cot, and their inverses) selectable via a dropdown.

### 🌡️ Temperature & Humidity Dashboard — `Temperature_and_humidity_on_chrome.ino`
A live weather-station style dashboard using a **DHT11 sensor** — auto-refreshing card UI showing real-time temperature and humidity readings.

### 📈 DHT11 + ST7735 Graph *(cross-reference)* — see `display_module/`
Companion project that plots sensor data directly on a TFT screen instead of (or alongside) the browser.

### 🖼️ Picture on Web Server — `Picture_on_web_server.ino`
Serves an image (`photo.jpg`) stored on the ESP32's **SPIFFS filesystem** directly to a web page — a minimal example of media hosting from a microcontroller.

### 🎞️ GIF on Web Browser — `Web gif on esp32.ino` / `gif on web browser.txt`
Notes and a sketch exploring serving animated GIFs from the ESP32 to a browser.

### 🍀 "Good Luck" Page — `Good_luck_on_web_browser.ino`
A friendly, beginner-style starter project — connects to Wi-Fi and serves a styled "Good Luck! 🍀" landing page. Perfect first test to confirm your Wi-Fi + WebServer setup works.

### 🖥️ Hello on Display Module — `hellow on display module.ino`
A simple "Hello" text rendered on an ST7735 TFT — a sanity-check sketch for display wiring (companion to `display_module/`).

### 🚗 Motor Web Control — `esp32_motor_web_control.ino`
Drive a **DC motor via L298N driver** using PWM speed control, with a web interface to start, stop, and adjust speed remotely.

### ⭕ Tic-Tac-Toe — `esp32_tictactoe.ino`
A full **Tic-Tac-Toe game** rendered as a styled grid in-browser, with game logic and a reset button — playable from any phone or laptop on the network.

### 💬 Offline Mini Chat Server — `offline_web_server.ino`
A self-hosted local chat room (no internet needed!) — supports up to **5 users**, **15 messages**, with temporary RAM storage. Great for offline events or demos.

### 🔄 OTA Firmware Update — `ota_update.ino`
Enables **Over-The-Air (OTA)** updates — once flashed, future code uploads can happen wirelessly via Arduino IDE instead of plugging in USB every time.

### 🔐 Password Saving Server — `web password saving server from esp32.ino`
A **vault-style login system** using `ESPAsyncWebServer` + `Preferences` (NVS storage) — features a styled login page and admin password protection for securely storing data on-device.

---

## 🛠️ Requirements

### Hardware
- ✅ ESP32 DevKit V1
- ✅ USB cable
- ✅ Wi-Fi network
- 🔩 *(Project-specific)* DHT11 sensor, L298N motor driver + DC motor, ST7735 display

### Software
- ✅ Arduino IDE or Arduino Cloud
- ✅ ESP32 board package
- ✅ Libraries (varies per project):
  - `WiFi`, `WebServer` (built-in)
  - `ESPAsyncWebServer` + `AsyncTCP` (for the password vault)
  - `Preferences` (built-in, NVS storage)
  - `DHT sensor library`
  - `SPIFFS` (built-in)
  - `ArduinoOTA` (built-in)

---

## ▶️ Uploading the Code

1. 📂 Open the desired `.ino` file in Arduino IDE / Arduino Cloud.
2. ⚙️ Select **ESP32 Dev Module** as the board.
3. 📦 Install any missing libraries via Library Manager.
4. 🔑 Update placeholder Wi-Fi credentials:
   ```cpp
   const char* ssid = "YOUR_WIFI_NAME";
   const char* password = "YOUR_WIFI_PASSWORD";
   ```
5. ⬆️ Compile and upload.
6. 🌐 Open the **Serial Monitor** at `115200 baud` to find the ESP32's IP address.
7. 💻 Visit that IP from any browser on the same network!

---

## ⚠️ Security Notes

- 🔑 **Always replace placeholder credentials** (`YOUR_WIFI_NAME`, `ENTER YOUR PASSWORD`, `ENTRE ADMIN PASS`, etc.) before deploying.
- 🛡️ The password vault project stores data via `Preferences` (flash-backed NVS) — fine for personal/learning use, but not a substitute for proper encryption in production.
- 📡 These servers run on your **local network only** by default — they are not exposed to the internet unless you configure port forwarding.

---

🚀 Power up your ESP32, connect to its IP, and explore a whole suite of browser-based tools running on a $5 chip!
