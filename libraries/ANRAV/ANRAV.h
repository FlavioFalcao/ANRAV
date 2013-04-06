#include <Servo.h> 
#include <AP_GPS.h>
#include <Wire.h>
#include <HMC5883L.h>
#include <Waypoints.h>
#include <PID_v1.h>

#define NULL null //for Arduino to understand both types of NULL

// Set up some system constants:
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
const char rudder_angle = 90;
const char motor_speed  = 50;

// Interrupts
const char InterruptPin = 13;
volatile int state = LOW;

// Basic
boolean systemStatus();
void sendtoBase(char *stringy);
char *getDateTime();

// Navigation
void loadWayPoints();
int getCurrentBearing();
int  calcDestBearing();
int  calcDestDistance();
int  calcSetPoint();
int calcGap();
boolean goalReached();
// Controls
Servo Rudder;  // create servo object to control a servo 
void setMotor(char motor_speed){
	analogWrite(motorpin, motor_speed);
}
void circlePattern(){
	Rudder.write(45);
	delay(15); // waits for the servo to get there 
	setMotor(25);
}

// PID variables
double Setpoint, Input, Output;

//Define the aggressive and conservative Tuning Parameters
double aggKp=4, aggKi=0.2, aggKd=1;
double consKp=1, consKi=0.05, consKd=0.25;

//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint,2,5,1, DIRECT);
