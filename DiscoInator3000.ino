#include "pinout.h"
#include "display/display.h" // DrawTest(), DrawJazz(), DrawCool()
//#include "servo/servo.h" // SpinServo(), StopServo()
#include "engine/engine.h" // SpinServo(), StopServo()
#include "sound_sensor/sound_sensor.h" // zmienna clapMode zmienia stan po klasnieciu 
#include "OLED/oled.h"
#include "LED/LED.h"

#include "main_logic.h"

void setup() {
  Serial.begin(9600);
  setupDisplay();
  setupServo();
  setupOLED();
  setupLogic();
  setupLED();
}

void loop() {
  UpdateSoundSensor();
  
  UpdateParty();
  UpdateLED(partyMode, );
}
