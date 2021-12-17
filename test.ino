void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

// Blink LED at 120 bpm (2 beats/second)
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
  digitalWrite(LED_BUILTIN, LOW);
  delay(250);
}
