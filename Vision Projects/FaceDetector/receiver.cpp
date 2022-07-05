#include <cvzone.h>

const int RED = 2;

SerialData serialData(1, 1);
int valsRec[1];

int potVal;

void setup() {
  pinMode(RED, OUTPUT);

  serialData.begin();
}

void loop() {
  serialData.Get(valsRec);
  digitalWrite(RED, valsRec[0]);
}
