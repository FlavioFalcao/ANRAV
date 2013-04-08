#include <Arduino.h>
void setup();
void loop();
#line 1 "src/sketch.ino"
#include <Servo.h>
#include <Wire.h>
#include "../lib/ANRAV.h"
void setup()
{
	Rudder.attach(rudderpin);
}

void loop()
{
}
