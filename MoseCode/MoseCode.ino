const int dotDelay = 200;   // base time unit for Morse
const int ledPin = 13;      

// Morse code for A–Z
const char* letters[] = { 
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",   
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."         
};

// Morse code for 0–9
const char* numbers[] = { 
  "-----", ".----", "..---", "...--", "....-", 
  ".....", "-....", "--...", "---..", "----."
};

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter text (A–Z, 0–9, space):");
}

void loop() {
  if (Serial.available() > 0) {
    char ch = Serial.read();

    if (ch >= 'a' && ch <= 'z') {
      flashSequence(letters[ch - 'a']);
    } 
    else if (ch >= 'A' && ch <= 'Z') {
      flashSequence(letters[ch - 'A']);
    } 
    else if (ch >= '0' && ch <= '9') {
      flashSequence(numbers[ch - '0']);
    } 
    else if (ch == ' ') {
      delay(dotDelay * 4); // gap between words
    }
    // Ignore newlines/carriage returns
  }
}

// Flashes a sequence (like ".-" for A)
void flashSequence(const char* sequence) {
  for (int i = 0; sequence[i] != '\0'; i++) {
    flashDotOrDash(sequence[i]);
  }
  delay(dotDelay * 3); // gap between letters
}

// Flashes a single dot or dash
void flashDotOrDash(char dotOrDash) {
  digitalWrite(ledPin, HIGH);

  if (dotOrDash == '.') {
    delay(dotDelay); // dot = 1 unit
  } 
  else { 
    delay(dotDelay * 3); // dash = 3 units
  }

  digitalWrite(ledPin, LOW);
  delay(dotDelay); // gap between parts of a letter
}
