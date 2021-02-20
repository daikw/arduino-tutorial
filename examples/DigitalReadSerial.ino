const int pushButtonPin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(pushButtonPin, INPUT);
}

void loop() {
  int buttonState = digitalRead(pushButtonPin);
  Serial.println(buttonState);
  delay(100);
}
