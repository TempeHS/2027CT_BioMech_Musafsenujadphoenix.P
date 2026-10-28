#include "Ultrasonic.h"

Ultrasonic ultrasonic(2);   // Grove 3-pin sensor: trigger and echo share D2

void setup() {
  Serial.begin(115200);
}

void loop() {
  int distance = ultrasonic.read();   // distance in cm
  Serial.println(distance);
  delay(100);
}
