#pragma once

bool partyMode = 0;
int switchCount = 0;

void setupLogic() {
  partyMode = !clapMode;
}

void StartParty() {
  setupOLED();
  DisplayText("DISCO\nINATOR\n3000");
  SpinServo();
  DrawCool();
}

void StopParty() {
  StopServo();
  DrawJazz();
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
