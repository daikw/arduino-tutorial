const int leds[8] = {2, 3, 4, 5, 6, 7, 8, 9};
const int seg = 8;  // number of the led segment

const bool numbers[10][8] = {
    {1, 0, 1, 1, 1, 1, 0, 1},  // 0
    {0, 0, 0, 0, 0, 1, 0, 1},  // 1
    {0, 1, 1, 1, 1, 1, 0, 0},  // 2
    {0, 1, 1, 0, 1, 1, 0, 1},  // 3
    {1, 1, 0, 0, 0, 1, 0, 1},  // 4
    {1, 1, 1, 0, 1, 0, 0, 1},  // 5
    {1, 1, 1, 1, 1, 0, 0, 1},  // 6
    {1, 0, 0, 0, 1, 1, 0, 1},  // 7
    {1, 1, 1, 1, 1, 1, 0, 1},  // 8
    {1, 1, 1, 0, 1, 1, 0, 1},  // 9
};

void setup() {
  for (int i = 0; i < seg; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void clear() {
  for (int i = 0; i < seg; i++) {
    digitalWrite(leds[i], LOW);
  }
}

void display(int num) {
  for (int i = 0; i < seg; i++) {
    digitalWrite(leds[i], numbers[num][i]);
  }
}

void loop() {
  for (int num = 0; num < 10; num++) {
    display(num);
    delay(1000);
    clear();
  }
}
