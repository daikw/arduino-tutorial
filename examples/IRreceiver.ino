// copied && modified from:
//   https://www.instructables.com/Simple-Arduino-and-HC-SR04-Example/

#define ledRed 10
#define ledGreen 11
#define echoPin 12
#define trigPin 13

void setup() {
  Serial.begin(9600);

  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;  // cm
  Serial.println(distance);

  if (distance < 4) {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, LOW);
  } else {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);
  }

  delay(50);
}
