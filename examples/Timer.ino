#include <MsTimer2.h>

#define button 2
#define led 3

void flash() {
  static boolean output = HIGH;

  digitalWrite(led, output);
  output = !output;
}

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);

  MsTimer2::set(500, flash);
  MsTimer2::start();
}

void toggleTimer() {
  static bool state = true;

  state = !state;
  if (state) {
    MsTimer2::stop();
  } else {
    MsTimer2::start();
  }
}

void loop() {
  static bool lastButtonState = LOW;
  static bool buttonState = LOW;
  static unsigned int lastDebounceTime = 0;
  static unsigned int debounceDelay = 50;

  bool reading = digitalRead(button);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  bool waited = (millis() - lastDebounceTime) < debounceDelay;
  bool alternate = (reading != buttonState);

  if (waited && alternate) {
    buttonState = reading;
    if (buttonState) toggleTimer();
  }

  lastButtonState = buttonState;
}
