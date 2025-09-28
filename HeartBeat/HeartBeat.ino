int ledPin = 13;
int fastDelay = 150;   
int slowDelay = 600;   
int seperDelay = 600;   

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Fast blink (2 times)
  for (int i = 0; i < 2; i++) {
    digitalWrite(ledPin, HIGH);
    delay(fastDelay);
    digitalWrite(ledPin, LOW);
    delay(fastDelay);
  }
delay(seperDelay);
  // Slow blink (2 times)
  for (int i = 0; i < 2; i++) {
    digitalWrite(ledPin, HIGH);
    delay(slowDelay);
    digitalWrite(ledPin, LOW);
    delay(slowDelay);
  }
  delay(seperDelay);
}
