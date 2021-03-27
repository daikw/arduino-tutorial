int leds[] = {6, 5, 4, 3, 2};

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

bool evenState = HIGH;
void toggleEven() {
  evenState = !evenState;
  digitalWrite(leds[0], evenState);
  digitalWrite(leds[2], evenState);
  digitalWrite(leds[4], evenState);
}

bool oddState = LOW;
void toggleOdd() {
  oddState = !oddState;
  digitalWrite(leds[1], oddState);
  digitalWrite(leds[3], oddState);
}

void loop() {
  toggleEven();
  toggleOdd();
  delay(1000);
}
