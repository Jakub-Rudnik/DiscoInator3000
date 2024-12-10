#include "pinout.h"
#include "display/display.h" // DrawTest(), DrawJazz(), DrawCool()
#include "servo/servo.h" // SpinServo(), StopServo()
#include "sound_sensor/sound_sensor.h" // zmienna clapMode zmienia stan po klasnieciu 

void setup() {
  Serial.begin(9600);
  setupDisplay();
  DrawTest();
  
}

void loop() {
  loopSoundSensor();
  Serial.println(clapMode);
}
