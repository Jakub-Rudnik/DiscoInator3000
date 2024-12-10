#include "pinout.h"
#include "display/display.h"
#include "servo/servo.h"
#include "sound_sensor/sound_sensor.h"
//#include "engine/engine.h"

void setup() {
  Serial.begin(9600);
  setupDisplay();
  DrawTest();

  
}

void loop() {

}
