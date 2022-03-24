/*
	A first step towards a State Machine with this
	multi-tasking, 2-LED blink program that allows
	two functions to run without interfering with
	each other.
*/

#include <Arduino.h>

// Two LEDs on GPIO pins
#define redLED 10
#define grnLED 8

// Arduino IDE does not require the next two lines
// that "forward declares" all functions we use in
// the sketch. But good practice, nonetheless.
void blinkRedLed();
void blinkGrnLed();

// Simple setup function
void setup() {
    Serial.begin(115200);
	
    pinMode(redLED, OUTPUT);
    pinMode(grnLED, OUTPUT);
    
	digitalWrite(grnLED, LOW);
    digitalWrite(redLED, LOW);
    
	Serial.println("Setup completed");
}

// Very simple and tidy loop that calls two functions
void loop() {
	// See if the RED led needs toggling
    blinkRedLed();

	// See if the GREEN led needs toggling
    blinkGrnLed();
}

// RED led blink
void blinkRedLed() {
	// This unsigned long integer declaration is only 
	// actioned ONCE by the compiler before moving the
	// variable outside of the loop
    static unsigned long redMillis = millis();

	// If enough time has passed (500mS) we toggle the flash
    if (millis() - redMillis > 500) {
		// Set the red LED to whatever it is NOT now
        digitalWrite(redLED, !digitalRead(redLED));
		
		// We must reset the local millis variable
        redMillis = millis();
    }
}

// GREEN led blink - same as above, just runs faster
void blinkGrnLed() {
    static unsigned long grnMillis = millis();

    if (millis() - grnMillis > 100) {
        digitalWrite(grnLED, !digitalRead(grnLED));
        grnMillis = millis();
    }
}
