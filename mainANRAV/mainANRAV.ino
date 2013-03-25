// Includes

// Defines

// Function Prototypes (needs to be moved to header file?)
// Basic
boolean systemStatus();
void sendtoBase(char *stringy);
char *getDateTime();

// Navigation
void loadWayPoints();
int  getCurrentBearing();
int  calcDestBearing();
int  calcDestDistance();
boolean goalReached();
void circlePattern();
// Controls
void getKs();
void setRudder();
void circlePattern();

// Interrupt for incoming Serial data:
int InterruptPin = 13;
volatile int state = LOW;

void setup()
{

}

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

  // Load navigation points, check GPS, etc.
  loadWPTS();
  boolean status = systemStatus(); // 0 System has failures, 1 System is ready.
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
	}
	// Communication

	// Blah
}


