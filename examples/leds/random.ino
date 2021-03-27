int leds[] = {6, 5, 4, 3, 2};

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

const int FLUSH_DELAY = 250;

void flush(int index) {
  digitalWrite(leds[index], HIGH);
  delay(FLUSH_DELAY);
  digitalWrite(leds[index], LOW);
}

void loop() {
  int rand = random(5);
  flush(rand);
}
