#include <Arduino.h>

// Define the pins our LED is connected to
#define redLED 10

// Setup
void setup() {
    // Start debugging output
    Serial.begin(115200);

    // LED pins are OUTPUT pins
    pinMode(redLED, OUTPUT);

    // But set them off (LOW) initially
    digitalWrite(redLED, LOW);

    // All done
    Serial.println("Setup completed");
}

// Main loop
void loop() {
    // Start the red LED going
    digitalWrite(redLED, HIGH);

    // Wait a bit
    delay(500);

    // Turn it off
    digitalWrite(redLED, LOW);

    // Wait a bit
    delay(500);
}