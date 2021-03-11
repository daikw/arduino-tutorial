bool numbers[10][8] = {
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
  for (int led = 2; led <= 9; led++) {
    pinMode(led, OUTPUT);
  }
}

void clear() {
  for (int led = 2; led <= 9; led++) {
    digitalWrite(led, LOW);
  }
}

void display(int num) {
  for (int led = 2; led <= 9; led++) {
    digitalWrite(led, numbers[num][led - 2]);
  }
}

void loop() {
  for (int num = 0; num < 10; num++) {
    display(num);
    delay(1000);
    clear();
  }
}
