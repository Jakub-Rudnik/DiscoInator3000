int NOTE_A3 = 220;
int NOTE_C4 = 262;
int NOTE_D4 = 294;
int NOTE_E4 = 330;
int NOTE_F4 = 350;
int NOTE_G4 = 392;
int REST = 1;

int dofenschmirtsMelody[] = {
  NOTE_C4, NOTE_A3, NOTE_C4, REST,
  NOTE_E4, NOTE_C4, NOTE_E4, REST, 
  NOTE_G4, REST, NOTE_G4, REST, NOTE_G4, REST, NOTE_G4
};

int dofenschmirtzNoteDurations[] = {
  6, 6, 6, 8,
  6, 6, 6, 8,
  6, 6, 8, 16, 4, 16, 2
};

int dofenschmirtzSongDuration = 110;

int lickMelody[] = {
  NOTE_A3, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_F4,
  REST, NOTE_C4, NOTE_D4, REST
};

int lickNoteDurations[] = {
  4, 4, 4, 4, 4, 2,
  8, 2, 2, 1
};