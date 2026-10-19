// Define the pre-wired pins on the Arduino Sensor Kit
const int buttonPin = 4; // Grove Button is on D4
const int ledPin = 6;    // Grove Red LED is on D6

int ledState = LOW;         // Tracks the current state of the LED
int buttonState = LOW;      // Tracks the current reading from the button pin
int lastButtonState = LOW;  // Tracks the previous reading from the button pin

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Start with the LED turned off
  digitalWrite(ledPin, ledState);
}

void loop() {
  // Read the current status of the button
  buttonState = digitalRead(buttonPin);

  // Check if the button transition changed from NOT pressed to PRESSED
  if (buttonState == HIGH && lastButtonState == LOW) {
    // Toggle the state variable
    if (ledState == HIGH) {
      ledState = LOW;
    } else {
      ledState = HIGH;
    }

    // Apply the new state to the LED
    digitalWrite(ledPin, ledState);

    // Small delay to handle button bounce
    delay(50);
  }

  // Save the current state for the next loop comparison
  lastButtonState = buttonState;
}
