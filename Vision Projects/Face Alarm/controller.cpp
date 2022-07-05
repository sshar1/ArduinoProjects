#include <cvzone.h>

const int FIRST = 2;
const int SECOND = 4;
const int THIRD = 6;
const int FOURTH = 7;
const int FIFTH = 8;
const int SIXTH = 10;

const int BUZZER = 11;
const int POT = A0;

const int pins[6] = {FIRST, SECOND, THIRD, FOURTH, FIFTH, SIXTH};
const int PIN_SIZE = 6;

SerialData serialOut; 
SerialData serialIn(1, 1);

int valsRec[1];
int sendVals[3];

int potVal;

const int BUZZ_WAIT = 100;
const int FLASH_WAIT = 100;

// 200 before potentiometer
int alarmWait;

// 150 and 50 before potentiometer
int buzzHigh;
int buzzLow;

void setup() {

  for (int i = 0; i < PIN_SIZE; ++i) {
    pinMode(pins[i], OUTPUT);
  }
  
  pinMode(BUZZER, OUTPUT);
  pinMode(POT, INPUT);

  Serial.begin(9600);
  serialIn.begin();
  serialOut.begin();
}

void loop() {
  serialIn.Get(valsRec);
    
  if (valsRec[0] == 1) {
    alarm();
  }
  else {
    shutOff();
  }
}

void alarm() {
  potVal = analogRead(POT);

  alarmWait = 1500 - (potVal * (1500. / 1023.)) + 60;
  buzzHigh = potVal * (230. / 1023.) + 25;
  buzzLow = 0.3 * buzzHigh;

  sendVals[0] = alarmWait;
  sendVals[1] = buzzHigh;
  sendVals[2] = buzzLow;

  serialOut.Send(sendVals);

  // Turn on LED
  for (int i = 0; i < PIN_SIZE; ++i) {
    digitalWrite(pins[i], HIGH);
  }
  analogWrite(BUZZER, buzzHigh);

  delay(alarmWait);

  // Turn off LED
  for (int i = 0; i < PIN_SIZE; ++i) {
    digitalWrite(pins[i], LOW);
  }
  analogWrite(BUZZER, buzzLow);

  delay(alarmWait);
}

void shutOff() {
  for (int i = 0; i < PIN_SIZE; ++i) {
    digitalWrite(pins[i], LOW);
  }
  analogWrite(BUZZER, 0);
}


// FOR TESTING
//
//void buzz() {
//  analogWrite(BUZZER, 50);
//  delay(BUZZ_WAIT);
//  analogWrite(BUZZER, 150);
//  delay(BUZZ_WAIT);
//}
//
//void flash() {
//  for (int i = 0; i < PIN_SIZE; ++i) {
//    digitalWrite(pins[i], HIGH);
//  }
//
//  delay(FLASH_WAIT);
//
//  for (int i = 0; i < PIN_SIZE; ++i) {
//    digitalWrite(pins[i], LOW);
//  }
//
//  delay(FLASH_WAIT);
//}
