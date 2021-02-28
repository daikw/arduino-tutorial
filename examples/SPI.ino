// see also...
//
// arduino:
//   https://shirogoma.mobi/%E9%9B%BB%E5%AD%90%E5%B7%A5%E4%BD%9C/raspi3/post-1390
// raspi:
//   https://www.raspberrypi.org/documentation/hardware/raspberrypi/spi/README.md
//   https://tomosoft.jp/design/?p=5428
//   https://tomosoft.jp/design/?p=5252
//   https://qiita.com/7of9/items/49d7a462732cbd41cb82

#include <SPI.h>

void setup(void) {
  pinMode(MISO, OUTPUT);
  Serial.begin(9600);

  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  SPCR |= _BV(SPE);
  SPI.attachInterrupt();
}

// spi interrupt
ISR(SPI_STC_vect) {
  byte cc = SPDR;
  cc++;
  SPDR = cc;
  Serial.println(cc);
}

void loop(void) {}
