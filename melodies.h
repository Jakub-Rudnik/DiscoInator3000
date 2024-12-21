uint16_t NOTE_C3 = 131;
uint16_t NOTE_D3 = 147;
uint16_t NOTE_E3 = 165;
uint16_t NOTE_F3 = 175;
uint16_t NOTE_G3 = 196;
uint16_t NOTE_A3 = 220;
uint16_t NOTE_B3 = 247;
uint16_t NOTE_C4 = 262;
uint16_t NOTE_D4 = 294;
uint16_t NOTE_D4S = 311;
uint16_t NOTE_E4 = 330;
uint16_t NOTE_F4 = 350;
uint16_t NOTE_G4 = 392;
uint16_t NOTE_G4S = 415;
uint16_t NOTE_A4 = 440;
uint16_t NOTE_A4S = 466;
uint16_t NOTE_C5 = 523;
uint16_t NOTE_C5S = 554;
uint16_t NOTE_F5 = 698;
uint16_t REST = 0;

//-----------------------------------DOOFENSHMIRTZ JINGLE-----------------------------------
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

//-----------------------------------THE LICK-----------------------------------
uint16_t lickMelody[] = {
  NOTE_A3, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_F4,
  REST, NOTE_C4, NOTE_D4, REST
};

uint8_t lickNoteDurations[] = {
  4, 4, 4, 4, 4, 2,
  8, 2, 2, 1
};

//-----------------------------------WLAZŁ KOTEK NA PŁOTEK-----------------------------------
uint16_t catMelody[] = {
  NOTE_G4, NOTE_E4, REST, NOTE_E4, NOTE_F4, NOTE_D4, REST, NOTE_D4, NOTE_C4, NOTE_E4, NOTE_G4, REST,
  NOTE_G4, NOTE_E4, REST, NOTE_E4, NOTE_F4, NOTE_D4, REST, NOTE_D4, NOTE_C4, NOTE_E4, NOTE_C4, REST
};

uint8_t catNoteDurations[] = {
  2, 2, 16, 2, 2, 2, 16, 2, 4, 4, 2, 2,
  2, 2, 16, 2, 2, 2, 16, 2, 4, 4, 2, 2
};

//-----------------------------------TWINKLE TWINKLE LITTLE STAR-----------------------------------
uint16_t starMelody[] = {
  //1 bar
  NOTE_C4, REST, NOTE_C4, REST, NOTE_G4, REST, NOTE_G4, REST, NOTE_A4, REST, NOTE_A4, REST, NOTE_G4, REST,
  //2 bar
  NOTE_F4, REST, NOTE_F4, REST, NOTE_E4, REST, NOTE_E4, REST, NOTE_D4, REST, NOTE_D4, REST, NOTE_C4, REST,
  //3 bar
  NOTE_G4, REST, NOTE_G4, REST, NOTE_F4, REST, NOTE_F4, REST, NOTE_E4, REST, NOTE_E4, REST, NOTE_D4, REST,
  //4bar - same as 3
  NOTE_G4, REST, NOTE_G4, REST, NOTE_F4, REST, NOTE_F4, REST, NOTE_E4, REST, NOTE_E4, REST, NOTE_D4, REST,
  //5 bar - same as 1
  NOTE_C4, REST, NOTE_C4, REST, NOTE_G4, REST, NOTE_G4, REST, NOTE_A4, REST, NOTE_A4, REST, NOTE_G4, REST,
  //6 bar - same as 2
  NOTE_F4, REST, NOTE_F4, REST, NOTE_E4, REST, NOTE_E4, REST, NOTE_D4, REST, NOTE_D4, REST, NOTE_C4, REST,
};

uint8_t starNoteDurations[] = {
  2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 1, 16,
  2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 1, 16,
  2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 1, 16,
  2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 1, 16,
  2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 1, 16,
  2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 1, 16,
};

//-----------------------------------RICK ROLL-----------------------------------
uint16_t rickMelody[] = {
  NOTE_G3, NOTE_A3, NOTE_C4, NOTE_A3,
  NOTE_E4, REST, NOTE_E4, REST, NOTE_D4, REST,
  //variation #1
  NOTE_G3, NOTE_A3, NOTE_C4, NOTE_A3,
  NOTE_D4, REST, NOTE_D4, REST, NOTE_C4, REST,
  //variation #2
  NOTE_G3, NOTE_A3, NOTE_C4, NOTE_A3,
  NOTE_C4, REST, NOTE_D4, REST, 
  NOTE_B3, NOTE_A3, NOTE_G3, REST, NOTE_G3, NOTE_D4, REST, NOTE_C4, REST
};

uint8_t rickNoteDurations[] = {
  8, 8, 8, 8,
  3, 16, 6, 8, 2, 3,
  //variation #1
  8, 8, 8, 8,
  3, 16, 6, 8, 2, 3,
  //variation #2
  8, 8, 8, 8,
  3, 16, 6, 8,
  2, 6, 5, 16, 5, 4, 4, 2, 3
};

//-----------------------------------SEVEN NATION ARMY-----------------------------------
uint16_t sevenNationMelody[] = {
  NOTE_E4, REST, NOTE_E4, REST, NOTE_G4, REST, NOTE_E4, REST, NOTE_D4, REST, NOTE_C4, REST, NOTE_B3, REST,
  NOTE_E4, REST, NOTE_E4, REST, NOTE_G4, REST, NOTE_E4, REST, NOTE_D4, REST, NOTE_C4, REST, NOTE_D4, REST, NOTE_C4, REST, NOTE_B3, REST
};

uint8_t sevenNationNoteDurations[] = {
  2, 16, 4, 16, 4, 16, 4, 16, 4, 16, 1, 16, 1, 6,
  2, 16, 4, 16, 4, 16, 4, 16, 4, 16, 4, 16, 4, 16, 4, 16, 1, 6
};

//-----------------------------------CRAZY FROG-----------------------------------
uint16_t crazyFrogMelody[] = {
  //1 bar
  NOTE_F4, REST, NOTE_G4S, REST, NOTE_F4, REST, NOTE_F4, NOTE_A4S, REST, NOTE_F4, REST, NOTE_D4S, REST,
  //2 bar
  NOTE_F4, REST, NOTE_C5, REST, NOTE_F4, REST, NOTE_F4, NOTE_C5S, REST, NOTE_C5, REST, NOTE_G4S, REST,
  //3 bar
  NOTE_F4, REST, NOTE_C5, REST, NOTE_F5, REST, NOTE_F4, NOTE_D4S, REST, NOTE_D4S, REST, NOTE_C4, REST, NOTE_G4, REST, NOTE_F4, REST, REST
};

uint8_t crazyFrogNoteDurations[] = {
  //1 bar
  3, 8, 4, 16, 5, 16, 6, 5, 16, 5, 16, 5, 16,
  //2 bar
  3, 8, 4, 16, 5, 16, 6, 5, 16, 5, 16, 5, 16,
  //3 bar
  5, 16, 5, 16, 5, 16, 7, 7, 100, 7, 16, 4, 16, 4, 16, 3, 1, 2
};
