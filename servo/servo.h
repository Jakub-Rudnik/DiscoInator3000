#pragma once
#include <Servo.h>

Servo myServo; // Obiekt serwa

void setupServo() {
  myServo.attach(SERVO_PIN); // Podłącz serwo do pinu cyfrowego 9
}

void SpinServo() {
  myServo.write(95); 
}
void StopServo() {
  myServo.write(90); 
}

