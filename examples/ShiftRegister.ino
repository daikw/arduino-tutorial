// control upto 8 leds by using 74HC595
//
// see also:
//   - https://omoroya.com/arduino-lesson20/
//   - https://synapse.kyoto/glossary/shift_register/page001.html
//
// words:
//   - D-flipflop ... https://synapse.kyoto/glossary/dff/page001.html
//   - multiplexer
//   - cascade
//   - parallel <-> serial converter
//   - noise-filter
//   - delay-timer

int dsPin = 9;      // (14) DS [SER] on 74HC595
int rclkPin = 11;   // (12) ST_CP [RCLK] on 74HC595
int srclkPin = 12;  // (11)  SH_CP [SRCLK] on 74HC595

byte leds = 0;

void setup() {
  pinMode(dsPin, OUTPUT);
  pinMode(rclkPin, OUTPUT);
  pinMode(srclkPin, OUTPUT);
  //   Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 8; i++) {
    bitSet(leds, i);
    // Serial.println(leds);

    digitalWrite(rclkPin, LOW);
    shiftOut(dsPin, srclkPin, LSBFIRST, leds);
    digitalWrite(rclkPin, HIGH);

    delay(200);

    bitClear(leds, i);
  }
}
