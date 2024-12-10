
void loop() {
  int val = analogRead(SOUND_PIN);  
  if (val > 100) {
    Serial.println(val);
  }
}