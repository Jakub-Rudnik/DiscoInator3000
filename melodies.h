uint16_t NOTE_A3 = 220;
uint16_t NOTE_C4 = 262;
uint16_t NOTE_D4 = 294;
uint16_t NOTE_E4 = 330;
uint16_t NOTE_F4 = 350;
uint16_t NOTE_G4 = 392;
uint16_t REST = 0;

uint16_t dofenschmirtsMelody[] = {
  NOTE_C4, NOTE_A3, NOTE_C4, REST,
  NOTE_E4, NOTE_C4, NOTE_E4, REST, 
  NOTE_G4, REST, NOTE_G4, REST, NOTE_G4, REST, NOTE_G4
};

uint8_t dofenschmirtzNoteDurations[] = {
  6, 6, 6, 8,
  6, 6, 6, 8,
  6, 6, 8, 16, 4, 16, 2
};

uint16_t lickMelody[] = {
  NOTE_A3, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_F4,
  REST, NOTE_C4, NOTE_D4, REST
};

uint8_t lickNoteDurations[] = {
  4, 4, 4, 4, 4, 2,
  8, 2, 2, 1
};