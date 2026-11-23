const int TOUCH_PIN = 2;   // D2

void setup() {
  Serial.begin(9600);
  pinMode(TOUCH_PIN, INPUT);
}

void loop() {
  int touchState = digitalRead(TOUCH_PIN);

  if (touchState == HIGH) {
    Serial.println("Made contact");
    delay(150); // small debounce delay
  }
}
