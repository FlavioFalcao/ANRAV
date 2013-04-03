// Includes
include "ANRAV.h"
// Defines

// Globals
// Interrupt for incoming Serial data:
int InterruptPin = 13;
volatile int state = LOW;


void ManualOverride()
{
  // Function for Sarah to check if we should go into Manual Operation.
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
	char *datestring = getDateTime();
	Serial.println(datestring);
	Wire.begin(); // Start the I2C interface.

	// Setup Rudder

	// PID Stuff
	Input 	 = getCurrentBearing();
	Setpoint = 90; // 90 degrees (center the rudder)

	// Turn the PID on
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
	// Startup Meta-Rules

	// Navigation
	if( goalReached() == 1 ){
		// Circle
		circlePattern();
	}else{
		// Steer towards goal
		Input = getCurrentBearing();

		if(gap < 45)
		{  //we're close to setpoint, use conservative tuning parameters
    		myPID.SetTunings(consKp, consKi, consKd);
  		}
	    else
   		{
    		//we're far from setpoint, use aggressive tuning parameters
     		myPID.SetTunings(aggKp, aggKi, aggKd);
     	}
  }


	}


	// Communication

}






























