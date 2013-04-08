#include <Arduino.h>
void setup();
void loop();
#line 1 "src/sketch.ino"
/*
  ANRAV.ino - Main ANRAV Arduino Sketch
 Created by:
 Markus A. R. Kreitzer,
 Kyle V. Owen
 on Apr 5, 2013
 Released under GPL licensing.
 */

// System Includes
#include "Arduino.h"
#include <Wire.h>
#include <Servo.h>

// Local Include
#include "lib/ANRAV.h"

// Initialize Vessel Subsystems, etc.
void setup(){  
  // Initialize the serial port.
  Serial.begin(9600);
  Serial.println("Welcome to ANRAV, SeaVoyager I");
  /* Todo. I would like to get the current GPS date printed.
   	char *datestring = getDateTime();
   	Serial.println(datestring);
   	*/

  // Setup Rudder
  Rudder.attach(rudderpin);	

  // Setup Motor
  pinMode(motorpin, OUTPUT);   // Sets up the motor pin as PWM.

  // PID Stuff
  int Input 	 = getCurrentBearing();
  char Setpoint = 90; // 90 degrees (center the rudder)
  // Turn PID Controller ON
  myPID.SetMode(AUTOMATIC);

  // 0 System has failures, 1 System is ready.
  /*	boolean status = systemStatus(); 
   	if(status == 0){
   	  	// We have a failure
   	  	Serial.println("System failed to start up");
   	}else{
   		Serial.println("All systems go!");
   		// Do nothing for now...
   	}  	
   */
}

void loop()
{
  // Start-up Meta-Rules
  if (Serial.available())
  {

  }
	// Navigation
   	if( goalReached() == 0 ){
   		// Circle
   		circlePattern();
   	}else{
   		// Steer towards goal
   		Input = getCurrentBearing();
   	Setpoint = calcDestBearing();
   	gap = getShortAngle((int) Input,(int) Setpoint);
   		if(gap < 20){
   			// If vessel has to compensate with a small angle.
   		myPID.SetTunings(consKp, consKi, consKd);
   		}else{
   			// If vessel is has to compensate with a large angle.
   		myPID.SetTunings(aggKp, aggKi, aggKd);
   	}
   myPID.Compute();
   Rudder.write(convertRudder(Output));
   }
   	// Communication

}
