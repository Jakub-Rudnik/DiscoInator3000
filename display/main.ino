#include <Arduino.h>
#include "LedControl.h"
#include "SoundControl.h"
#include "DisplayManager.h"
#include "SensorHandler.h"
#include "ModeManager.h"

// Piny
const int buttonPin = 7;          // Pin przycisku trybu "Vixa"
const int temperatureSensorPin = A1; // Pin czujnika temperatury
const int soundSensorPin = A2;    // Pin czujnika dźwięku

// Zmienne globalne
int currentMode = 0; // 0 - Tryb początkowy, 1 - Tryb "Vixa"

// Zmienne do obsługi czasu
unsigned long lastSensorUpdateTime = 0;
unsigned long lastLedUpdateTime = 0;
unsigned long lastSoundUpdateTime = 0;
unsigned long debounceDelay = 50;    // Opóźnienie dla debounce przycisku
unsigned long lastButtonPressTime = 0;

// Czasy aktualizacji
const unsigned long sensorUpdateInterval = 100;  // Częstotliwość odczytu czujników (ms)
const unsigned long ledUpdateInterval = 50;      // Częstotliwość aktualizacji LED (ms)
const unsigned long soundUpdateInterval = 200;   // Częstotliwość aktualizacji dźwięku (ms)

// Obiekty klas
LedControl ledControl;
SoundControl soundControl;
DisplayManager displayManager;
SensorHandler sensorHandler;
ModeManager modeManager;

void setup() {
    // Inicjalizacja pinów
    pinMode(buttonPin, INPUT_PULLUP);

    // Inicjalizacja bibliotek
    ledControl.begin();
    soundControl.begin();
    displayManager.begin();
    sensorHandler.begin(temperatureSensorPin, soundSensorPin);
    modeManager.begin();

    // Uruchomienie trybu początkowego
    displayManager.showStartupScreen("DiscoInator3000");
    soundControl.playStartupSound();
    ledControl.setInitialPattern();
}

void loop() {
    unsigned long currentMillis = millis();

    // Odczyt wartości z czujników (co `sensorUpdateInterval` ms)
    if (currentMillis - lastSensorUpdateTime >= sensorUpdateInterval) {
        lastSensorUpdateTime = currentMillis;

        float temperature = sensorHandler.getTemperature();
        int noiseLevel = sensorHandler.getNoiseLevel();

        // Dynamiczne dostosowanie efektów do otoczenia
        ledControl.adjustPattern(temperature, noiseLevel);
    }

    // Sprawdzanie przycisku trybu "Vixa" z debounce
    if (digitalRead(buttonPin) == LOW && (currentMillis - lastButtonPressTime >= debounceDelay)) {
        lastButtonPressTime = currentMillis;
        currentMode = 1 - currentMode; // Przełączanie między trybami
        modeManager.switchMode(currentMode, ledControl, soundControl, displayManager);
    }

    // Aktualizacja LED (co `ledUpdateInterval` ms)
    if (currentMillis - lastLedUpdateTime >= ledUpdateInterval) {
        lastLedUpdateTime = currentMillis;

        if (currentMode == 0) {
            ledControl.updateRegularMode();
        } else {
            ledControl.updateVixaMode();
        }
    }

    // Aktualizacja dźwięku (co `soundUpdateInterval` ms)
    if (currentMillis - lastSoundUpdateTime >= soundUpdateInterval) {
        lastSoundUpdateTime = currentMillis;

        if (currentMode == 0) {
            soundControl.updateRegularSound();
        } else {
            soundControl.updateVixaSound();
        }
    }

    
    // Wyświetlenie wizerunku DJ-a w zależności od trybu
    if (currentMode == 0) {
        displayManager.showVixaDJ(false); // Tryb normalny
    } else {
        displayManager.showVixaDJ(true);  // Tryb "Vixa"
    }

}