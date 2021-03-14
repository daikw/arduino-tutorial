void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(A0);
  Serial.println(reading);
  delay(500);
}

/*
## info
- DC: 5 V
- Photointerrupter: CNZ1023(ON1023)
  https://akizukidenshi.com/catalog/g/gP-09668/

## resistors
- PULLDOWN ... pull
- CURRENT_CONTROLING ... cc

## states
- open: led --> photoresistor
- close: led -|-> photoresistor

## result
| pull [ohm] | cc [ohm] | state | reading |
| --- | --- | --- |
| 10k | 100 | open | 103 ~ 110 |
| 10k | 100 | close | 10 ~ 20 |
| 10k | 220 | open | 52 ~ 54 |
| 10k | 220 | close | 4 ~ 7 |
| 2k | 100 | open | 24 ~ 25 |
| 2k | 100 | close | 4 ~ 5 |
| 2k | 220 | open | 15 ~ 15 |
| 2k | 220 | close | 3 ~ 7 |
*/