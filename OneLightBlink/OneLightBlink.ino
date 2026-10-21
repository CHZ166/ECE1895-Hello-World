/*
  ECE 1895 - Assignment 9: Hello World
  Part 1: One Light Blink
  Chuxuan Zhou

  Behavior: while the push button is held down, one LED blinks
  (0.5 s on, 0.5 s off). As soon as the button is released the LED
  turns off and stays off.

  Standalone ATmega328P, 16 MHz crystal, programmed as "Arduino Uno"
  with a USBtinyISP (Sketch > Upload Using Programmer).

  Wiring (Arduino pin -> ATmega328P physical pin):
    Button : D2 -> pin 4, other side of the button to GND
             (uses the internal pull-up, so pressed = LOW)
    LED    : D8 -> pin 14 -> 330 ohm resistor -> LED -> GND
*/

const int BUTTON_PIN = 2;                  // ATmega328P pin 4
const int LED_PIN = 8;                     // ATmega328P pin 14
const unsigned long HALF_PERIOD_MS = 500;  // 0.5 s on, 0.5 s off

// The button pulls the pin to GND, so "pressed" reads LOW.
bool buttonPressed() {
  return digitalRead(BUTTON_PIN) == LOW;
}

// Wait up to `ms` milliseconds while watching the button.
// Returns false right away if the button is released.
bool waitWhilePressed(unsigned long ms) {
  unsigned long start = millis();
  while (millis() - start < ms) {
    if (!buttonPressed()) {
      return false;
    }
    delay(5);
  }
  return true;
}

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  if (!buttonPressed()) {
    digitalWrite(LED_PIN, LOW);            // not pressed: stay off
    return;
  }

  digitalWrite(LED_PIN, HIGH);             // on for 0.5 s ...
  if (!waitWhilePressed(HALF_PERIOD_MS)) {
    digitalWrite(LED_PIN, LOW);            // released: stop immediately
    return;
  }

  digitalWrite(LED_PIN, LOW);              // ... then off for 0.5 s
  waitWhilePressed(HALF_PERIOD_MS);
}
