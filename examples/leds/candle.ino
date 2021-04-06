int led = A0;

void setup() { pinMode(led, OUTPUT); }

const int DELAY = 20;

void loop() {
  for (int i = 0; i < 255; i++) {
    analogWrite(led, i);
    delay(DELAY);
  }
  for (int i = 0; i < 255; i++) {
    analogWrite(led, 255 - i);
    delay(DELAY);
  }
}
