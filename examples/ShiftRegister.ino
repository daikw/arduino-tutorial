// control upto 8 leds by using 74HC595
//
// see also:
//   - https://omoroya.com/arduino-lesson20/
//   - https://synapse.kyoto/glossary/shift_register/page001.html
//
// datasheet:
//   [253DSN74HC595N](https://www.ti.com/lit/ds/symlink/sn74hc595.pdf?ts=1616216539681&ref_url=https%253A%252F%252Fwww.ti.com%252Fsitesearch%252Fdocs%252Funiversalsearch.tsp%253FsearchTerm%253DSN74HC595N)
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

byte leds = 0b00000000;  // 8 bits

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

    delay(200);  // tune this to alter the behaviour

    bitClear(leds, i);
  }
}
