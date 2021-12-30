#include <BLEMIDI_Transport.h>
#include <hardware/BLEMIDI_ArduinoBLE.h>

BLEMIDI_CREATE_INSTANCE("Glove", MIDI)

unsigned long t0 = millis();
bool isConnected = false;

void setup() {
  MIDI.begin();

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  BLEMIDI.setHandleConnected([]() {
    isConnected = true;
    digitalWrite(LED_BUILTIN, HIGH);
  });

  BLEMIDI.setHandleDisconnected([]() {
    isConnected = false;
    digitalWrite(LED_BUILTIN, LOW);
  });

  MIDI.setHandleNoteOn([](byte channel, byte note, byte velocity) {
    digitalWrite(LED_BUILTIN, LOW);
  });
  MIDI.setHandleNoteOff([](byte channel, byte note, byte velocity) {
    digitalWrite(LED_BUILTIN, HIGH);
  });
}

void loop() {
  MIDI.read();

  if (isConnected && (millis() - t0) > 1000) {
    t0 = millis();

    MIDI.sendNoteOn(60, 100, 1);
  }
}
