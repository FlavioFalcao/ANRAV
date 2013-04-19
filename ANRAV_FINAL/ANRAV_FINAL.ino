#include <AP_GPS.h>
#include <AP_GPS_406.h>
#include <AP_GPS_Auto.h>
#include <AP_GPS_HIL.h>
#include <AP_GPS_IMU.h>
#include <AP_GPS_MTK.h>
#include <AP_GPS_MTK16.h>
#include <AP_GPS_MTK_Common.h>
#include <AP_GPS_NMEA.h>
#include <AP_GPS_None.h>
#include <AP_GPS_Shim.h>
#include <AP_GPS_SIRF.h>
#include <AP_GPS_UBLOX.h>
#include <GPS.h>
#include <Navigation.h>
#include <Wire.h>
#include <Servo.h>
#include <EEPROM.h>
#include <HMC5883L.h>
#include <PID_v1.h>
#include <Waypoints.h>

/*
  ANRAV.ino - Library with misc ANRAV code.
 Created by Markus A. R. Kreitzer Apr 5, 2013
 Released under GPL licensing.
 */

// Set up some system constants:
// CONSTANTS
//I2C on the Pro is 4 (SDA) and 5 (SCL).
static const char I2C_SDA  = 4;
static const char I2C_SCL  = 5;

// Current Sensors
static const char current1pin = 6;
static const char current2pin = 7;

// Motors
static const char motorpin = 9;
static const char rudderpin = 10;

// Temperature Sensors (Must be analog)
static const char temppin1 = 11;
static const char temppin2 = 12;
static const char temppin3 = 13;

// Propulsion and Steering
unsigned char rudder_angle = 90;
unsigned char motor_speed  = 50;
int           gap          = 0;

// GLOBAL VARIABLES!
// Interrupts
const char InterruptPin = 13;
volatile int state = LOW;

// PID variables
double Setpoint, Input, Output;

//Define the aggressive and conservative Default Tuning Parameters
// Aggresive
double aggKp=4;
double aggKi=0.2;
double aggKd=1;

// Conservative
double consKp=1;
double consKi=0.05;
double consKd=0.25;

// Navigation
int goal_thres = 10; // 10 meters
//HMC5883L compass;
HMC5883L compass;

// FUNCTION PROTOTYPES
// Basic
boolean systemStatus();
void sendtoBase(char *stringy);
char *getDateTime();

// Navigation
void loadWayPoint();
void storeWayPoint();
int  getCurrentBearing();
int  calcDestBearing();
int  calcDestDistance();
int  calcSetPoint();
int  calcGap();
int  getShortAngle(int a1, int a2);
bool goalReached();

// Controls
Servo Rudder;  // create servo object to control a servo 
void setMotor(char motor_speed);
void circlePattern();
char convertRudder();

// OBJECT INSTANTIATION. 
//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint,consKp,consKi,consKd, DIRECT);


// Puts the boat into circle mode around the destination.
void circlePattern(){
  Rudder.write(45);
  delay(15); // waits for the servo to get there 
  setMotor(25);
}

// Sets the PWM duty cycle.
void setMotor(char motor_speed){
  analogWrite(motorpin, motor_speed);
}

// Gets two angles and returns the smallest angle.
int getShortAngle(int a1, int a2){
  int angle = (abs(a1 - a2)) % 360;
  if(angle > 180){
    angle = 360 - angle;
  }
  return angle;
}

// Navigation
void storeWayPoint(){

}
void loadWayPoint(){

}
int setupCompass(){
  int error = 0;
  // Initialize the serial port.
  // Serial.begin(9600);

  // Serial.println("Starting the I2C interface.");
  // Wire.begin(); // Start the I2C interface.

  // Serial.println("Constructing new HMC5883L");
  compass = HMC5883L(); // Construct a new HMC5883 compass.

  // Serial.println("Setting scale to +/- 1.3 Ga");
  error = compass.SetScale(1.3); // Set the scale of the compass.

  if(error != 0){
    // If there is an error, print it out.
    Serial.println(compass.GetErrorText(error));
    return 1;
  }

  // Serial.println("Setting measurement mode to continous.");
  error = compass.SetMeasurementMode(Measurement_Continuous); // Set the measurement mode to Continuous
  if(error != 0){
    // If there is an error, print it out.
    Serial.println(compass.GetErrorText(error));
    return 1;
  } 
  return 0;
}

int  getCurrentBearing(){
  // Retrive the raw values from the compass (not scaled).
  MagnetometerRaw raw = compass.ReadRawAxis();
  // Retrived the scaled values from the compass (scaled to the configured scale).
  MagnetometerScaled scaled = compass.ReadScaledAxis();

  // Values are accessed like so:
  int MilliGauss_OnThe_XAxis = scaled.XAxis;// (or YAxis, or ZAxis)

  // Calculate heading when the magnetometer is level, then correct for signs of axis.
  float heading = atan2(scaled.YAxis, scaled.XAxis);

  // Once you have your heading, you must then add your 'Declination Angle', which is the 'Error' of the magnetic field in your location.
  // Find yours here: http://www.magnetic-declination.com/
  // Mine is: 2 37' W, which is 2.617 Degrees, or (which we need) 0.0456752665 radians, I will use 0.0457
  // If you cannot find your Declination, comment out these two lines, your compass will be slightly off.
  float declinationAngle = 0.06702;
  heading += declinationAngle;

  // Correct for when signs are reversed.
  if(heading < 0)
    heading += 2*PI;

  // Check for wrap due to addition of declination.
  if(heading > 2*PI)
    heading -= 2*PI;

  // Convert radians to degrees for readability.
  float headingDegrees = heading * 180/M_PI; 

  // Output the data via the serial port.
  //Output(raw, scaled, heading, headingDegrees);
  return headingDegrees;
  // Normally we would delay the application by 66ms to allow the loop
  // to run at 15Hz (default bandwidth for the HMC5883L).
  // However since we have a long serial out (104ms at 9600) we will let
  // it run at its natural speed.
  // delay(66);
}

int  calcDestBearing(){
  return 0;
}
int  calcDestDistance(){
  return 0;
}
int  calcSetPoint(){
  return 0;
}

// Returns 0 if goal is reached, 1 if not there yet.
bool goalReached(){
  return true;

}
char convertRudder(){
  return 0;
}


void setup() {                
  // Nothing
}

void loop() {
  // Nothing
  Waypoints::WP	location_A = { 0, 0, 38.579633 * T7, -122.566265 * T7, 10000 };
  Waypoints::WP	location_B = { 0, 0, 38.578743 * T7, -122.572782 * T7, 5000  };
  long distance = nav.get_distance(&location_A, &location_B);
  long bearing 	= nav.get_bearing(&location_A, &location_B);
  Serial.print("\tDistance = ");
  Serial.print(distance, DEC);	
  Serial.print(" Bearing = ");
  Serial.println(bearing, DEC);
}

