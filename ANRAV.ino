// Includes
include "ANRAV.h"

// Globals

void ManualOverride()
{

  /* 
  Functions needed:
  h - print all available commands
  s [name] [parameter] - sets a parameter
  g [name] - displays a parameter
  n - navigation mode allows for steering the vessel via the cmd line.

  ...
  */


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
	if( goalReached() == 1 ){
		// Circle
		circlePattern();
	}else{
		// Steer towards goal
		Input = getCurrentBearing();
     	Setpoint = calcDestBearing();
     	gap = calcGap(Input,Setpoint);
		if(gap < 20){
			// If SeaVoyager is has to compensate with a small angle.
    		myPID.SetTunings(consKp, consKi, consKd);
  		}else{
			// If SeaVoyager is has to compensate with a large angle.
     		myPID.SetTunings(aggKp, aggKi, aggKd);
     	}
     myPID.Compute();
  }
	// Communication


}





























