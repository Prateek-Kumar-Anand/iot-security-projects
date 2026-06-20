[⬅ Back to main repository](../README.md)

# 🌐 ESP32 Web Server Projects — ESP32 DevKit V1

A toolbox of **browser-based mini apps** that run entirely on an ESP32 — no cloud, no external server, just your microcontroller serving HTML/JS/CSS straight to any device on your Wi-Fi network. 📲💡

---

## 📡 Network Mode at a Glance

ESP32 web servers connect in one of two ways. Knowing which mode a project uses tells you exactly how to reach it:

- **STA mode** — the ESP32 joins **your existing Wi-Fi network**. You edit `ssid`/`password` in the code, then find its IP via the Serial Monitor and visit that IP from any device on the same network.
- **AP (Access Point) mode** — the ESP32 creates **its own Wi-Fi hotspot**. You connect your phone/laptop directly to that hotspot, then visit `192.168.4.1` (the default ESP32 AP address) in a browser.

| Project | Mode | Default Network Name |
|---|---|---|
| 🧮 Graphing Calculator | STA | `YOUR_WIFI_NAME` *(placeholder — edit)* |
| 📐 Trig Visualizer | — | N/A *(no ESP32 networking code — see notes)* |
| 🌡️ Temp & Humidity Dashboard | STA | `YOUR_WIFI_NAME` *(placeholder — edit)* |
| 🖼️ Picture Server | STA | `YOUR_WIFI_NAME` *(placeholder — edit)* |
| 🎞️ Random GIF Server | AP | `ESP32-GIF` / `12345678` |
| 🌀 Fan Controller | AP | `ESP32-Fan` / `12345678` |
| 💡 Hotspot Light Control | AP | `ESP32-Light` / `12345678` |
| 🦾 Servo Web Control | AP | `ESP32_Servo` / `12345678` |
| 🚗 Motor Web Control | STA | `YOUR_WIFI_NAME` *(placeholder — edit)* |
| ⭕ Tic-Tac-Toe | STA | `YOUR_WIFI_NAME` *(placeholder — edit)* |
| 💬 Offline Chat Room | AP | `ENTER HOTSPOT NAME` *(placeholder — edit)* |
| 🔄 OTA Firmware Update | STA | hardcoded personal credentials *(replace before reuse)* |
| 🔐 Password Vault | AP | `ESP32 WEB SERVER` / `ENTER YOUR PASSWORD` *(placeholder — edit)* |
| 🍀 Hello / Good Luck Page | STA | `YOUR_WIFI_NAME` *(placeholder — edit)* |
| 🖥️ Hello on Display Module | — | N/A *(local TFT only, no networking)* |

---

## 📦 Included Projects

### 🧮 Dashboards & Visualizers

#### Advanced Graphing Calculator — `ESP32_Advanced_Graphing_Calculator.ino`
A Chart.js-powered graphing calculator served from the ESP32. Type multiple functions (e.g. `Math.sin(x); x*x; Math.cos(x)`) separated by `;`, then plot, zoom in, and zoom out — all rendered client-side in your browser via CDN-loaded Chart.js. ESP32 only serves the static page; all graphing math runs in JavaScript on the client.

#### Trigonometry Ratio Visualizer — `Trigonometry_ratio_on_web_server.ino`
An interactive canvas-based graphing tool for **trig and inverse trig functions** (sin, cos, tan, cosec, sec, cot, and their inverses) selectable via a dropdown.

> ⚠️ **Heads up:** this file currently contains **only the HTML/JS page** — it's missing the `WiFi.h` / `WebServer.h` wrapper code (`setup()`, `loop()`, `server.on()`) that every other project in this folder has. As-is, it won't compile as an Arduino sketch. To use it, wrap this HTML inside a `server.send(200, "text/html", ...)` call the same way `esp32_tictactoe.ino` does, or rename it `.html` and serve it from SPIFFS like the Picture Server does.

#### Temperature & Humidity Dashboard — `Temperature_and_humidity_on_chrome.ino`
A live weather-station style dashboard using a **DHT11 sensor** — auto-refreshing card UI (via `<meta http-equiv="refresh">`, every 2s) showing real-time temperature and humidity readings.

| Component | ESP32 Pin |
|---|---|
| DHT11 data pin | GPIO 4 |

```
DHT11 VCC  ── 3.3V
DHT11 GND  ── GND
DHT11 DATA ── GPIO 4 (add a 10kΩ pull-up to 3.3V if your module doesn't already have one onboard)
```

#### 📈 DHT11 + ST7735 Graph *(cross-reference)* — see `display_module/`
Companion project that plots sensor data directly on a TFT screen instead of (or alongside) the browser.

---

### 🖼️ Media & Fun

#### Picture on Web Server — `Picture_on_web_server.ino`
Serves an image (`photo.jpg`) stored on the ESP32's **SPIFFS filesystem** directly to a web page — a minimal example of media hosting from a microcontroller.

> 📌 The sketch only *reads* `/photo.jpg` from SPIFFS — it doesn't upload it for you. Before flashing, create a `data/` folder next to the `.ino` file, drop `photo.jpg` inside, and use the **ESP32 Sketch Data Upload** tool (Arduino IDE plugin, or "ESP32FS"/LittleFS uploader depending on your IDE version) to flash it to SPIFFS separately from the sketch itself.

#### Random GIF Server — `Web gif on esp32.ino` / `gif on web browser.txt`
Picks a random GIF from a hardcoded list of 5 Giphy URLs and displays it full-page with a "Next Random GIF" button to reload. Runs in **AP mode** (`ESP32-GIF` / `12345678`).

> 📌 Two things worth knowing: (1) the working sketch is actually in `gif on web browser.txt`, not the `.ino` file — see the root README's housekeeping note. (2) Because this connects your device to the ESP32's **own** hotspot (not your home Wi-Fi), your phone/laptop loses its regular internet connection while connected — and the GIFs themselves are hotlinked from `media.giphy.com`, which needs internet access to load. On most phones this works because of Wi-Fi/mobile-data failover, but on a laptop with no other connection, the images won't load even though the page itself does.

#### Tic-Tac-Toe — `esp32_tictactoe.ino`
A full **Tic-Tac-Toe game** rendered as a styled grid in-browser, with win/draw detection and a reset button. All game logic runs **client-side in JavaScript** — the ESP32 just serves the static page once; there's no server-side game state or multiplayer sync between devices.

#### "Good Luck" Page — `Good_luck_on_web_browser.ino`
A friendly, beginner-style starter project — connects to Wi-Fi and serves a styled "Good Luck! 🍀" landing page. Perfect first test to confirm your Wi-Fi + WebServer setup works before moving on to anything more complex.

#### Hello on Display Module — `hellow on display module.ino`
A minimal "Hello" text rendered on an ST7735 TFT — a sanity-check sketch for display wiring, no networking involved.

| Component | ESP32 Pin |
|---|---|
| TFT CS | GPIO 5 |
| TFT RST | GPIO 4 |
| TFT DC | GPIO 2 |

Uses `Adafruit_GFX` + `Adafruit_ST7735` over SPI (hardware SCK/MOSI pins, plus the CS/RST/DC pins above). This is really a `display_module/`-style project — it's just located in `web-server/` rather than `display_module/` (see root README notes).

---

### 🔌 Hardware Control

#### Fan Controller — `ESP32_Fan_Controller.ino`
A 4-speed (OFF / LOW / MEDIUM / HIGH) DC motor/fan controller driven via an **L298N** motor driver, with a button-based web UI. Runs in **AP mode** (`ESP32-Fan` / `12345678`).

| Component | ESP32 Pin |
|---|---|
| L298N ENA (PWM speed) | GPIO 25 |
| L298N IN1 | GPIO 26 |
| L298N IN2 | GPIO 27 |

PWM speed levels: `OFF=0`, `LOW=85`, `MEDIUM=170`, `HIGH=255` via `analogWrite()`.

> 📌 This sketch calls `analogWrite()` directly without setting up `ledcSetup()`/`ledcAttachPin()` first. That only works on **ESP32 Arduino core 3.x**, which added native `analogWrite()` support — older core versions (2.x) will fail to compile this and need the manual LEDC setup that `esp32_motor_web_control.ino` uses instead. Check your installed core version (**Tools → Board → Boards Manager**) if you hit a compile error here.

#### Hotspot Light Control — `ESP32_Hotspot_Light_Control.ino`
A standalone ON/OFF LED control page with no router required — the ESP32 creates its own hotspot (`ESP32-Light` / `12345678`) and you connect directly to it.

| Component | ESP32 Pin |
|---|---|
| LED / Relay signal | GPIO 2 |

Same wiring approach as the Button Light Control project in `manually-controling-projects/` — GPIO 2 doubles as most ESP32 DevKit V1 boards' built-in LED, so this works with zero extra components.

#### Servo Web Control — `ESP32_Servo_Web_Control.ino`
A browser slider (0–180°) drives a servo's angle live over Wi-Fi, sent via an AJAX `GET /servo?angle=` request on every slider move. Runs in **AP mode** (`ESP32_Servo` / `12345678`).

| Component | ESP32 Pin |
|---|---|
| Servo signal | GPIO 13 |

Requires the [`ESP32Servo`](https://github.com/madhephaestus/ESP32Servo) library (same as the button-controlled servo project — install via Library Manager, not the classic `Servo.h`).

#### Motor Web Control — `esp32_motor_web_control.ino`
Drive a **DC motor via L298N driver** with Forward / Backward / Stop buttons and a live speed slider (0–255), controlled over your existing Wi-Fi network (**STA mode**).

| Component | ESP32 Pin |
|---|---|
| L298N IN1 | GPIO 26 |
| L298N IN2 | GPIO 27 |
| L298N ENA (PWM speed) | GPIO 14 |

> 📌 Note this project's pin numbers (`ENA=14`) differ from the Fan Controller's (`ENA=25`) — they're independent sketches, not meant to run on the same board at once without re-checking your wiring against whichever one you're flashing. This sketch uses `ledcSetup()`/`ledcAttachPin()` for PWM, which is the more broadly-compatible approach across ESP32 core versions (see the Fan Controller note above).

---

### 🔐 Security & Connectivity

#### Offline Mini Chat Server — `offline_web_server.ino`
A self-hosted local chat room (no internet needed!) — login-gated with a single shared password, RAM-only message storage capped at **15 messages** (oldest drops off) and **70 words per message**. Runs in **AP mode**.

> 📌 The code header comments mention a "Max Users: 5" limit, but there's no actual user-count enforcement in the code — any number of devices can connect to the AP and chat simultaneously (limited only by the ESP32's general Wi-Fi client limit, typically ~4 in AP mode by default). Treat that comment as a design note rather than an enforced rule.

#### OTA Firmware Update — `ota_update.ino`
Enables **Over-The-Air (OTA)** updates via `ArduinoOTA` — once flashed once over USB, future code uploads can happen wirelessly through Arduino IDE instead of plugging in USB every time. Hostname is set to `ESP32-OTA`.

> 🔑 This file currently has **hardcoded personal Wi-Fi credentials** in `ssid`/`password` rather than the usual `YOUR_WIFI_NAME` placeholder used elsewhere in this repo — replace these with your own (or a placeholder) before sharing or reusing this sketch.

#### Password Saving Server — `web password saving server from esp32.ino`
A **vault-style login system** using `ESPAsyncWebServer` + `Preferences` (NVS flash storage) — a styled login page gated by an admin password, then a dashboard to save and list site/username/password entries. Runs in **AP mode** (`ESP32 WEB SERVER` hotspot).

Requires `ESPAsyncWebServer` + its dependency `AsyncTCP` (install both via Library Manager or from GitHub if not in the Library Manager index for your core version).

> 🛡️ Entries are stored **in plain text** inside NVS (`prefs.putString(...)`) — there's no hashing or encryption. This is fine for a personal-use learning project, but don't treat it as a real password manager without adding encryption first. Also note: the admin password check happens client-request-side per `/login` call with no session/cookie afterward, so `/dashboard` and `/save` are reachable directly by anyone on the network who knows (or guesses) the URL, even without logging in first.

---

## 🛠️ Requirements

### Hardware
- ✅ ESP32 DevKit V1
- ✅ USB cable
- ✅ Wi-Fi network (for STA-mode projects) — not needed for AP-mode projects, which create their own hotspot
- 🔩 *(Project-specific)* DHT11 sensor, L298N motor driver + DC motor/fan, micro servo, ST7735 display, LED/relay, push buttons

### Software
- ✅ Arduino IDE or Arduino Cloud
- ✅ ESP32 board package (ideally **core 3.x** — see the Fan Controller note above on `analogWrite()` compatibility)
- ✅ Libraries (varies per project):
  - `WiFi`, `WebServer` (built-in)
  - `ESP32Servo` (for Fan→no, for the two servo projects — install via Library Manager)
  - `ESPAsyncWebServer` + `AsyncTCP` (for the password vault)
  - `Preferences` (built-in, NVS storage)
  - `DHT sensor library` (Adafruit)
  - `Adafruit_GFX` + `Adafruit_ST7735` (for the display hello-world sketch)
  - `SPIFFS` (built-in)
  - `ArduinoOTA` (built-in)

---

## ▶️ Uploading the Code

1. 📂 Open the desired `.ino` file in Arduino IDE / Arduino Cloud.
2. ⚙️ Select **ESP32 Dev Module** as the board.
3. 📦 Install any missing libraries via Library Manager (check the per-project notes above).
4. 🔑 For **STA-mode** projects, update placeholder Wi-Fi credentials:
   ```cpp
   const char* ssid = "YOUR_WIFI_NAME";
   const char* password = "YOUR_WIFI_PASSWORD";
   ```
5. ⬆️ Compile and upload.
6. 🌐 **STA mode:** open the **Serial Monitor** at `115200 baud` to find the ESP32's IP address on your network, then visit it from any browser on the same network.
   **AP mode:** connect your phone/laptop's Wi-Fi directly to the ESP32's hotspot (see the network table above for the name/password), then visit `192.168.4.1`.

---

## ⚠️ Security Notes

- 🔑 **Always replace placeholder credentials** (`YOUR_WIFI_NAME`, `ENTER YOUR PASSWORD`, `ENTRE ADMIN PASS`, etc.) before deploying — and note the OTA sketch has real personal credentials hardcoded in, not a placeholder.
- 🔁 **Several AP-mode projects share the same default password (`12345678`)** — fine for one board at a time, but if you flash multiple boards and run them on overlapping Wi-Fi ranges, give each a unique SSID to avoid confusion about which hotspot you're connecting to.
- 🛡️ The password vault project stores data via `Preferences` (flash-backed NVS) in **plain text** — fine for personal/learning use, but not a substitute for proper hashing/encryption in production, and its `/dashboard`/`/save` routes aren't actually protected after the initial login check (see note above).
- 📡 AP-mode servers run on the ESP32's **own local hotspot only**; STA-mode servers run on your **local network only** — neither is exposed to the internet unless you configure port forwarding.

---

🚀 Power up your ESP32, connect to its IP (or its hotspot), and explore a whole suite of browser-based tools running on a $5 chip!
