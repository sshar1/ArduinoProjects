#include <cvzone.h>

const int RED = 2;
const int POT = A0;

SerialData serialData;
int sendVals[2];

int potVal;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(POT, INPUT);

  serialData.begin();
}

void loop() {

  potVal = analogRead(POT);
  sendVals[0] = potVal;
  serialData.Send(sendVals);

  
