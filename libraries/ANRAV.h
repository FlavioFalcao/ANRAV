#include <AP_GPS.h>
#include <Wire.h>
#include <HMC5883L.h>
#include <Waypoints.h>
#include <AP_PID.h>

// Basic
boolean systemStatus();
void sendtoBase(char *stringy);
char *getDateTime();

// Navigation
void loadWayPoints();
int  getCurrentBearing();
int  calcDestBearing();
int  calcDestDistance();
int  calcSetPoint();
boolean goalReached();
void circlePattern();

// Controls
void getKs();
void setRudder();
void circlePattern();

// PID variables
double Setpoint, Input, Output;

//Define the aggressive and conservative Tuning Parameters
double aggKp=4, aggKi=0.2, aggKd=1;
double consKp=1, consKi=0.05, consKd=0.25;

//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint,2,5,1, DIRECT);
