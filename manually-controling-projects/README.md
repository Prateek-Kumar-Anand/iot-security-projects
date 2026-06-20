[⬅ Back to main repository](../README.md)

# 🔘 Manual & Sensor-Based Control Projects — ESP32 DevKit V1

Simple, no-frills projects that put **physical hardware directly in control** — buttons, sensors, and GPIO pins doing the work with no Wi-Fi, no browser, and no cloud needed. Perfect for getting started with GPIO and understanding the basics before layering in networking or displays. 🛠️

---

## 📦 What's Inside

| Project | File | Description |
|---|---|---|
| 💡 **Button Light Control** | `ESP32_Button_Light_Control.ino` | Two push buttons (ON / OFF) control an LED or relay output in real time. |
| 🚨 **PIR Motion Detector** | `ESP32_PIR_Motion_Detector.ino` | PIR sensor detects motion and triggers a buzzer alarm. |
| 🦾 **Servo Button Control** | `ESP32_Servo_Button_Control.ino` | Two buttons step a servo arm up/down by 5° per press. |

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

### 🚨 PIR Motion Detector

| Component | ESP32 Pin |
|---|---|
| PIR sensor OUT | GPIO 14 |
| PIR sensor VCC | 5V |
| PIR sensor GND | GND |
| Buzzer signal | GPIO 27 |

**Wiring steps:**

1. **PIR sensor:** VCC → 5V, GND → GND, OUT → GPIO 14.
2. **Buzzer:** If it's an **active buzzer** (built-in oscillator, only 2 pins), connect + to GPIO 27 and − to GND directly. If it's a **passive buzzer**, you'll need `tone()`/PWM instead of a plain `digitalWrite()` — the current code assumes an active buzzer.

```
PIR VCC ── 5V          PIR GND ── GND
PIR OUT ── GPIO 14

GPIO 27 ──[Buzzer +]   [Buzzer -]── GND
```

---

### 🦾 Servo Button Control

| Component | ESP32 Pin |
|---|---|
| Servo signal (orange/yellow) | GPIO 13 |
| Increase angle button | GPIO 26 |
| Decrease angle button | GPIO 27 |

**Wiring steps:**

1. **Servo:** Signal wire → GPIO 13. Power the servo from **5V**, not the ESP32's 3.3V rail — small servos can draw more current than the onboard regulator likes. Share GND between the servo's supply and the ESP32.
2. **Buttons:** Same as above — each button between its GPIO pin and GND, using `INPUT_PULLUP`.

```
GPIO 13 ── Servo signal
5V      ── Servo VCC (external 5V recommended for anything beyond a micro servo)
GND     ── Servo GND (common ground with ESP32)

GPIO 26 ──[BUTTON_INCREASE]── GND
GPIO 27 ──[BUTTON_DECREASE]── GND
```

> ⚠️ Note: `BUZZER_PIN` in the PIR project and `buttonDecrease` in the Servo project both use **GPIO 27** — that's fine since they're separate sketches, but don't wire both circuits onto the same board at once without changing one of the pins.

---

## 📚 Required Libraries

| Project | Library | Notes |
|---|---|---|
| Button Light Control | — | Built-in Arduino/ESP32 core functions only (`pinMode`, `digitalWrite`, `digitalRead`). |
| PIR Motion Detector | — | Built-in core functions only. |
| Servo Button Control | [`ESP32Servo`](https://github.com/madhephaestus/ESP32Servo) | Install via **Library Manager** (`Ctrl+Shift+I`) — search "ESP32Servo". The classic Arduino `Servo.h` is **not** compatible with ESP32; you need this dedicated library. |

---

## ▶️ Uploading the Code

1. Open the desired `.ino` file in **Arduino IDE** or **Arduino Cloud**.
2. Select **ESP32 Dev Module** as the board.
3. For the Servo project, install `ESP32Servo` first (see table above).
4. Connect your ESP32 via USB.
5. Click **Upload** (`Ctrl+U`).
6. Test the wiring as described in each project's section below.

---

## 🔍 How It Works

### 💡 Button Light Control

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

### 🚨 PIR Motion Detector

```cpp
#define PIR_PIN 14
#define BUZZER_PIN 27
```

The `loop()` reads `PIR_PIN` on every pass. When the sensor outputs `HIGH` (motion detected):

- `"Person Detected!"` is printed to Serial
- The buzzer is turned on for **1 second** (`delay(1000)`), then switched off

Because the 1-second buzzer beep uses a blocking `delay()`, the sensor isn't re-checked during that second — fine for a simple alarm, but worth knowing if you plan to extend this into something more responsive (e.g. logging multiple rapid triggers).

> 💡 **PIR sensors need a warm-up period** — most modules take **30–60 seconds** after power-on to calibrate to the room's ambient infrared levels. Expect false triggers during that window; this is normal sensor behavior, not a code bug.

---

### 🦾 Servo Button Control

```cpp
#include <ESP32Servo.h>
Servo myServo;

const int servoPin = 13;
const int buttonIncrease = 26;
const int buttonDecrease = 27;

int servoAngle = 90;  // starts centered
```

Both buttons use `INPUT_PULLUP`. On each press:

- **Increase button** → `servoAngle += 5`, capped at `180`
- **Decrease button** → `servoAngle -= 5`, capped at `0`

Each step writes the new angle to the servo and waits `200ms` before reading the buttons again (simple debounce). The servo starts centered at 90° on boot.

---

## 💡 Project Ideas / Extensions

- **Relay control:** Replace the LED with a relay module to switch mains-voltage devices (lights, fans, appliances) — just change `ledPin` to match your relay's IN pin.
- **Toggle mode:** Add a single toggle button that flips state on each press instead of separate ON/OFF buttons.
- **Serial feedback:** Add `Serial.println("ON")` / `Serial.println("OFF")` inside each `if` block for logging via the Serial Monitor.
- **Status LED:** Add a second LED on another GPIO as a visual indicator of current state.
- **Debounce upgrade:** Replace the `delay(200)` calls (button light, servo) with a proper millis-based debounce for a more responsive feel without blocking.
- **PIR alarm log:** Timestamp each motion event (e.g. with `millis()`) and print a running count to Serial instead of just beeping.
- **PIR + light combo:** Pair the PIR sensor with the Button Light Control LED/relay to make a motion-activated light instead of (or in addition to) a buzzer.
- **Servo sweep mode:** Add a third "auto sweep" button that smoothly sweeps the servo 0→180→0 instead of stepping in 5° increments.

---

## ⚠️ Notes

- 🔌 GPIO 2 is the **built-in LED** on most ESP32 DevKit V1 boards — so you can test the Button Light Control sketch with zero extra components right out of the box.
- 🔋 Don't drive high-current loads (motors, high-power LEDs, big servos) directly from GPIO pins — use a transistor, relay, or external power supply as appropriate.
- ⚡ For relay-based mains control: always use an **optocoupler relay module** and exercise appropriate electrical safety precautions.
- 🚨 PIR sensitivity and trigger-hold-time are usually adjustable via two small potentiometers on the sensor module itself — tune these if you're getting too many/too few triggers.
- 🦾 Larger servos can briefly draw enough current to brown out the ESP32 if powered from the same 5V/3.3V rail — use a separate supply for anything bigger than a micro servo (e.g. SG90).

---

🔧 Simple, reliable, and a solid foundation for any hardware control project!
