int musicLength = 15;

int timeUnitForMusic = 20;

int halfPeriod1 = 100;
int halfPeriod2 = 100;
unsigned long long  nextNoteTime1 = 0;
unsigned long long  nextNoteTime2 = 0;
int noteIndex1 = 0;

unsigned long long  playingStartTime = 0;

int* noteArray1 = dofenschmirtsMelody;
int* durationArray1 = dofenschmirtzNoteDurations;

void updateFreq() {
  int timeSincePlaying = micros() - playingStartTime;
  if (timeSincePlaying >= nextNoteTime1) {
    halfPeriod1 = 500000 / noteArray1[noteIndex1];
    noteIndex1++; 
    noteIndex1 %= musicLength;
    nextNoteTime1 = durationArray1[noteIndex1] * timeUnitForMusic;
  }
}

unsigned long long  lastTime1 = 0;
unsigned long long  lastTime2 = 0;
int buzzerState1 = 0;
int buzzerState2 = 0;

void updateBuzzers() {
  unsigned long long currentTime = micros();
  if (currentTime - lastTime1 >= halfPeriod1) {
    digitalWrite(BUZZER_PIN, buzzerState1 ? HIGH : LOW);
    buzzerState1 = !buzzerState1;
    lastTime1 = currentTime;
  }
}


