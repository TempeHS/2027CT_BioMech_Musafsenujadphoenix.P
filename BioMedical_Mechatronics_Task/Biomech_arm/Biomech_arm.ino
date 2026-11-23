#include <Servo.h>
#include "Ultrasonic.h"   // quotes: the file is in the sketch folder

const int BUTTON_PIN = 4;
const int LED_PIN = 6;
const int SERVO_PIN = 3;

Ultrasonic ultrasonic(2);   // D2
Servo myServo;

int ledState = LOW;
int lastButtonState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  myServo.attach(SERVO_PIN);
myServo.write(0);
}

void loop() {

  int distance = ultrasonic.read();
  int buttonState = digitalRead(BUTTON_PIN);
  Serial.println(distance);


  if (buttonState == HIGH && lastButtonState == LOW) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
  }

if (distance < 15) {
  myServo.write(90);
} else {
  myServo.write(0);
}


  lastButtonState = buttonState;
}
