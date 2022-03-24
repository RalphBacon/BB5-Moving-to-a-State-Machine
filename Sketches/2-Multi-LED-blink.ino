/* 
	The classic BLINK sketch expanded for two LEDs
	but which causes problems due to the suboptimal
	sequential coding method.
*/

#include <Arduino.h>

// Define the pins our LEDs are connected to
#define redLED 10
#define grnLED 8

// Setup
void setup() {
    // Start debugging output
    Serial.begin(115200);

    // LED pins are OUTPUT pins
    pinMode(redLED, OUTPUT);
    pinMode(grnLED, OUTPUT);

    // But set them off (LOW) initially
    digitalWrite(grnLED, LOW);
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
	

    // Now the green LED
    digitalWrite(grnLED, HIGH);
	
    // Wait a bit
    delay(200);

    // Turn it off
    digitalWrite(grnLED, LOW);

    // Wait a bit
    delay(200);
}