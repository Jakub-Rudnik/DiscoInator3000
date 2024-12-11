#include "pinout.h"
#include "display/display.h" // DrawTest(), DrawJazz(), DrawCool()
//#include "servo/servo.h" // SpinServo(), StopServo()
#include "engine/engine.h" // SpinServo(), StopServo()
#include "sound_sensor/sound_sensor.h" // zmienna clapMode zmienia stan po klasnieciu 
#include "OLED/oled.h"

bool partyMode = 0;
int switchCount = 0;

void setup() {
  Serial.begin(9600);
  setupDisplay();
  setupServo();
  setupOLED();
  partyMode = !clapMode;
  pinMode(PINK_DIODE,OUTPUT);
}

void loop() {
  UpdateSoundSensor();
  UpdateParty();
}

void StartParty() {
  setupOLED();
  DisplayText("DISCO\nINATOR\n3000");
  digitalWrite(PINK_DIODE, HIGH); // zapala szereg rozowych diod
  SpinServo();
  DrawCool();
  
}

void StopParty() {
  digitalWrite(PINK_DIODE, LOW); // gasi szereg rozowych diod
  StopServo();
  DrawJazz();
  
}

void UpdateParty() {
  if (clapMode != partyMode) {
    //Serial.print("switch "); Serial.println(switchCount++);
    partyMode = clapMode;
    if (partyMode) {
      StartParty();
    }
    else {
      StopParty();
    }
  }
}