#pragma once

int pink_interval = 250;
int orange_interval = 200;
int last_orange_timestamp = 0;
int last_orange_timestamp = 0;

void setupLED() {
  pinMode(PINK_DIODE,OUTPUT);
  pinMode(ORANGE_DIODE,OUTPUT);
}

inline void PinkOn() {
  digitalWrite(PINK_DIODE, HIGH); 
}

inline void OrangeOn() {
  digitalWrite(ORANGE_DIODE, HIGH);
}

inline void PinkOff() {
  digitalWrite(PINK_DIODE, LOW); 
}

inline void OrangeOff() {
  digitalWrite(ORANGE_DIODE, LOW);
}

void UpdateLED(bool partyMode, float interval_modifier) { // 0 < interval_modifier < 1
  if (partyMode) {
    int pink_interval_tmp = pink_interval * interval_modifier;
    int orange_interval_tmp = orange_interval * interval_modifier;
  }
  else {
    PinkOff(); OrangeOff();
  }
}



