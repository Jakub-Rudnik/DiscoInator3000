#include "pinout.h"
#include "playNotes.h"
#include "melodies.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#include "utils.h"

void IRAM_ATTR changeMode() {
  stopPlaying = 1;
}

uint8_t currentNormalMelody = 0;
uint8_t i = 0;
uint8_t ii = 0;
uint8_t currentPartyMelody = 0;

void IRAM_ATTR changeToSong1() {
  currentNormalMelody = 0;
  i = 0;
  switchNormalModeMelody(currentNormalMelody);
}

void IRAM_ATTR changeToSong2() {
  currentNormalMelody = 1;
  i = 0;
  switchNormalModeMelody(currentNormalMelody);
}

void IRAM_ATTR changeToSong3() {
  currentNormalMelody = 2;
  i = 0;
  switchNormalModeMelody(currentNormalMelody);
}

void IRAM_ATTR changeToSong4() {
  currentPartyMelody = 0;
  ii = 0;
  switchPartyModeMelody(currentPartyMelody);
}

void IRAM_ATTR changeToSong5() {
  currentPartyMelody = 1;
  ii = 0;
  switchPartyModeMelody(currentPartyMelody);
}

void IRAM_ATTR changeToSong6() {
  currentPartyMelody = 2;
  ii = 0;
  switchPartyModeMelody(currentPartyMelody);
}

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(SECOND_BUZZER_PIN, OUTPUT);
  pinMode(MODE_PIN, INPUT_PULLDOWN);
  pinMode(BTN_1, INPUT_PULLUP);
  pinMode(BTN_2, INPUT_PULLUP);
  pinMode(BTN_3, INPUT_PULLUP);
  pinMode(BTN_4, INPUT_PULLUP);
  pinMode(BTN_5, INPUT_PULLUP);
  pinMode(BTN_6, INPUT_PULLUP);

  attachInterrupt(MODE_PIN, changeMode, CHANGE);
  attachInterrupt(BTN_1, changeToSong1, RISING);
  attachInterrupt(BTN_2, changeToSong2, RISING);
  attachInterrupt(BTN_3, changeToSong3, RISING);
  attachInterrupt(BTN_4, changeToSong4, RISING);
  attachInterrupt(BTN_5, changeToSong5, RISING);
  attachInterrupt(BTN_6, changeToSong6, RISING);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }

  display.clearDisplay();
  display.setTextColor(WHITE);
}

int lastMode = 1;

void loop() {  
  stopPlaying = 0;

  switchNormalModeMelody(currentNormalMelody);
  switchPartyModeMelody(currentPartyMelody);

  int currentMode = digitalRead(MODE_PIN) == HIGH;
  
  if (currentMode != lastMode)
  {
    lastMode = currentMode;

    if (!currentMode) {
      displayNormal();

      while (!stopPlaying) {
        for (i = 0; i < normalModeMelodyLength; i++) {
          if (stopPlaying) break;
          int noteDuration = 1000 / currentNormalModeNoteDurations[i];
          playTwoNotes(BUZZER_PIN, currentNormalModeMelody[i], SECOND_BUZZER_PIN, currentNormalModeMelody[i] * 1.5, noteDuration);
        }
      }
    } 
    else {
      displayVixa();

      for (int i = 0; i < sizeof(dofenschmirtsMelody) / sizeof(dofenschmirtsMelody[0]); i++) {
        if (stopPlaying) break;
        int noteDuration = 1000 / dofenschmirtzNoteDurations[i];
        playTwoNotes(BUZZER_PIN, dofenschmirtsMelody[i], SECOND_BUZZER_PIN, dofenschmirtsMelody[i] * 1.5, noteDuration);
      }

      while (!stopPlaying) {
        for (ii = 0; ii < partyModeMelodyLength; ii++) {
          if (stopPlaying) break;
          int noteDuration = 1000 / currentPartyModeNoteDurations[ii];
          playTwoNotes(BUZZER_PIN, currentPartyModeMelody[ii], SECOND_BUZZER_PIN, currentPartyModeMelody[ii] * 1.5, noteDuration);
        }
      }
    } 
  }
}