// Uses two buttons: one to raise the brighness of an LED, and another to lower its brightness

// DIRECTIONS

// BUTTON (do this twice, for each button)
// Connect a jumper cable to 5 volts (in the positive power rail) in series with a 10k ohm resistor, and a button (you may use another jumper cable to have the button in its own column)
// Connect a jumper from the resistor column to pin 12
// Connect the button to ground

// LED
// Connect a red LED in pin 9 in series with a 330 ohm resistor and ground

// Note: You should connect all ground pins to the negative power rail and connect the rail to ground on the arduino

const int RED = 9;
const int HIGH_BUTTON = 12;
const int LOW_BUTTON = 7;

const int B_UNPRESSED = 1;
const int B_PRESSED = 0;

int hButtonStatus;
int lButtonStatus;

// From 0-255
int redPower = 0;
const int RED_MAX = 255;
const int RED_MIN = 0;

const int LOOP_WAIT = 50

void setup() {
  pinMode(HIGH_BUTTON, INPUT);
  pinMode(LOW_BUTTON, INPUT);
  pinMode(RED, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  hButtonStatus = digitalRead(HIGH_BUTTON);
  lButtonStatus = digitalRead(LOW_BUTTON);
  
  Serial.println(hButtonStatus + "    " + lButtonStatus);

  if (hButtonStatus == B_PRESSED && redPower < RED_MAX) {
    redPower += 5;
  }

  if (lButtonStatus == B_PRESSED && redPower > RED_MIN) {
    redPower -= 5;
  }

  analogWrite(RED, redPower);

  delay(LOOP_WAIT);
}
