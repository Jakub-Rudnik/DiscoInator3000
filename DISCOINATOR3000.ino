uint8_t BUZZER_PIN = 5;
uint8_t SECOND_BUZZER_PIN = 18;
uint8_t MODE_PIN = 34;

#include "playNotes.h"
#include "melodies.h"
#include "soundDriverv2.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup()
{
  Serial.begin(9600);

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(SECOND_BUZZER_PIN, OUTPUT);
  pinMode(MODE_PIN, INPUT_PULLDOWN);

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

void loop()
{
  int currentMode = digitalRead(MODE_PIN) == HIGH;
  if (currentMode !=  lastMode)
  {
    lastMode = currentMode;
    if (currentMode) {
      displayVIXA();
    }
    else {
      displayNormal();
    }
  } 
  updateFreq();
  updateBuzzers();
}



void displayVIXA() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Tryb: VIXA");
  display.display();
}

void displayNormal() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Tryb: Normlany");
  display.display();
}
