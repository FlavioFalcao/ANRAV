#include <Servo.h>
#include <Wire.h>
#include <PID_v1.h>

//#include "../lib/ANRAV.h"

double Setpoint, Input, Output;
double aggKp=4, aggKi=0.2, aggKd=1;
double consKp=1, consKi=0.05, consKd=0.25;
PID myPID(&Input, &Output, &Setpoint, consKp, consKi, consKd, DIRECT);

void setup()
{	
	Servo Rudder
	Rudder.attach(rudderpin);
	Input = 10;
	Setpoint = 100;	
	myPID.SetMode(AUTOMATIC);

}

void loop()
{
	myPID.Compute();
}
