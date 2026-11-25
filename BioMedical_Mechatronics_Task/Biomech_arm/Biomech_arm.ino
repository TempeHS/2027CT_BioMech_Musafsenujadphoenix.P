#include <Servo.h>
#include "Ultrasonic.h"

const int ULTRASONIC_PIN = 2;   // D2
const int SERVO_PIN = 3;        // D3
const int BUTTON_PIN = 4;       // D4
const int LED_PIN = 6;          // D6
const int TOUCH_PIN = 7;        // moved from D2 to D7

Ultrasonic ultrasonic(ULTRASONIC_PIN);
Servo myServo;

int ledState = LOW;
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  Serial.begin(9600);

  pinMode(BUTTON_PIN, INPUT);
  pinMode(TOUCH_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(LED_PIN, ledState);

  myServo.attach(SERVO_PIN);
  myServo.write(0);
}

void loop() {
  int distance = ultrasonic.read();
  int buttonState = digitalRead(BUTTON_PIN);
  int touchState = digitalRead(TOUCH_PIN);

  // Button toggles LED on press edge
  if (buttonState == HIGH && lastButtonState == LOW &&
      (millis() - lastDebounceTime) > debounceDelay) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    lastDebounceTime = millis();
  }
  lastButtonState = buttonState;

  // Ultrasonic controls servo
  if (distance < 15) {
    myServo.write(90);
  } else {
    myServo.write(0);
  }

  // Touch sensor feedback
  if (touchState == HIGH) {
    Serial.println("Made contact");
  }

  Serial.print("Distance(cm): ");
  Serial.print(distance);
  Serial.print(" | LED: ");
  Serial.print(ledState);
  Serial.print(" | Touch: ");
  Serial.println(touchState);

  delay(40); // small readable update rate
}
