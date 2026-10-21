/*
  ECE 1895 - Assignment 9: Hello World
  Part 2: Three Light Blink
  Chuxuan Zhou

  Behavior: while the push button is held down, three LEDs take turns
  (D8 -> D7 -> D6), each on for 0.5 s with a 0.5 s gap.
  If the button is released in the middle of a cycle, the cycle is
  finished first; then all LEDs stay off until the button is pressed
  again.

  Standalone ATmega328P, 16 MHz crystal, programmed as "Arduino Uno"
  with a USBtinyISP (Sketch > Upload Using Programmer).

  Wiring (Arduino pin -> ATmega328P physical pin):
    Button     : D2 -> pin 4, other side of the button to GND
                 (uses the internal pull-up, so pressed = LOW)
    LED 1      : D8 -> pin 14 -> 330 ohm resistor -> LED -> GND
    LED 2      : D7 -> pin 13 -> 330 ohm resistor -> LED -> GND
    LED 3      : D6 -> pin 12 -> 330 ohm resistor -> LED -> GND
*/

const int BUTTON_PIN = 2;                 // ATmega328P pin 4
const int NUM_LEDS = 3;
const int LED_PINS[NUM_LEDS] = {8, 7, 6}; // lit in this order: pin 14, pin 13, pin 12
const unsigned long ON_MS = 500;          // each LED stays on 0.5 s
const unsigned long GAP_MS = 500;         // all off for 0.5 s between LEDs

// The button pulls the pin to GND, so "pressed" reads LOW.
// A second read 20 ms later ignores contact bounce.
bool buttonPressed() {
  if (digitalRead(BUTTON_PIN) == HIGH) {
    return false;
  }
  delay(20);
  return digitalRead(BUTTON_PIN) == LOW;
}

void allOff() {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], LOW);
  }
}

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }
  allOff();
}
// Edited by Xiaodong Deng on branch XiaodongD-edit (ECE 1895 Assignment 13: Intro to Git)
void loop() {
  // The button is only checked here, at the start of a cycle.
  // Once a cycle starts it always runs to the end, so releasing the
  // button mid-cycle finishes the current cycle and then stops.
  if (!buttonPressed()) {
    allOff();
    return;
  }

  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], HIGH);
    delay(ON_MS);
    digitalWrite(LED_PINS[i], LOW);
    delay(GAP_MS);
  }
}
