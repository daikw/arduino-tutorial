const PROGMEM int X_PIN = A1;
const PROGMEM int Y_PIN = A0;

int xValue = 0;
int yValue = 0;

void setup() { Serial.begin(9600); }

void loop() {
  xValue = analogRead(X_PIN);
  yValue = analogRead(Y_PIN);
  Serial.print(xValue);
  Serial.print(",");
  Serial.print(yValue);
  Serial.println("");
  delay(50);
}
