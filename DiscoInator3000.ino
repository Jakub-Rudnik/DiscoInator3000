#include "pinout.h"
#include "display/display.h"
#include "servo/servo.h"

void setup() {
  setupDisplay();
  DrawCool();

  setupServo();
  SpinServo();
  delay(1000);
  StopServo();
}

void loop() {
  
}
