// copied && modified from:
//   https://www.instructables.com/Simple-Arduino-and-HC-SR04-Example/

#define button 2
#define ledR 3
#define ledG 5
#define ledB 6

void setup() {
  Serial.begin(9600);

  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(button, INPUT);
}

int ledState = HIGH;
int color = 0;
int buttonState;
int lastButtonState = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;  // ms

void loop() {
  int reading = digitalRead(button);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        ledState = !ledState;
        color = (color + 1) % 3;
      }
    }
  }

  digitalWrite(ledR, LOW);
  digitalWrite(ledG, LOW);
  digitalWrite(ledB, LOW);
  switch (color) {
    case 0:
      digitalWrite(ledR, ledState);
      break;
    case 1:
      digitalWrite(ledG, ledState);
      break;
    case 2:
      digitalWrite(ledB, ledState);
      break;
    default:
      break;
  }

  lastButtonState = reading;
}
