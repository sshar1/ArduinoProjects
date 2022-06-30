// Changes the frequency of an active buzzer using a potentiometer. A red LED scales its power with the volume and a green LED with digitally turn on once passing a threshold value

// DIRECTIONS

// Buzzer
// Connect one jumper cable to ground and another to pin 9 (analog)

// Potentiometer
// Connect one outside pin to a jumper cable connected to ground and the other outside pin to a jumper cable connected to a source of 5 volts
// Connect the middle pin to analog pin A0

// Red LED
// Connect the LED in series with ground, a 330 ohm resistor, and plug into pin 11 (analog)

// Green LED
// Connect the LED in series with ground, a 330 ohm resistor, and plug into pin 13 (digital)

const int BUZZER = 9;
const int RED = 11;
const int GREEN = 13;
const int POT = A0;

const int GREEN_THRESH = 220

int potVal;
int analogMag;

void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(POT, INPUT);
}

void loop() {
  potVal = analogRead(POT);
  
  analogMag = (255./1023.) * potVal;
  
  analogWrite(BUZZER, analogMag);
  analogWrite(RED, analogMag);

  if (analogMag > GREEN_THRESH) {
    digitalWrite(GREEN, HIGH);
  }
  else {
    digitalWrite(GREEN, LOW);
  }
}
