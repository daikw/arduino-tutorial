int leds[] = {6, 5, 4, 3, 2};

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

const int FLUSH_DELAY = 250;

void loop() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(leds[i], HIGH);
    delay(FLUSH_DELAY);
    digitalWrite(leds[i], LOW);
  }

  for (int i = 4; i >= 0; i--) {
    digitalWrite(leds[i], HIGH);
    delay(FLUSH_DELAY);
    digitalWrite(leds[i], LOW);
  }

  digitalWrite(leds[0], HIGH);
  delay(FLUSH_DELAY);
}
