# 🖥️ ST7735 Display Projects — ESP32 DevKit V1

A collection of fun and practical projects built around the **ST7735 TFT display module**, paired with the ESP32 DevKit V1. From a fully playable Tetris-style game to live sensor graphs and a real-time networked message board! 🎮📊

---

## 📦 What's Inside

| Project | File | Description |
|---|---|---|
| 🧱 **Block Game** | `block_game.ino` | A Tetris-style falling block game with a 10×20 grid, button controls (left/right/rotate/drop), scoring, levels, and increasing fall speed. |
| 💬 **ESP32 ↔ TFT Chat** | `esp32_st7735_chat.ino` | Hosts a web page where you type a message in your browser, and it instantly appears on the ST7735 screen — your ESP32 becomes a tiny networked message board! |
| 🌡️ **DHT11 Live Graph** | `esp32_dht11_display_graph.ino` | Reads temperature & humidity from a DHT11 sensor and plots a real-time scrolling graph directly on the TFT display. |

---

## 🔌 Wiring

### ST7735 TFT — Common Pinout

| ST7735 Pin | ESP32 Pin (example) |
|---|---|
| CS | GPIO 5 / 15 *(varies per project — check top of file)* |
| DC | GPIO 2 / 16 |
| RST | GPIO 4 / 17 |
| SCK | Default SPI SCK (GPIO 18) |
| SDA / MOSI | Default SPI MOSI (GPIO 23) |
| VCC | 3.3V |
| GND | GND |

> ⚠️ **Pin numbers differ between projects!** Always check the `#define TFT_CS / TFT_DC / TFT_RST` lines at the top of each `.ino` file before wiring.

### Block Game — Additional Push Buttons

| Button | ESP32 Pin |
|---|---|
| Left | GPIO 12 |
| Right | GPIO 13 |
| Rotate | GPIO 14 |
| Drop | GPIO 27 |

Wire each button between its GPIO pin and **GND**. The internal pull-up (`INPUT_PULLUP`) is used in code, so no external resistors are needed.

### DHT11 Live Graph — Sensor Wiring

| DHT11 Pin | ESP32 Pin |
|---|---|
| DATA | GPIO 4 |
| VCC | 3.3V |
| GND | GND |

---

## 📚 Required Libraries

Install via Arduino **Library Manager** (`Ctrl+Shift+I`):

| Library | Projects |
|---|---|
| `Adafruit GFX Library` | All |
| `Adafruit ST7735 and ST7789 Library` | All |
| `DHT sensor library` | `esp32_dht11_display_graph.ino` |
| `WiFi` *(built-in)* | `esp32_st7735_chat.ino` |
| `WebServer` *(built-in)* | `esp32_st7735_chat.ino` |

---

## ▶️ Uploading the Code

1. Open the desired `.ino` file in **Arduino IDE** or **Arduino Cloud**.
2. Select **ESP32 Dev Module** as the target board.
3. Install any missing libraries listed above.
4. For Wi-Fi projects, update the credentials:
   ```cpp
   const char* ssid     = "YOUR_WIFI_NAME";
   const char* password = "YOUR_WIFI_PASSWORD";
   ```
5. Click **Upload** (`Ctrl+U`) to flash.
6. For the chat project, open **Serial Monitor** at `115200 baud` to get the ESP32's IP address, then visit it in your browser.

---

## 🎮 Project Details

### 🧱 Block Game (`block_game.ino`)

A miniature Tetris running entirely on a microcontroller — grid logic, piece falling, line clearing, and a scoring system, all rendered on a 128×160 TFT. Uses `Adafruit_ST7735` for rendering and reads 4 hardware buttons for input.

- **Grid:** 10 columns × 20 rows, each cell 6×6 px
- **Scoring:** Points per line cleared; speed increases with level
- **Pins:** CS=15, DC=2, RST=4 | Buttons: 12, 13, 14, 27

### 💬 ESP32 ↔ TFT Chat (`esp32_st7735_chat.ino`)

Connects to Wi-Fi, hosts a minimal web page, and pushes any text you type straight onto the physical TFT screen in real time. A great intro to combining `WebServer` + `Adafruit_GFX`.

- **Pins:** CS=5, DC=2, RST=4
- **How to use:** Flash → get IP from Serial Monitor → open IP in browser → type and send

### 🌡️ DHT11 Live Graph (`esp32_dht11_display_graph.ino`)

A self-updating environmental dashboard — reads temperature and humidity every second and renders a scrolling line graph across the 128-pixel-wide display. No phone or laptop needed.

- **Pins:** CS=5, DC=16, RST=17 | DHT11 DATA=4
- **Display mode:** Landscape (`setRotation(1)`)

---

## ⚠️ Notes

- 🖥️ Default display init is `tft.initR(INITR_BLACKTAB)` — change this if your ST7735 module has a **red tab** (`INITR_REDTAB`) or **green tab** (`INITR_GREENTAB`).
- 🔑 Update `ssid` / `password` before uploading any Wi-Fi-based sketch.
- 🧩 Most code here can be adapted to other `Adafruit_GFX`-compatible displays (ILI9341, SSD1306, etc.) with minor pin/init changes.

---

✨ Tinker, remix, and build something cool on that tiny screen!
