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

void UpdateLED(bool partyMode) {
  if (!partyMode) {
    PinkOff(); OrangeOff();
  }
  else {
    
  }
}



