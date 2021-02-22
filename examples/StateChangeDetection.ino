const int ledPin = 13;
const int buttonPin = 2;

int counter = 0;
int buttonState = 0;
int lastButtonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (lastButtonState == LOW && buttonState == HIGH) {
    Serial.println("pushed");
    counter++;
  }
  lastButtonState = buttonState;
  delay(50);

  if (counter % 4 == 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
