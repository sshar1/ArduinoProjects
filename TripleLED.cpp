// This will produce a cool pattern with 3 leds!

// DIRECTIONS

// Pins
// Connect red LED to PWM 13
// Connect green LED to PWM 11
// Connect yellow LED to PWM 9

// Connect each LED in series with a 220 ohm resistor and a jumper cable leading to the negative power rail
// Connect the negative power rail to ground


const int YELLOW_PIN = 9;
const int GREEN_PIN = 11;
const int RED_PIN = 13;

int pins[3] = {RED_PIN, GREEN_PIN, YELLOW_PIN};

const int PIN_SIZE = sizeof(pins) / sizeof(int);

const int WAIT = 150;

void setup() {
    pinMode(YELLOW_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(RED_PIN, OUTPUT);

}

void loop() {
  leftToRight(HIGH, WAIT);
  rightToLeft(LOW, WAIT);
  rightToLeft(HIGH, WAIT);
  leftToRight(LOW, WAIT);
}

void leftToRight(int input, int waitTime) {
  
  for (int i = 0; i < PIN_SIZE; ++i) {
    digitalWrite(pins[i], input);
    delay(waitTime);
  }
}

void rightToLeft(int input, int waitTime) {
  
  for (int i = PIN_SIZE-1; i >= 0; --i) {
    digitalWrite(pins[i], input);
    delay(waitTime);
  }
}
