const int ledPin = 13;
const int pushbuttonPin = 3;

// Time in milliseconds
const int dottime = 200;    // Duration of a dot
const int dashtime = 2 * dottime;  // Duration of a dash
const int lettertime = 4 * dottime;  // Space for letters
const int wordtime = 6 * dottime;  // Space for words

void dot() {
  digitalWrite(ledPin, HIGH);
  delay(dottime);
  digitalWrite(ledPin, LOW);
  delay(dottime);
}

void dash() {
  digitalWrite(ledPin, HIGH);
  delay(dashtime);
  digitalWrite(ledPin, LOW);
  delay(dottime);
}

void blinkLetter(char abc) {
  switch (abc) {
    case 'T':
      dash();
      break;
    case 'A':
      dot(); dash();
      break;
    case 'N':
      dash(); dot();
      break;
    case 'Y':
      dash(); dot(); dash(); dash();
      break;
    case 'A':
      dot(); dash();
      break;
    
    default:
      break;
  }
}

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pushbuttonPin, INPUT_PULLUP);
  digitalWrite(ledPin, LOW);
}

void loop() {
  static bool pushbuttonState = HIGH;
  static bool previousButtonState = HIGH;
  static bool nameBlinking = false;

  pushbuttonState = digitalRead(pushbuttonPin);

  if (pushbuttonState == LOW && previousButtonState == HIGH) {
    nameBlinking = !nameBlinking;
    if (nameBlinking) {
      // Starts blinking the name "TANYA"
      const char name[] = "TANYA";
      for (int i = 0; i < sizeof(name) - 1; i++) {
        blinkLetter(name[i]);
        delay(lettertime);
      }
      delay(wordtime);
    }
  }

  previousButtonState = pushbuttonState;
}