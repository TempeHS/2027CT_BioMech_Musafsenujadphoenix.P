class Led {
  private:
    int pin;          // properties: data each Led remembers
    bool isOn;

  public:
    Led(int ledPin) {  // constructor: runs when an object is created
      pin = ledPin;
      isOn = false;
    }

    void begin() {
      pinMode(pin, OUTPUT);
      digitalWrite(pin, LOW);
    }

    void turnOn() {    // methods: things every Led can do
      digitalWrite(pin, HIGH);
      isOn = true;
    }

    void turnOff() {
      digitalWrite(pin, LOW);
      isOn = false;
    }

    void toggle() {
      if (isOn) {
        turnOff();
      } else {
        turnOn();
      }
    }
};

class Button {
  private:
    int pin;
  public:
    Button(int buttonPin) {
      pin = buttonPin;
    }
    void begin() {
      pinMode(pin, INPUT);
    }
    bool isPressed() {
      return digitalRead(pin) == HIGH;  // Grove button: HIGH when pressed
    }
};

Led moduleLed(6);    // the Grove LED module on D6
Led builtinLed(13);  // the LED soldered onto the Uno itself
Button myButton(4);

void setup() {
  moduleLed.begin();
  builtinLed.begin();
  builtinLed.turnOn();
  myButton.begin();
}

void loop() {
  if (myButton.isPressed()) {
    moduleLed.turnOn();
    builtinLed.turnOff();
  } else {
    moduleLed.turnOff();
    builtinLed.turnOn();
  }
}
