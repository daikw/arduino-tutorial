#include <MsTimer2.h>
#define led 2

void flash() {
  static boolean output = HIGH;

  digitalWrite(led, output);
  output = !output;
}

void setup() {
  pinMode(led, OUTPUT);

  MsTimer2::set(500, flash);
  MsTimer2::start();
}

void loop() {}
