# 🔐 IoT Security Projects — ESP32 DevKit V1

A growing collection of **ESP32-based IoT, security, and embedded systems projects** — from password vaults and motion-sensitive alarms to browser-controlled motors/servos and tiny web apps that run entirely off your microcontroller. 🚀

---

## 📦 About This Repository

This repo is a personal playground and project archive for everything built on the **ESP32 DevKit V1**. The focus areas include:

- 🛡️ **Security-oriented IoT devices** — password vaults, login-gated web servers, OTA-secured firmware updates
- 🖥️ **Display-based gadgets** — ST7735 TFT screens used for games, sensor graphs, and live chat displays
- 🌐 **Browser-controlled hardware** — motors, fans, servos, lights, and games served straight from the ESP32's own web server
- 🔘 **Manual & sensor-based control** — physical buttons and a PIR motion sensor for real-time GPIO control, no Wi-Fi required

Each project is self-contained as a single `.ino` sketch, so you can grab exactly what you need without pulling in the whole repo.

---

## 🗂️ Repository Structure

```
iot-security-projects/
├── 📁 display_module/                → ST7735 TFT display projects (games, graphs, chat UI)
├── 📁 manually-controling-projects/  → Physical button / PIR sensor / GPIO control projects
└── 📁 web-server/                    → ESP32 web server projects (dashboards, games, vaults, OTA, motor/servo control)
```

Every sub-folder contains:

- 📄 One or more `.ino` Arduino sketches
- 📘 Its own `README.md` with setup, wiring, and usage details

---

## 🗺️ Project Index

### 🖥️ [`display_module/`](./display_module/README.md)
| Project | File | Description |
|---|---|---|
| 🧱 Block Game | `block_game.ino` | Tetris-style falling block game on a 128×160 TFT |
| 💬 ESP32 ↔ TFT Chat | `esp32_st7735_chat.ino` | Browser → ESP32 → TFT live message board |
| 🌡️ DHT11 Live Graph | `esp32_dht11_display_graph.ino` | Scrolling temp & humidity graph on TFT |

### 🔘 [`manually-controling-projects/`](./manually-controling-projects/README.md)
| Project | File | Description |
|---|---|---|
| 💡 Button Light Control | `ESP32_Button_Light_Control.ino` | Two-button ON/OFF control for LED or relay |
| 🚨 PIR Motion Detector | `ESP32_PIR_Motion_Detector.ino` | PIR sensor triggers a buzzer alarm on motion |
| 🦾 Servo Button Control | `ESP32_Servo_Button_Control.ino` | Two buttons step a servo arm up/down by 5° |

### 🌐 [`web-server/`](./web-server/README.md)
| Project | File | Description |
|---|---|---|
| 🧮 Graphing Calculator | `ESP32_Advanced_Graphing_Calculator.ino` | Chart.js-powered function plotter |
| 📐 Trig Visualizer | `Trigonometry_ratio_on_web_server.ino` | Interactive canvas trig grapher |
| 🌡️ Temp & Humidity Dashboard | `Temperature_and_humidity_on_chrome.ino` | Live DHT11 sensor dashboard |
| 🖼️ Picture Server | `Picture_on_web_server.ino` | Serve images from SPIFFS over HTTP |
| 🎞️ Random GIF Server | `Web gif on esp32.ino` / `gif on web browser.txt` | Browser button cycles through random GIFs from a hosted list |
| 🌀 Fan Controller | `ESP32_Fan_Controller.ino` | OFF/LOW/MEDIUM/HIGH PWM speed control for a DC motor/fan via L298N |
| 💡 Hotspot Light Control | `ESP32_Hotspot_Light_Control.ino` | Standalone Wi-Fi AP + web page for ON/OFF LED control |
| 🦾 Servo Web Control | `ESP32_Servo_Web_Control.ino` | Browser slider drives a servo angle (0–180°) via AJAX |
| 🚗 Motor Web Control | `esp32_motor_web_control.ino` | L298N DC motor control via browser |
| ⭕ Tic-Tac-Toe | `esp32_tictactoe.ino` | In-browser multiplayer game from the ESP32 |
| 💬 Offline Chat Room | `offline_web_server.ino` | Local network mini-chat server (no internet needed) |
| 🔄 OTA Firmware Update | `ota_update.ino` | Wireless code uploads over Wi-Fi |
| 🔐 Password Vault | `web password saving server from esp32.ino` | Login-gated NVS password storage |
| 🍀 Hello / Good Luck Page | `Good_luck_on_web_browser.ino` | Beginner-friendly Wi-Fi + WebServer test |
| 🖥️ Hello on Display Module | `hellow on display module.ino` | Minimal ST7735 "Hello World" text test |

---

## 🛠️ General Requirements

### Hardware
- ✅ ESP32 DevKit V1
- ✅ USB cable (data-capable, not charge-only!)
- ✅ Wi-Fi network (or the ESP32's own AP mode) for connectivity-based projects
- ✅ Project-specific components (TFT display, DHT11 sensor, PIR sensor, servo, L298N motor driver, buttons — see each folder's README)

### Software
- ✅ [Arduino IDE](https://www.arduino.cc/en/software) or [Arduino Cloud](https://create.arduino.cc/)
- ✅ ESP32 board package installed (`https://espressif.github.io/arduino-esp32/package_esp32_index.json`)
- ✅ Required libraries (varies by project — commonly `WiFi.h`, `WebServer.h`, `ESP32Servo`, `Adafruit_GFX` / `Adafruit_ST7735`, `DHT`)

---

## ▶️ Getting Started

1. Pick a project folder.
2. Open its `README.md` for specific wiring and setup instructions.
3. Open the desired `.ino` file in Arduino IDE or Arduino Cloud.
4. Select **ESP32 Dev Module** as the board.
5. Install any missing libraries via **Library Manager** (`Ctrl+Shift+I`).
6. Update Wi-Fi credentials (`ssid` / `password`) where needed.
7. Compile, upload, and enjoy! 🎉

---

## ⚠️ Important Notes

- 🔑 Most network projects use placeholder Wi-Fi/AP credentials (`YOUR_WIFI_NAME`, `ESP32-Fan`, `12345678`, etc.) — **update these before flashing**, especially the default `12345678` AP passwords used across several sketches.
- 🔌 Pin numbers may need adjusting depending on your exact wiring.
- 📚 Check the top of each `.ino` file for required libraries and any additional setup notes.
- 🧪 These are learning and experimentation projects — harden credentials and configs before any real deployment.
- 🧹 Housekeeping for next cleanup pass: `gif on web browser.txt` holds the actual GIF-server sketch while `Web gif on esp32.ino` is just a connection note — consider renaming the `.txt` to `.ino` and merging them. `hellow on display module.ino` is a TFT test but currently lives in `web-server/` instead of `display_module/`.

---

## 📌 Disclaimer

These projects are built for **learning, experimentation, and personal use**. Some include hardcoded test credentials in source code for demo purposes — always change these before deploying on a real network. 🔒

---

⭐ If you find something useful here, feel free to explore, fork, and build on it!
