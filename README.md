# 🔐 IoT Security Projects — ESP32 DevKit V1

A growing collection of **ESP32-based IoT, security, and embedded systems projects** — from password vaults and motion-sensitive displays to browser-controlled robots and tiny web apps that run entirely off your microcontroller. 🚀

---

## 📦 About This Repository

This repo is a personal playground and project archive for everything built on the **ESP32 DevKit V1**. The focus areas include:

- 🛡️ **Security-oriented IoT devices** — password vaults, login-gated web servers, OTA-secured firmware updates
- 🖥️ **Display-based gadgets** — ST7735 TFT screens used for games, sensor graphs, and live chat displays
- 🌐 **Browser-controlled hardware** — motors, sensors, and games served straight from the ESP32's own web server

Each project is self-contained as a single `.ino` sketch, so you can grab exactly what you need without pulling in the whole repo.

---

## 🗂️ Repository Structure

```
iot-security-projects/
├── 📁 display_module/    → ST7735 TFT display projects (games, graphs, chat UI)
└── 📁 web-server/         → ESP32 web server projects (dashboards, games, vaults, OTA)
```

Every sub-folder contains:

- 📄 One or more `.ino` Arduino sketches
- 📘 Its own `README.md` with setup, wiring, and usage details

---

## 🛠️ General Requirements

### Hardware
- ✅ ESP32 DevKit V1
- ✅ USB cable (data-capable, not charge-only!)
- ✅ Wi-Fi network for connectivity-based projects
- ✅ Project-specific components (TFT display, sensors, motors, etc.)

### Software
- ✅ [Arduino IDE](https://www.arduino.cc/en/software) or [Arduino Cloud](https://create.arduino.cc/)
- ✅ ESP32 board package installed
- ✅ Required libraries (listed per project)

---

## ▶️ Getting Started

1. Pick a project folder (`display_module` or `web-server`).
2. Open its `README.md` for specific instructions.
3. Open the desired `.ino` file in Arduino IDE / Arduino Cloud.
4. Select **ESP32 Dev Module** as the board.
5. Install any missing libraries.
6. Update Wi-Fi credentials (`ssid` / `password`) where needed.
7. Compile, upload, and enjoy! 🎉

---

## ⚠️ Important Notes

- 🔑 Most projects use placeholder Wi-Fi credentials (`YOUR_WIFI_NAME`, `YOUR_WIFI_PASSWORD`) — **update these before flashing**.
- 🔌 Pin numbers may need adjusting depending on your exact wiring.
- 📚 Check the top of each `.ino` file for required libraries and notes.

---

## 📌 Disclaimer

These projects are built for **learning, experimentation, and personal use**. Some include hardcoded test credentials in source code for demo purposes — always change these before deploying on a real network. 🔒

---

⭐ If you find something useful here, feel free to explore, fork, and build on it!
