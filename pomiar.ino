#define SOUND_CONST 58.00
#define MEASUREMENT_COUNT 5

float checkDistance() {
  unsigned long time = 0;
  for (int i = 0; i < MEASUREMENT_COUNT; i++) {
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);
    time += pulseIn(ECHO, HIGH);
    delay(50);
  }
  return time / SOUND_CONST / MEASUREMENT_COUNT;
}
