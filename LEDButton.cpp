// Turns on an LED with the push of a button

// DIRECTIONS

// BUTTON
// Connect a jumper cable to 5 volts in series with a 10k ohm resistor, and a button (you may use another jumper cable to have the button on its own column)
// Connect a jumper from the resistor column to pin 12
// Connect the button to ground

// LED
// Connect a red LED in series with a 330 ohm resistor and ground

const int RED = 8;
const int BUTTON = 12;

const int B_UNPRESSED = 1;
const int B_PRESSED = 0;

int buttonVal;
int prevVal = 1;

boolean ledOn = false;

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(RED, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  buttonVal = digitalRead(BUTTON);

  Serial.println(buttonVal);

  if (buttonVal == B_PRESSED && prevVal == B_UNPRESSED) {
    if (ledOn) {
      digitalWrite(RED, LOW);
    }
    else {
      digitalWrite(RED, HIGH);
    }
    
    ledOn = !ledOn;
  }

  prevVal = digitalRead(BUTTON);

  delay(100);
}
