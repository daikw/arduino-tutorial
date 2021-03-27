int led = 2;

void setup() { pinMode(led, OUTPUT); }

const int FLUSH_DELAY = 250;

void loop() {
  for (int i = 0; i < 10; i++) {
    analogWrite() flush(rand);
  }
}
