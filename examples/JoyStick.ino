const PROGMEM int X_PIN = A1;
const PROGMEM int Y_PIN = A0;
const PROGMEM int BTN_PIN = 2;

int xValue = 0;
int yValue = 0;

int buttonState = LOW;

void setup() {
  pinMode(BTN_PIN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(BTN_PIN);

  xValue = analogRead(X_PIN);
  yValue = analogRead(Y_PIN);
  Serial.print(xValue * buttonState);
  Serial.print(",");
  Serial.print(yValue * buttonState);
  Serial.println("");

  delay(50);
}
