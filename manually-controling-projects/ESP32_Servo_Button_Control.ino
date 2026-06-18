#include <ESP32Servo.h>

Servo myServo;

const int servoPin = 13;
const int buttonIncrease = 26;
const int buttonDecrease = 27;

int servoAngle = 90;

void setup() {
  pinMode(buttonIncrease, INPUT_PULLUP);
  pinMode(buttonDecrease, INPUT_PULLUP);

  myServo.attach(servoPin);
  myServo.write(servoAngle);
}

void loop() {
  if (digitalRead(buttonIncrease) == LOW) {
    servoAngle += 5;
    if (servoAngle > 180) servoAngle = 180;
    myServo.write(servoAngle);
    delay(200);
  }

  if (digitalRead(buttonDecrease) == LOW) {
    servoAngle -= 5;
    if (servoAngle < 0) servoAngle = 0;
    myServo.write(servoAngle);
    delay(200);
  }
}
