/*
  ANRAV.ino - Main ANRAV Arduino Sketch
  Created by:
  Markus A. R. Kreitzer,
  Kyle V. Owen
  Patrick D. Berry
  on Apr 5, 2013
  Released under GPL licensing.
*/

// Includes
include "ANRAV.h"

// Interrupt Service Routine which triggers when Xbee receives data.
void ManualOverride()
{

  /* 
  Functions needed:
  h - print all available commands --implement last
  s [name] [parameter] - sets a parameter
  	consKp
  	consKi
  	consKd
  	aggKp
  	aggKi
  	aggKd
  	rudderAngle
  	waypointN
  	waypointW
  g [name] - displays a parameter
  n - navigation mode allows for steering the vessel via the cmd line.
  q - terminates manual override mode
  */

  //if you're here, the Arduino has been interrupted into manual control
  //switch to manual control...does a PID controller need to know this?
  return 0;

  switch(manualCommand[0])
  {
  	case 'q': //exit manual override

  		break;
  	case 'h': //print help via wireless
  		//how do print via Xbee?
  		break;
  	case 's':
  		break;

  }

}

// Initialize Vessel Subsystems, etc.
void setup()
{  
	// The following instructions interrupts the micro when new data comes in.
	pinMode(InterruptPin, OUTPUT);
	attachInterrupt(0, ManualOverride, CHANGE);

	// Initialize the serial port.
	Serial.begin(9600);
	Serial.println("Welcome to ANRAV, SeaVoyager I");
	/* Todo. I would like to get the current GPS date printed.
	char *datestring = getDateTime();
	Serial.println(datestring);
	*/
	Wire.begin(); // Start the I2C interface.

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
	boolean status = systemStatus(); 
	if(status == 0){
	  	// We have a failure
	  	sendtoBase("System failed to start up");
	}else{
		Serial.println("All systems go!");
  		// Do nothing for now...
	}  	
}

void loop()
{
	// Start-up Meta-Rules

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
























