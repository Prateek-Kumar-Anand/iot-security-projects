const int ledPin = 2;      // LED or Relay
const int onButton = 18;   // ON Button
const int offButton = 19;  // OFF Button

void setup() {
  pinMode(ledPin, OUTPUT);

  pinMode(onButton, INPUT_PULLUP);
  pinMode(offButton, INPUT_PULLUP);

  digitalWrite(ledPin, LOW);
}

void loop() {

  if (digitalRead(onButton) == LOW) {
    digitalWrite(ledPin, HIGH);
    delay(200);
  }

  if (digitalRead(offButton) == LOW) {
    digitalWrite(ledPin, LOW);
    delay(200);
  }
}
