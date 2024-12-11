#pragma once

bool partyMode = 0;
int switchCount = 0;

void setupLogic() {
  partyMode = !clapMode;
  pinMode(VIXA_PIN, OUTPUT);
}

void StartParty() {
  setupOLED();
  DisplayText("DISCO\nINATOR\n3000");
  DrawCool();
  SpinServo();
  digitalWrite(VIXA_PIN, HIGH);
}

void StopParty() {
  StopServo();
  DrawJazz();
  digitalWrite(VIXA_PIN, LOW);
}

void UpdateParty() {
  if (clapMode != partyMode) {
    //Serial.print("switch "); Serial.println(switchCount++);
    partyMode = clapMode;
    if (partyMode) {
      StartParty();
    }
    else {
      StopParty();
    }
  }
}
