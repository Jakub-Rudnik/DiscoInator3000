#include "pinout.h"
#include <Servo.h>

Servo myServo; // Obiekt serwa

void setup() {
  myServo.attach(SERVO_PIN); // Podłącz serwo do pinu cyfrowego 9
  
}

void loop() {
  for (int i = 90; i >= 0; i--) {
    myServo.write(i);
    delay(100);
  }

     // Serwo w pozycji neutralnej (brak ruchu)
    
  
  
  
}
