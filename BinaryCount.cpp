// This will represent binary numbers from 0 to 15 using 4 LEDs where off represents 0 and on represents 1

// DIRECTIONS

// Pins
// Connect 4 red LEDs to PWMs 4, 7, 11, and 13

// Connect each LED in series with a 220 ohm resistor and a jumper cable leading to the negative power rail
// Connect the negative power rail to ground

const int FIRST = 4;
const int SECOND = 7;
const int THIRD = 11;
const int FOURTH = 13;

int pins[4] = {FIRST, SECOND, THIRD, FOURTH};

void setup() {
  pinMode(FIRST, OUTPUT);
  pinMode(SECOND, OUTPUT);
  pinMode(THIRD, OUTPUT);
  pinMode(FOURTH, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i <= 15; ++i) {
    lightPins(i);
    delay(1000);
  }
}

int toBinary(int decimal) {
  int binary = 0, remainder, product = 1;
  
  while (decimal != 0) {
    remainder = decimal % 2;
    binary = binary + (remainder * product);
    decimal = decimal / 2;
    product *= 10;
  }

  return binary;
}

// num is NOT in binary
void lightPins(int num) {
  int binary = toBinary(num);

  String str = toString(binary);

  for (int i = 0; i < str.length(); ++i) {
    if (str[i] == '0') {
      digitalWrite(pins[i], LOW);
    }
    else {
      digitalWrite(pins[i], HIGH);
    }
  }
}

int len(int arr[]) {
  return sizeof(arr) / sizeof(arr[0]);
}

String toString(int num) {
  String str;
  
  while (num != 0) {
    str = num % 10 + str;
    num /= 10;
  }

  for (int i = 0; i < 4; ++i) {
    if (str.length() == 4) {
      break;
    }

    str = "0" + str;
  }

  return str;
}
