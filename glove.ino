#include <Arduino_APDS9960.h>
#include <BLEMIDI_Transport.h>
#include <hardware/BLEMIDI_ArduinoBLE.h>

BLEMIDI_CREATE_INSTANCE("Glove", MIDI)

unsigned long t0 = millis();
bool isBluetoothConnected = false;

void setup() {
  MIDI.begin();
  int proximityInitialized = APDS.begin();

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  BLEMIDI.setHandleConnected([]() {
    isBluetoothConnected = true;
    digitalWrite(LED_BUILTIN, HIGH);
  });

  BLEMIDI.setHandleDisconnected([]() {
    isBluetoothConnected = false;
    digitalWrite(LED_BUILTIN, LOW);
  });
}

void loop() {
  const int SENSOR_INTERVAL = 1000;
  MIDI.read();

  if (isBluetoothConnected && APDS.proximityAvailable() &&
      (millis() - t0) > SENSOR_INTERVAL) {
    t0 = millis();

    // `proximity` ranges from 0 (closest) to 255 (farthest)
    int proximity = APDS.readProximity();

    MIDI.sendControlChange(1, proximity / 2, 1);
  }
}
