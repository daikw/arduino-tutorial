const int led = 2;
const int THRESHOLD = 200;

int piState;
int lastPIState = LOW;  // CLOSED ~= LOW, OPEN ~= HIGH
int ledState = HIGH;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;  // ms

void setup() {
  pinMode(A0, INPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(A0);
  bool readingDigital = reading > THRESHOLD;

  if (readingDigital != lastPIState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (readingDigital != piState) {
      piState = readingDigital;

      if (piState == HIGH) {
        ledState = !ledState;
      }
    }
  }

  digitalWrite(led, ledState);
  lastPIState = readingDigital;
}
