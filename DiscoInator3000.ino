#include "pinout.h"
#include "melodies.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#include "utils.h"

uint8_t last_mode = 0;
uint8_t current_normal_melody = 0;
uint8_t current_party_melody = 0;
uint8_t normal_melody_index = 0;
uint8_t party_melody_index = 0;
uint8_t update_display_flag = 0;

void IRAM_ATTR changeMode() {
  stop_playing = 1;
}

void IRAM_ATTR changeToSong1() {
  current_normal_melody = 0;
  normal_melody_index = 0;
  switchNormalModeMelody(current_normal_melody);
  update_display_flag = 1;  
}

void IRAM_ATTR changeToSong2() {
  current_normal_melody = 1;
  normal_melody_index = 0;
  switchNormalModeMelody(current_normal_melody);
  update_display_flag = 1;
}

void IRAM_ATTR changeToSong3() {
  current_normal_melody = 2;
  normal_melody_index = 0;
  switchNormalModeMelody(current_normal_melody);
  update_display_flag = 1;
}

void IRAM_ATTR changeToSong4() {
  current_party_melody = 0;
  party_melody_index = 0;
  switchPartyModeMelody(current_party_melody);
  update_display_flag = 1;
}

void IRAM_ATTR changeToSong5() {
  current_party_melody = 1;
  party_melody_index = 0;
  switchPartyModeMelody(current_party_melody);
  update_display_flag = 1;
}

void IRAM_ATTR changeToSong6() {
  current_party_melody = 2;
  party_melody_index = 0;
  switchPartyModeMelody(current_party_melody);
  update_display_flag = 1;
}

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(SECOND_BUZZER_PIN, OUTPUT);
  pinMode(MODE_PIN, INPUT_PULLDOWN);
  pinMode(BTN_1_PIN, INPUT_PULLUP);
  pinMode(BTN_2_PIN, INPUT_PULLUP);
  pinMode(BTN_3_PIN, INPUT_PULLUP);
  pinMode(BTN_4_PIN, INPUT_PULLUP);
  pinMode(BTN_5_PIN, INPUT_PULLUP);
  pinMode(BTN_6_PIN, INPUT_PULLUP);

  attachInterrupt(MODE_PIN, changeMode, CHANGE);
  attachInterrupt(BTN_1_PIN, changeToSong1, RISING);
  attachInterrupt(BTN_2_PIN, changeToSong2, RISING);
  attachInterrupt(BTN_3_PIN, changeToSong3, RISING);
  attachInterrupt(BTN_4_PIN, changeToSong4, RISING);
  attachInterrupt(BTN_5_PIN, changeToSong5, RISING);
  attachInterrupt(BTN_6_PIN, changeToSong6, RISING);

  setupDisplay();
  last_mode = digitalRead(MODE_PIN) == LOW;
}

void loop() {  
  if (stop_playing) {
    stop_playing = 0;
  }

  switchNormalModeMelody(current_normal_melody);
  switchPartyModeMelody(current_party_melody);

  uint8_t current_mode = digitalRead(MODE_PIN) == HIGH;
  
  if (current_mode != last_mode)
  {
    last_mode = current_mode;

    if (!current_mode) {
      displayNormal(current_normal_melody);

      while (!stop_playing) {
        for (normal_melody_index = 0; normal_melody_index < normal_mode_melody_length; normal_melody_index++) {
          if (stop_playing) break;

          if (update_display_flag) {
            update_display_flag = 0;
            displayCurrentSongId(current_normal_melody);
          }

          int note_duration = 1000 / current_normal_mode_note_durations[normal_melody_index];
          playTwoNotes(BUZZER_PIN, current_normal_mode_melody[normal_melody_index], SECOND_BUZZER_PIN, current_normal_mode_melody[normal_melody_index] * 1.5, note_duration);
        }
      }
    } 
    else {
      displayParty(current_party_melody);

      for (int i = 0; i < sizeof(dofenschmirtz_melody) / sizeof(dofenschmirtz_melody[0]); i++) {
        if (stop_playing) break;
        int note_duration = 1000 / dofenschmirtz_note_durations[i];
        playTwoNotes(BUZZER_PIN, dofenschmirtz_melody[i], SECOND_BUZZER_PIN, dofenschmirt_melody[i] * 1.5, note_duration);
      }

      while (!stop_playing) {
        for (party_melody_index = 0; party_melody_index < party_mode_melody_length; party_melody_index++) {
          if (stop_playing) break;

          if (update_display_flag) {
            update_display_flag = 0;
            displayCurrentSongId(current_party_melody);
          }

          int note_duration = 1000 / current_party_mode_note_durations[party_melody_index];
          playTwoNotes(BUZZER_PIN, current_party_mode_melody[party_melody_index], SECOND_BUZZER_PIN, current_party_mode_melody[party_melody_index] * 1.5, note_duration);
        }
      }
    } 
  }

  delay(50);
}
