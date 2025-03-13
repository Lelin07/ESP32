#include <Arduino.h>

#define LED_BUILTIN 2 // Define the built-in LED pin for ESP32
#define BUZZER_PIN 25 // Define the buzzer pin for ESP32

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize digital pin BUZZER_PIN as an output.
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  // turn the buzzer on
  digitalWrite(BUZZER_PIN, HIGH);
  // wait for a second
  delay(200);
  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
  // turn the buzzer off
  digitalWrite(BUZZER_PIN, LOW);
  // wait for a second
  delay(3000);
}
