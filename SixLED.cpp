// Plays a pattern with 6 LEDs and controls the wait using a potentiometer

// DIRECTIONS

// Connect 6 LEDs in series with a 220 or 330 ohm resistor and each connected to ground. 
// Connect each LED in the following PWM pins: 2, 4, 6, 7, 8, and 10

// Connect a potentiometer to a five volt power source, ground, and analog pin A0

const int FIRST = 2;
const int SECOND = 4;
const int THIRD = 6;
const int FOURTH = 7;
const int FIFTH = 8;
const int SIXTH = 10;

const int POT = A0;

int pins[6] = {FIRST, SECOND, THIRD, FOURTH, FIFTH, SIXTH};

const int PIN_SIZE = sizeof(pins) / sizeof(int);

int wait;

void setup() {
    for (int i = 0; i < PIN_SIZE; ++i) {
      pinMode(pins[i], OUTPUT);
    }

    pinMode(POT, INPUT);
}

void loop() {
  leftToRight(HIGH);
  rightToLeft(LOW);
  rightToLeft(HIGH);
  leftToRight(LOW);
}

void leftToRight(int input) {
  
  for (int i = 0; i < PIN_SIZE; ++i) {
    digitalWrite(pins[i], input);

    wait = (3000./1043.) * (analogRead(POT) + 20);
    delay(wait);
  }
}

void rightToLeft(int input) {
  
  for (int i = PIN_SIZE-1; i >= 0; --i) {
    digitalWrite(pins[i], input);

    wait = (3000./1043.) * (analogRead(POT) + 20);
    delay(wait);
  }
}
