void setupDisplay() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }

  display.clearDisplay();
  display.setTextColor(WHITE);
}

void displayCurrentSongId(uint8_t current_normal_melody) {
  display.fillRect(0, 10, 128, 10, BLACK);
  display.setCursor(0, 10);
  display.setTextColor(WHITE);
  display.print("Piosenka: ");
  display.print(current_normal_melody + 1);
  display.display(); 
}

void displayNormal(uint8_t current_normal_melody) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Tryb: Normalny");
  displayCurrentSongId(current_normal_melody);
}

void displayParty(uint8_t current_party_melody) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Tryb: Dyskoteka");
  displayCurrentSongId(current_party_melody);
}

uint16_t* current_normal_mode_melody;
uint8_t* current_normal_mode_note_durations;
uint8_t normal_mode_melody_length;

void switchNormalModeMelody(uint8_t melody_index) {
  switch (melody_index) {
    case 0:
      current_normal_mode_melody = lick_melody;
      current_normal_mode_note_durations = lick_note_durations;
      normal_mode_melody_length = sizeof(lick_melody) / sizeof(lick_melody[0]);
      break;
    case 1:
      current_normal_mode_melody = cat_melody;
      current_normal_mode_note_durations = cat_note_durations;
      normal_mode_melody_length = sizeof(cat_melody) / sizeof(cat_melody[0]);
      break;
    case 2:
      current_normal_mode_melody = star_melody;
      current_normal_mode_note_durations = star_note_durations;
      normal_mode_melody_length = sizeof(star_melody) / sizeof(star_melody[0]);
      break;
  }
}

uint16_t* current_party_mode_melody;
uint8_t* current_party_mode_note_durations;
uint8_t party_mode_melody_length;

void switchPartyModeMelody(uint8_t melody_index) {
  switch (melody_index) {
    case 0:
      current_party_mode_melody = rick_melody;
      current_party_mode_note_durations = rick_note_durations;
      party_mode_melody_length = sizeof(rick_melody) / sizeof(rick_melody[0]);
      break;
    case 1:
      current_party_mode_melody = seven_nation_melody;
      current_party_mode_note_durations = seven_nation_note_durations;
      party_mode_melody_length = sizeof(seven_nation_melody) / sizeof(seven_nation_melody[0]);
      break;
    case 2:
      current_party_mode_melody = crazy_frog_melody;
      current_party_mode_note_durations = crazy_frog_note_durations;
      party_mode_melody_length = sizeof(crazy_frog_melody) / sizeof(crazy_frog_melody[0]);
      break;
  }
}

int stop_playing = 0;
void playTwoNotes(int pin1, int freq1, int pin2, int freq2, int duration) {
  unsigned long period1 = freq1 == 0 ? 0 : 1000000 / freq1;  // Okres 1
  unsigned long period2 = freq2 == 0 ? 0 : 1000000 / freq2;  // Okres 2
  unsigned long half_period1 = period1 / 2;
  unsigned long half_period2 = period2 / 2;

  unsigned long start_time = millis();
  while (millis() - start_time < duration && !stop_playing) {
    // Buzzer 1
    if (freq1 > 0) {
      digitalWrite(pin1, HIGH);
      delayMicroseconds(half_period1);
      digitalWrite(pin1, LOW);
      delayMicroseconds(half_period1);
    }

    // Buzzer 2
    if (freq2 > 0) {
      digitalWrite(pin2, HIGH);
      delayMicroseconds(half_period2);
      digitalWrite(pin2, LOW);
      delayMicroseconds(half_period2);
    }
  }
}
