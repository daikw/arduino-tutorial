// control 4 digits 7 segmented led by using 74HC595

int dsPin = 2;     // (14) DS [SER]: Serial input
int rclkPin = 3;   // (12) ST_CP [RCLK]: Storage Register Clock
int srclkPin = 4;  // (11) SH_CP [SRCLK]: Shift Register Clock

int digitPins[4] = {11, 10, 9, 8};

byte letters[12] = {
    0b00111111,  // 0
    0b00000110,  // 1
    0b01011011,  // 2
    0b01001111,  // 3
    0b01100110,  // 4
    0b01101101,  // 5
    0b01111101,  // 6
    0b00100111,  // 7
    0b01111111,  // 8
    0b01101111,  // 9
    0b10000000,  // D.P.
    0b00000000,  // ''
};
int DP = 10;
int Null = 11;

int SETUP_DELAY = 100;  // [ms]
int FLUSH_DELAY = 1;    // [ms]
int LOOP_DELAY = 1;     // [ms]

void setup() {
  pinMode(dsPin, OUTPUT);
  pinMode(rclkPin, OUTPUT);
  pinMode(srclkPin, OUTPUT);

  for (int i = 0; i < sizeof(digitPins); i++) {
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], HIGH);
  }
  srSend(Null);
  delay(SETUP_DELAY);
}

void clear() {
  for (int i = 0; i < sizeof(digitPins); i++) {
    digitalWrite(digitPins[i], HIGH);
  }
}

void srSend(int number) {
  digitalWrite(rclkPin, LOW);
  shiftOut(dsPin, srclkPin, LSBFIRST, letters[number]);
  digitalWrite(rclkPin, HIGH);
}

void flush(int digit, int number) {
  digitalWrite(digitPins[digit], LOW);
  srSend(number);
  delay(FLUSH_DELAY);
  srSend(Null);
  clear();
}

void loop() {
  for (int i = 0; i < sizeof(digitPins); i++) {
    flush(i, i);
  }
  delay(LOOP_DELAY);
}
