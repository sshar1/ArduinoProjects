// Turns on green LED when lights are turned on and turns on red LED when lights are turned off in the room. Uses a photoresistor to measure light.

// DIRECTIONS
// Connect photoresistor in series with 5 volt source, 10k ohm resistor, and ground
// Connect a read pin in the same column as the photoresistor and the 10k resistor and connect it to pin A0
// Connect red LED in series with 330 ohm resistor and ground
// Connect green LED in series with 330 ohm resistor and ground

const int LIGHT_READER = A0;
const int RED = 2;
const int GREEN = 8;

const int LIGHT_THRESH = 920;

int lightVal;

void setup() {
  pinMode(LIGHT_READER, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  lightVal = analogRead(LIGHT_READER);

  //light on
  if (lightVal > LIGHT_THRESH) {
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
  }
  //light off
  else {
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
  }

  Serial.println(lightVal);

  delay(250);
}
