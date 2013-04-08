#include "Arduino.h"
#include "Servo.h"

const char motorpin = 9;
const char rudderpin = 10;

void setup(){
	// Blah
	Servo Rudder;
	Rudder.attach(rudderpin);
}

void loop(){

}
