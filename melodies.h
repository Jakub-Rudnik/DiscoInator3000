uint16_t note_c3 = 131;
uint16_t note_d3 = 147;
uint16_t note_e3 = 165;
uint16_t note_f3 = 175;
uint16_t note_g3 = 196;
uint16_t note_a3 = 220;
uint16_t note_b3 = 247;
uint16_t note_c4 = 262;
uint16_t note_d4 = 294;
uint16_t note_d4s = 311;
uint16_t note_e4 = 330;
uint16_t note_f4 = 350;
uint16_t note_g4 = 392;
uint16_t note_g4s = 415;
uint16_t note_a4 = 440;
uint16_t note_a4s = 466;
uint16_t note_c5 = 523;
uint16_t note_c5s = 554;
uint16_t note_f5 = 698;
uint16_t rest = 0;

//-----------------------------------DOOFENSHMIRTZ JINGLE-----------------------------------
uint16_t dofenschmirtz_melody[] = {
  note_c4, note_a3, note_c4, rest,
  note_e4, note_c4, note_e4, rest, 
  note_g4, rest, note_g4, rest, note_g4, rest, note_g4
};

uint8_t dofenschmirtz_note_durations[] = {
  6, 6, 6, 8,
  6, 6, 6, 8,
  6, 6, 8, 16, 4, 16, 2
};

//-----------------------------------THE LICK-----------------------------------
uint16_t lick_melody[] = {
  note_a3, note_d4, note_e4, note_f4, note_g4, note_f4,
  rest, note_c4, note_d4, rest
};

uint8_t lick_note_durations[] = {
  4, 4, 4, 4, 4, 2,
  8, 2, 2, 1
};

//-----------------------------------WLAZŁ KOTEK NA PŁOTEK-----------------------------------
uint16_t cat_melody[] = {
  note_g4, note_e4, rest, note_e4, note_f4, note_d4, rest, note_d4, note_c4, note_e4, note_g4, rest,
  note_g4, note_e4, rest, note_e4, note_f4, note_d4, rest, note_d4, note_c4, note_e4, note_c4, rest
};

uint8_t cat_note_durations[] = {
  2, 2, 16, 2, 2, 2, 16, 2, 4, 4, 2, 2,
  2, 2, 16, 2, 2, 2, 16, 2, 4, 4, 2, 2
};

//-----------------------------------TWINKLE TWINKLE LITTLE STAR-----------------------------------
uint16_t star_melody[] = {
  //1 bar
  note_c4, rest, note_c4, rest, note_g4, rest, note_g4, rest, note_a4, rest, note_a4, rest, note_g4, rest,
  //2 bar
  note_f4, rest, note_f4, rest, note_e4, rest, note_e4, rest, note_d4, rest, note_d4, rest, note_c4, rest,
  //3 bar
  note_g4, rest, note_g4, rest, note_f4, rest, note_f4, rest, note_e4, rest, note_e4, rest, note_d4, rest,
  //4bar - same as 3
  note_g4, rest, note_g4, rest, note_f4, rest, note_f4, rest, note_e4, rest, note_e4, rest, note_d4, rest,
  //5 bar - same as 1
  note_c4, rest, note_c4, rest, note_g4, rest, note_g4, rest, note_a4, rest, note_a4, rest, note_g4, rest,
  //6 bar - same as 2
  note_f4, rest, note_f4, rest, note_e4, rest, note_e4, rest, note_d4, rest, note_d4, rest, note_c4, rest,
};

uint8_t star_note_durations[] = {
  2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 1, 16,
  2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 1, 16,
  2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 1, 16,
  2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 1, 16,
  2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 1, 16,
  2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 2, 16, 1, 16,
};

//-----------------------------------RICK ROLL-----------------------------------
uint16_t rick_melody[] = {
  note_g3, note_a3, note_c4, note_a3,
  note_e4, rest, note_e4, rest, note_d4, rest,
  //variation #1
  note_g3, note_a3, note_c4, note_a3,
  note_d4, rest, note_d4, rest, note_c4, rest,
  //variation #2
  note_g3, note_a3, note_c4, note_a3,
  note_c4, rest, note_d4, rest, 
  note_b3, note_a3, note_g3, rest, note_g3, note_d4, rest, note_c4, rest
};

uint8_t rick_note_durations[] = {
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
uint16_t seven_nation_melody[] = {
  note_e4, rest, note_e4, rest, note_g4, rest, note_e4, rest, note_d4, rest, note_c4, rest, note_b3, rest,
  note_e4, rest, note_e4, rest, note_g4, rest, note_e4, rest, note_d4, rest, note_c4, rest, note_d4, rest, note_c4, rest, note_b3, rest
};

uint8_t seven_nation_note_durations[] = {
  2, 16, 4, 16, 4, 16, 4, 16, 4, 16, 1, 16, 1, 6,
  2, 16, 4, 16, 4, 16, 4, 16, 4, 16, 4, 16, 4, 16, 4, 16, 1, 6
};

//-----------------------------------CRAZY FROG-----------------------------------
uint16_t crazy_frog_melody[] = {
  //1 bar
  note_f4, rest, note_g4s, rest, note_f4, rest, note_f4, note_a4s, rest, note_f4, rest, note_d4s, rest,
  //2 bar
  note_f4, rest, note_c5, rest, note_f4, rest, note_f4, note_c5s, rest, note_c5, rest, note_g4s, rest,
  //3 bar
  note_f4, rest, note_c5, rest, note_f5, rest, note_f4, note_d4s, rest, note_d4s, rest, note_c4, rest, note_g4, rest, note_f4, rest, rest
};

uint8_t crazy_frog_note_durations[] = {
  //1 bar
  3, 8, 4, 16, 5, 16, 6, 5, 16, 5, 16, 5, 16,
  //2 bar
  3, 8, 4, 16, 5, 16, 6, 5, 16, 5, 16, 5, 16,
  //3 bar
  5, 16, 5, 16, 5, 16, 7, 7, 100, 7, 16, 4, 16, 4, 16, 3, 1, 2
};
