# 🔘 Manual Control Projects — ESP32 DevKit V1

Simple, no-frills projects that put **physical hardware directly in control** — buttons, switches, and GPIO pins doing the work with no Wi-Fi, no browser, and no cloud needed. Perfect for getting started with GPIO and understanding the basics before layering in networking or displays. 🛠️

---

## 📦 What's Inside

| Project | File | Description |
|---|---|---|
| 💡 **Button Light Control** | `ESP32_Button_Light_Control.ino` | Two push buttons (ON / OFF) control an LED or relay output in real time. |

---

## 🔌 Wiring

### 💡 Button Light Control

| Component | ESP32 Pin |
|---|---|
| LED / Relay signal | GPIO 2 |
| ON Button | GPIO 18 |
| OFF Button | GPIO 19 |

**Wiring steps:**

1. **LED:** Connect the anode (+) through a **220Ω resistor** to GPIO 2; cathode (−) to GND.  
   *(Or connect a relay module's IN pin to GPIO 2, VCC to 3.3V/5V, GND to GND.)*
2. **Buttons:** Wire each button between its GPIO pin and **GND**. `INPUT_PULLUP` is used in code, so no external pull-up resistors are needed.

```
GPIO 18 ──[BUTTON_ON]── GND
GPIO 19 ──[BUTTON_OFF]── GND
GPIO  2 ──[220Ω]──[LED+]  [LED-]── GND
```

---

## 📚 Required Libraries

None — this project uses only built-in Arduino / ESP32 core functions (`pinMode`, `digitalWrite`, `digitalRead`). No library installs needed.

---

## ▶️ Uploading the Code

1. Open `ESP32_Button_Light_Control.ino` in **Arduino IDE** or **Arduino Cloud**.
2. Select **ESP32 Dev Module** as the board.
3. Connect your ESP32 via USB.
4. Click **Upload** (`Ctrl+U`).
5. Press the **ON button** → LED turns on. Press **OFF button** → LED turns off.

---

## 🔍 How It Works

```cpp
const int ledPin    = 2;   // Output: LED or Relay
const int onButton  = 18;  // Input: ON button (active LOW)
const int offButton = 19;  // Input: OFF button (active LOW)
```

Both button pins are set as `INPUT_PULLUP` — they read `HIGH` when not pressed and go `LOW` when pressed (because they connect to GND). The `loop()` polls both pins continuously with a 200ms debounce delay after each detected press.

- Press **ON button** → `digitalWrite(ledPin, HIGH)` — output goes HIGH
- Press **OFF button** → `digitalWrite(ledPin, LOW)` — output goes LOW

This is a **non-latching push state** model (not a toggle), so the output stays in the last commanded state even after releasing the button.

---

## 💡 Project Ideas / Extensions

- **Relay control:** Replace the LED with a relay module to switch mains-voltage devices (lights, fans, appliances) — just change `ledPin` to match your relay's IN pin.
- **Toggle mode:** Add a single toggle button that flips state on each press instead of separate ON/OFF buttons.
- **Serial feedback:** Add `Serial.println("ON")` / `Serial.println("OFF")` inside each `if` block for logging via the Serial Monitor.
- **Status LED:** Add a second LED on another GPIO as a visual indicator of current state.
- **Debounce upgrade:** Replace the `delay(200)` with a proper millis-based debounce for more responsive feel.

---

## ⚠️ Notes

- 🔌 GPIO 2 is the **built-in LED** on most ESP32 DevKit V1 boards — so you can test this sketch with zero extra components right out of the box.
- 🔋 Don't drive high-current loads (motors, high-power LEDs) directly from GPIO pins — use a transistor or relay as a buffer.
- ⚡ For relay-based mains control: always use an **optocoupler relay module** and exercise appropriate electrical safety precautions.

---

🔧 Simple, reliable, and a solid foundation for any hardware control project!
