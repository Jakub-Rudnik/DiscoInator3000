#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include "doofenshmirtz.h"
// Define pins
#define TFT_CS     10
#define TFT_DC     9
#define TFT_RST    8
#define TFT_BL     7

// Create the display object
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH); // Turn on backlight

  // Initialize the display
  tft.initR(INITR_BLACKTAB);
  tft.fillScreen(ST77XX_BLACK);

  // Draw the bitmap at (0, 0) position
  tft.drawRGBBitmap(0, 0, epd_bitmap_anime_booba, 128, 160);
}

void loop() {
  // Nothing to do here
}
