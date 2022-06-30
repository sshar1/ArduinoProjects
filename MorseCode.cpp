// Converts inputs to morse code with blinks and sounds. A double blink represents the start of a new character. A four time blink represents the start of a new word. Input phrases into the serial monitor and it will print the morse code.

// DIRECTIONS

// LED
// Connect a red LED in pin 12 in series with a 220 ohm resistor connected to ground

// Active blinker
// Connect blinker to pin 8 and ground

const int RED = 12;
const int BUZZER = 8;

const int WORD_WAIT = 2000;
const int DOT_DURATION = 300;
const int DASH_DURATION = 800;
const int MORSE_CHAR_WAIT = 500;
const int ALPHA_CHAR_WAIT = 1000;

const int BLINK_DURATION = 100;

const int CHAR_BLINK_COUNT = 2;
const int WORD_BLINK_COUNT = 4;

String str;

const char letters[37] = { ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
const String morseLetters[37] = { " ", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",  "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"};

const int arrLen = 37;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  while (Serial.available() == 0) {
    
  }
  
  str = Serial.readString();
  
  Serial.println(strToMorse(str));

  playMorse(strToMorse(str));
}

void playMorse(String str) {
  for (int i = 0; i < str.length(); ++i) {
    if (str[i] == '.') {
      dot();
    }
    else if (str[i] == '-') {
      dash();
    }
    else if (str[i] == '/') {
      delay(ALPHA_CHAR_WAIT / 2);
      blink(CHAR_BLINK_COUNT);
      delay(ALPHA_CHAR_WAIT / 2);
    }
    else if (str[i] == ' ') {
      delay(WORD_WAIT / 2);
      blink(WORD_BLINK_COUNT);
      delay(WORD_WAIT / 2);
    }
  }
}

String strToMorse(String str) {
  String morse;

  for (int i = 0; i < str.length(); ++i) {
    morse += charToMorse(str[i]);

    if (str[i] != ' ' && (i < str.length() -1 && str[i+1] != ' ')) {
      morse += "/";
    }
  }

  return morse;
}

String charToMorse(char c) {
  for (int i = 0; i < arrLen; ++i) {
    if (tolower(c) == letters[i]) {
      return morseLetters[i];
    }
  }
  return "";
}

int len(char arr[]) {
  return sizeof(arr) / sizeof(arr[0]);
}

int len(String arr[]) {
  return sizeof(arr) / sizeof(arr[0]);
}

void dot() {
  digitalWrite(RED, HIGH);
  digitalWrite(BUZZER, HIGH);

  delay(DOT_DURATION);
  
  digitalWrite(RED, LOW);
  digitalWrite(BUZZER, LOW);

  delay(MORSE_CHAR_WAIT);
}

void dash() {
  digitalWrite(RED, HIGH);
  digitalWrite(BUZZER, HIGH);

  delay(DASH_DURATION);
  
  digitalWrite(RED, LOW);
  digitalWrite(BUZZER, LOW);

  delay(MORSE_CHAR_WAIT);
}

void blink(int times) {
  for (int i = 0; i < times; ++i) {
    digitalWrite(RED, HIGH);
    delay(BLINK_DURATION);
    digitalWrite(RED, LOW);
    delay(BLINK_DURATION);
  }
}
