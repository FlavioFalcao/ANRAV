/*
  ANRAV.h - Library with misc ANRAV code.
  Created by Markus A. R. Kreitzer Apr 5, 2013
  Released under GPL licensing.
*/

#ifndef ANRAV_h 
#define ANRAV_h

#include "Arduino.h"
#include <Servo.h>
#include <HMC5883L.h>
// #include "Waypoints.h"
#include <PID_v1.h>
#include <SHELL.h>

// #define NULL null //for Arduino to understand both types of NULL

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
const unsigned char rudder_angle = 90;
const unsigned char motor_speed  = 50;


// GLOBAL VARIABLES!
// Interrupts
const char InterruptPin = 13;
volatile int state = LOW;

// Navigation
int goal_thres = 10; // 10 meters

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

// OBJECT INSTANTIATION. 
//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint,consKp,consKi,consKd, DIRECT);

#endif
