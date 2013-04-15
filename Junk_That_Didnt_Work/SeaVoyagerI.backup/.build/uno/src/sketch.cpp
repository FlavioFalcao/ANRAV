#include <Arduino.h>
void setup();
void loop();
#line 1 "src/sketch.ino"
#include <Servo.h>
#include <Wire.h>
#include "../lib/PID_v1.h"

//#include "../lib/ANRAV.h"

double Setpoint, Input, Output;
double aggKp=4, aggKi=0.2, aggKd=1;
double consKp=1, consKi=0.05, consKd=0.25;
PID* myPID; 

int rudderpin = 10;
int motorpin  = 9;

Servo Rudder;

void setup()
{	
	Rudder.attach(rudderpin);
	Input = 10;
	Setpoint = 100;	
	myPID = new PID(&Input, &Output, &Setpoint, consKp, consKi, consKd, DIRECT);
	myPID->SetMode(AUTOMATIC);

}

void loop()
{
	Rudder.write(10);
	myPID->Compute();
}
