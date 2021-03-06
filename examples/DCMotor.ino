#define EN12 5
#define D1A 4
#define D2A 3

void setup() {
  pinMode(EN12, OUTPUT);
  pinMode(D1A, OUTPUT);
  pinMode(D2A, OUTPUT);
  Serial.begin(9600);
}

void ctrl(byte speed, bool d1a, bool d2a) {
  analogWrite(EN12, speed);
  digitalWrite(D1A, d1a);
  digitalWrite(D2A, d2a);
}

void loop() {
  ctrl(255, HIGH, LOW);
  delay(2000);
  ctrl(255, LOW, HIGH);
  delay(2000);
  ctrl(100, HIGH, LOW);
  delay(2000);
}
