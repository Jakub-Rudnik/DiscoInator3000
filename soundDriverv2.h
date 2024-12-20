int musicLength = 15;

int timeUnitForMusic = 20000;

int halfPeriod1 = 4000;
int halfPeriod2 = 4000;
unsigned long long  nextNoteTime1 = 0;
unsigned long long  nextNoteTime2 = 0;
int noteIndex1 = 0;

unsigned long long  playingStartTime = 0;

int* noteArray1 = dofenschmirtsMelody;
int* durationArray1 = dofenschmirtzNoteDurations;

int songDurationInMicros = dofenschmirtzSongDuration * timeUnitForMusic;

void updateFreq() {
  int timeSincePlaying = micros() - playingStartTime;
  if (timeSincePlaying >= nextNoteTime1) {
    halfPeriod1 = 500000 / noteArray1[noteIndex1];
    noteIndex1++; 
    noteIndex1 %= musicLength;
    nextNoteTime1 = durationArray1[noteIndex1] * timeUnitForMusic;
    nextNoteTime1 %= songDurationInMicros;
  }
}

unsigned long lastTime1 = 0;
unsigned long lastTime2 = 0;
int buzzerState1 = 0;
int buzzerState2 = 0;

inline void updateBuzzers() {
  unsigned long currentTime = micros();
  if (currentTime - lastTime1 >= halfPeriod1) {
    digitalWrite(BUZZER_PIN, buzzerState1 ? HIGH : LOW);
    buzzerState1 = !buzzerState1;
    lastTime1 = currentTime;
  }
}



