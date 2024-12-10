#include "pinout.h"
#include "display/display.h"
#include "servo/servo.h"

void setup() {
  setupDisplay();
  DrawBooba();
  
  setupServo();
  SpinServo();
  delay(1000);
  StopServo();
}

void loop() {
  
}
