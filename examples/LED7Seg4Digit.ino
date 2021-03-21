// control 4 digits 7 segmented led by using 74HC595

#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

const int dsPin = 2;     // (14) DS [SER]: Serial input
const int rclkPin = 3;   // (12) ST_CP [RCLK]: Storage Register Clock
const int srclkPin = 4;  // (11) SH_CP [SRCLK]: Shift Register Clock

const int digitPins[4] = {11, 10, 9, 8};

const byte letters[12] = {
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

const int DP = 10;
const int Null = 11;

const int SETUP_DELAY = 100;  // [ms]
const int FLUSH_DELAY = 2;    // [ms]
const int LOOP_DELAY = 2;     // [ms]

void setup() {
  pinMode(dsPin, OUTPUT);
  pinMode(rclkPin, OUTPUT);
  pinMode(srclkPin, OUTPUT);

  for (int i = 0; i < sizeof(digitPins); i++) {
    pinMode(digitPins[i], OUTPUT);
  }
  clear();

  delay(SETUP_DELAY);
}

void clear() {
  for (int i = 0; i < ARRAY_LENGTH(digitPins); i++) {
    digitalWrite(digitPins[i], HIGH);
  }
  srSend(Null);
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
  clear();
}

unsigned long time2millis(int hour, int minute) {
  return (60 * (unsigned long)hour + (unsigned long)minute) * 60 * 1000;
}

bool millis2time(unsigned long millis, int *hour, int *minute) {
  *hour = (millis / 1000 / 60 / 60) % 24;
  *minute = (millis / 1000 / 60) % 60;

  return true;
}

void displayHHMM(unsigned long offset) {
  int hour, minute;
  millis2time(offset, &hour, &minute);

  flush(0, hour / 10);
  flush(1, hour % 10);
  flush(2, minute / 10);
  flush(3, minute % 10);
}

const unsigned long startTime = time2millis(1, 5);
unsigned long currentTime;

void loop() {
  currentTime = startTime + millis();
  displayHHMM(currentTime);

  delay(LOOP_DELAY);
}
