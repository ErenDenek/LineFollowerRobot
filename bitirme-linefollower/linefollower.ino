#include "config.h"
#include "linefollower.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);


  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, OUTPUT);

  for (int i = 0; i < 6; i++) {
    pinMode(analogPin[i], INPUT);
    minVal[i] = 1023; maxVal[i] = 0;
  }

  calibration(3000);

}

void loop() {

  motorControl();

}
