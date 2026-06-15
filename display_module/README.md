# 🖥️ ST7735 Display Projects — ESP32 DevKit V1

A collection of fun and practical projects built around the **ST7735 TFT display module**, paired with the ESP32 DevKit V1. From simple "Hello World" screens to a fully playable Tetris-style game and live sensor graphs! 🎮📊

---

## 📦 What's Inside

| Project | File | Description |
|---|---|---|
| 🧱 **Block Game** | `block_game.ino` | A Tetris-style falling block game with a 10×20 grid, button controls (left/right/rotate/drop), scoring, levels, and increasing fall speed. |
| 💬 **ESP32 ↔ TFT Chat** | `esp32_st7735_chat.ino` | Hosts a web page where you type a message in your browser, and it instantly appears on the ST7735 screen — your ESP32 becomes a tiny networked message board! |
| 🌡️ **DHT11 Live Graph** | `esp32_dht11_display_graph.ino` | Reads temperature & humidity from a DHT11 sensor and plots a real-time scrolling graph directly on the TFT display. |

---

## 🔌 Wiring (Typical ST7735 Pinout)

| ST7735 Pin | ESP32 Pin (example) |
|---|---|
| CS | GPIO 5 / 15 *(varies per project — check top of file)* |
| DC | GPIO 2 / 16 |
| RST | GPIO 4 / 17 |
| SCK | Default SPI SCK |
| SDA / MOSI | Default SPI MOSI |
| VCC | 3.3V |
| GND | GND |

> ⚠️ **Pin numbers differ between projects!** Always check the `#define TFT_CS / TFT_DC / TFT_RST` lines at the top of each `.ino` file before wiring.

For the **Block Game**, you'll also need 4 push buttons:
- GPIO 12 → Left
- GPIO 13 → Right
- GPIO 14 → Rotate
- GPIO 27 → Drop

---

## 📚 Required Libraries

Install via Arduino Library Manager:

- `Adafruit GFX Library`
- `Adafruit ST7735 and ST7789 Library`
- `DHT sensor library` (for the graph project)
- `WiFi` & `WebServer` (built-in, for the chat project)

---

## ▶️ Uploading the Code

For the smoothest experience, use **Arduino Cloud**:

1. Create a free [Arduino Cloud](https://create.arduino.cc/) account.
2. Download the desired `.ino` file from this folder.
3. Upload it as a new sketch in Arduino Cloud.
4. Select **ESP32 Dev Module** as the target board.
5. Install the libraries listed above if prompted.
6. Click **Upload** to flash it to your ESP32.

> 💡 You can also use the regular **Arduino IDE** — just make sure the ESP32 board package and libraries are installed.

---

## 🎮 Project Highlights

### 🧱 Block Game
A miniature Tetris running entirely on a microcontroller — grid logic, piece falling, line clearing, and a scoring system, all rendered on a 128×160 TFT.

### 💬 ESP32 ↔ TFT Chat
Connects to Wi-Fi, hosts a lightweight web page, and pushes any text you type straight onto the physical screen in real time. Great intro to combining `WebServer` + `Adafruit_GFX`.

### 🌡️ DHT11 Live Graph
A self-updating environmental dashboard — no phone or laptop needed, just glance at the screen to see the temperature & humidity trend over time.

---

## ⚠️ Notes

- 🔑 Update `ssid` / `password` placeholders before uploading Wi-Fi-based sketches.
- 🖥️ Default display init is `tft.initR(INITR_BLACKTAB)` — change this if you're using a different ST7735 variant (red/green/black tab).
- 🧩 Most code here can be adapted to other Adafruit GFX-compatible displays with minor pin/init changes.

---

✨ Tinker, remix, and build something cool on that tiny screen!
