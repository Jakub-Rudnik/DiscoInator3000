uint16_t dofenschmirtsMelody[] = {
  NOTE_C4,NOTE_C4,NOTE_C4,           NOTE_A3,NOTE_A3,NOTE_A3,     NOTE_C4,NOTE_C4,NOTE_C4,    REST,REST,REST,REST,
  NOTE_E4,NOTE_E4,NOTE_E4,           NOTE_C4,NOTE_C4,NOTE_C4,     NOTE_E4,NOTE_E4,NOTE_E4,    REST,REST,REST,REST,
  NOTE_G4,NOTE_G4,NOTE_G4,            REST,REST,REST,             NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4, 
  REST,REST,REST,REST,REST,REST,REST,REST, 
  NOTE_G4,NOTE_G4, 
  REST,REST,REST,REST,REST,REST,REST,REST, 
  NOTE_G4
};

uint8_t dofenschmirtzNoteDurations[] = {
  6, 6, 6, 8,
  3, 3, 3, 4,
  3, 3, 4, 8, 2, 8, 1
};

int period1 = 500;
int period2 = 500;
int lastTime1 = 0;
int lastTime2 = 0;
int playingStartTime = 0;

void updateFreq() {
  int current_time = millis();
  int playingTime = current_time - playingStartTime;
  
}

void updateBuzzers() {

}