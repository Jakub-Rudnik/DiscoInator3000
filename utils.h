void displayVixa() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.print(" IMPREZA ");
  display.display();
}

void displayNormal() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.print(" SPOKOJNY DZIEN ");
  display.display();
}

uint16_t* currentNormalModeMelody;
uint8_t* currentNormalModeNoteDurations;
int normalModeMelodyLength; // Liczba nut w bieżącej melodii

void switchNormalModeMelody(uint8_t melodyIndex) {
  switch (melodyIndex) {
    case 0:
      currentNormalModeMelody = lickMelody;
      currentNormalModeNoteDurations = lickNoteDurations;
      normalModeMelodyLength = sizeof(lickMelody) / sizeof(lickMelody[0]);
      break;
    case 1:
      currentNormalModeMelody = catMelody;
      currentNormalModeNoteDurations = catNoteDurations;
      normalModeMelodyLength = sizeof(catMelody) / sizeof(catMelody[0]);
      break;
    case 2:
      currentNormalModeMelody = starMelody;
      currentNormalModeNoteDurations = starNoteDurations;
      normalModeMelodyLength = sizeof(starMelody) / sizeof(starMelody[0]);
      break;
  }
}

uint16_t* currentPartyModeMelody;
uint8_t* currentPartyModeNoteDurations;
int partyModeMelodyLength; // Liczba nut w bieżącej melodii

void switchPartyModeMelody(uint8_t melodyIndex) {
  switch (melodyIndex) {
    case 0:
      currentPartyModeMelody = rickMelody;
      currentPartyModeNoteDurations = rickNoteDurations;
      partyModeMelodyLength = sizeof(rickMelody) / sizeof(rickMelody[0]);
      break;
    case 1:
      currentPartyModeMelody = sevenNationMelody;
      currentPartyModeNoteDurations = sevenNationNoteDurations;
      partyModeMelodyLength = sizeof(sevenNationMelody) / sizeof(sevenNationMelody[0]);
      break;
    case 2:
      currentPartyModeMelody = crazyFrogMelody;
      currentPartyModeNoteDurations = crazyFrogNoteDurations;
      partyModeMelodyLength = sizeof(crazyFrogMelody) / sizeof(crazyFrogMelody[0]);
      break;
  }
}