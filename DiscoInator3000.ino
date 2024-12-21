#include "pinout.h"
#include "playNotes.h"
#include "melodies.h"
// #include "WiFi.h"
// #include <WebServer.h>
// #include <ArduinoJson.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#include "utils.h"
// const char* ssid = "UPC6874093";
// const char* password = "Snesxj6runcf";

// WebServer server(80);

// void handleRoot() {
//   server.send(200, "text/plain", "Ready");
// }

// void changeSound() {
//     String body = server.arg("plain");

//     JsonDocument* doc = new JsonDocument();
//     DeserializationError error = deserializeJson(*doc, body);

//     if (error) {
//       Serial.print("deserializeJson() failed: ");
//       Serial.println(error.c_str());
//       server.send(400, "application/json", "{\"message\":\"Invalid JSON\"}");
//       return;
//     }

//     // int songId = (*doc)["sound-id"];
//     // currentSongId = songId;
//     // Serial.println("Name: " + String(songId));

//     server.send(200, "application/json", "{\"message\":\"Data received successfully\"}");
// }

void IRAM_ATTR changeMode() {
  stopPlaying = 1;
}

void setup() {
  Serial.begin(9600);
  // WiFi.softAP("ESP32");
  // server.on("/", handleRoot);
  // server.on("/change-sound", HTTP_POST, changeSound);
  // server.begin();
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(SECOND_BUZZER_PIN, OUTPUT);
  pinMode(MODE_PIN, INPUT_PULLDOWN);

  attachInterrupt(MODE_PIN, changeMode, CHANGE);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }

  display.clearDisplay();
  display.setTextColor(WHITE);
  // display.setTextSize(1);
  // display.setCursor(0, 0);
  // display.print("Tryb: ");
}

int lastMode = 1;
void loop() {
  // if (WiFi.status() != WL_CONNECTED) {
  //   connectWiFi();
  // }
  // server.handleClient();
  
  switchNormalModeMelody(2);
  switchPartyModeMelody(2);

  stopPlaying = 0;
  int currentMode = digitalRead(MODE_PIN) == HIGH;
  
  if (currentMode != lastMode)
  {
    lastMode = currentMode;

    if (!currentMode) {
      displayNormal();

      while (!stopPlaying) {
        for (int i = 0; i < normalModeMelodyLength; i++) {
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
        for (int i = 0; i < partyModeMelodyLength; i++) {
          if (stopPlaying) break;
          int noteDuration = 1000 / currentPartyModeNoteDurations[i];
          playTwoNotes(BUZZER_PIN, currentPartyModeMelody[i], SECOND_BUZZER_PIN, currentPartyModeMelody[i] * 1.5, noteDuration);
        }
      }
    } 
  }
}

// void connectWiFi() {
//   WiFi.mode(WIFI_OFF);
//   delay(1000);
//   WiFi.mode(WIFI_STA);
//   WiFi.begin(ssid,password);
//   Serial.println("Connecting to WIFi");

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   Serial.print("connected to :"); Serial.println(ssid);
//   Serial.print("IP address : "); Serial.println(WiFi.localIP());
// }
