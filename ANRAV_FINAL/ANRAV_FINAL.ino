/*
  ANRAV_FINAL.ino - Library with misc ANRAV code.
 Created by Markus A. R. Kreitzer Apr 5, 2013
 with much thanks to Patrick Berry for teaching
 C++.
 Released under GPL licensing.
 */

// General libs needed
#include <Wire.h>
#include <Servo.h>

// Nav, GPS, Compass
#include <Waypoints.h>
#include <Navigation.h>
#include <GPS_NMEA.h>
#include <HMC5883L.h> // Compass

// Instantiate all teh stuffs.
Navigation nav;
GPS_NMEA_Class gps;
Waypoints wp;
HMC5883L compass;    // Instantiate the compass.

//PID (seems like we wont need any PID)
//#include <PID_v1.h>

// Set up some system constants:
// CONSTANTS
//I2C on the Pro is 4 (SDA) and 5 (SCL).
static const char I2C_SDA  = 4;
static const char I2C_SCL  = 5;

// Current Sensors
static const char current1pin = 6;
static const char current2pin = 7;

// Motors
static const char motorpin  = 9;
static const char rudderpin = 10;

// Temperature Sensors (Must be analog)
static const char temppin1 = 11;
static const char temppin2 = 12;
static const char temppin3 = 13;
static const char geigerpin = 2;
volatile unsigned long counts = 0; // total counts
unsigned long start_time = 0; // start time for measurements in milliseconds
unsigned int measurement_interval = 1000; // measurement interval in milliseconds
volatile int state = LOW;

// Propulsion and Steering
static const char rudder_center = 45;
static const char rudder_left   = 60;
static const char rudder_right  = 30;
unsigned char rudder_angle = rudder_center;

// GLOBAL VARIABLES!
// Propulsion and Steering
static const char motor_speed_day_max   = 212;
static const char motor_speed_night_max = 170;
static const char motor_speed_min       = 0;
unsigned char     motor_speed           = 50;
static const char gap                   = 20;

// Interrupts
// const char InterruptPin = 13;
// volatile int state = LOW;

// PID variables
//double Setpoint, Input, Output;

//Define the aggressive and conservative Default Tuning Parameters
// Aggresive
//double aggKp=4;
//double aggKi=0.2;
//double aggKd=1;

// Conservative
//double consKp=1;
//double consKi=0.05;
//double consKd=0.25;

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
float  getCurrentBearing();
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
//PID myPID(&Input, &Output, &Setpoint,consKp,consKi,consKd, DIRECT);

void printwaypoint(Waypoints::WP *wp){
  // USB
  Serial.print("Lattitude: ");
  Serial.print( (*wp).lat );
  Serial.print("\t\nLongitude: ");
  Serial.println( (*wp).lng );	
  // Xbee
  Serial1.print("Lattitude: ");
  Serial1.print( (*wp).lat );
  Serial1.print("\t\nLongitude: ");
  Serial1.println( (*wp).lng );	
}


// Puts the boat into circle mode around the destination.
void circlePattern(){
  Rudder.write(rudder_left);
  delay(15); // waits for the servo to get there 
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

int setupCompass(){
  int error = 0;

  // Serial1.println("Starting the I2C interface.");
  Wire.begin(); // Start the I2C interface.

  // Serial1.println("Constructing new HMC5883L");
  compass = HMC5883L(); // Construct a new HMC5883 compass.

  // Serial1.println("Setting scale to +/- 1.3 Ga");
  error = compass.SetScale(1.3); // Set the scale of the compass.

  if(error != 0){
    // If there is an error, print it out.
    Serial1.println(compass.GetErrorText(error));
    return 1;
  }

  // Serial1.println("Setting measurement mode to continous.");
  error = compass.SetMeasurementMode(Measurement_Continuous); // Set the measurement mode to Continuous
  if(error != 0){
    // If there is an error, print it out.
    Serial1.println(compass.GetErrorText(error));
    return 1;
  } 
  return 0;
}

float  getCurrentBearing(){
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
  float declinationAngle = 0.06702; // Auburn
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
  //
  return 0;
}
int  calcDestDistance(){
  //
  return 0;
}

int  calcSetPoint(){
  return 0;
}

// Returns true if goal is reached, false if not there yet.
bool goalReached(){
  if( nav.distance < goal_thres ){
    return true;
  }
  else{
    return false;
  }
}
char convertRudder(){
  return 0;
}

char getByte()
{
  while (!Serial1.available());
  return Serial1.read();
}

long getLong()
{
  long constructedLong = 0;
  char negate = 1;
  unsigned char byteRead;
  boolean stillDigit = true;
  while (!Serial1.available());
  if (Serial1.peek() == '-')
  {
    Serial1.read();
    negate = -1;
  }
  while (stillDigit)
  {
    while (!Serial1.available());
    byteRead = Serial1.peek();
    if (isdigit(byteRead))
    {
      Serial1.read();
      constructedLong *= 10;
      constructedLong += (byteRead - '0');
    }
    else
    {
      stillDigit = false;
    }
  }
  return constructedLong * negate;
}

void increaseSpeed()
{
  if (motor_speed != 255)
  {
    motor_speed++;
    setMotor(motor_speed);
  }
  Serial1.print("motor_speed = ");
  Serial1.println(motor_speed);
}
void decreaseSpeed()
{
  if (motor_speed != 0)
  {
    motor_speed--;
    setMotor(motor_speed);
  }
  Serial1.print("motor_speed = ");
  Serial1.println(motor_speed);
}
void goLeft()
{
  if (rudder_angle != 0)
  {
    rudder_angle--;
    Rudder.write(rudder_angle);
  }
  Serial1.print("rudder = ");
  Serial1.println(Rudder.read());  	
}
void goRight()
{
  if (rudder_angle != 180)
  {
    rudder_angle++;
    Rudder.write(rudder_angle);
  }
  Serial1.print("rudder = ");
  Serial1.println(Rudder.read());  	
}


void manualLoop()
{
  unsigned char byteRead;
  boolean quit = false;
  while (!quit)
  {
    byteRead = getByte();
    switch (byteRead)
    {
    case 'h': //help
      //print help
      break;
    case 'n': //nav mode
      {
        boolean navMode = true;
        while (navMode)
        {
          byteRead = getByte();
          switch (byteRead)
          {
          case '+':
            increaseSpeed();
            break;
          case '0':
            setMotor(0);
            break;
          case 'f':
            setMotor(255);
            break; 
          case '-':
            decreaseSpeed();
            break;
          case 'l':
            goLeft();
            break;
          case 'r':
            goRight();
            break;
          case 'x': //exit nav mode
            navMode = false;
            break;
          }
        }
      }
      break;
    case 's': //set
      {
        byteRead = getByte();
        switch (byteRead)
        {
        case 'w': //waypoint
          int32_t lattitude, longitude;
          lattitude = getLong();
          longitude = getLong();
          //Waypoints::WP newWP = { 0, 0, latitude * T7, longitude * T7, 5000 };
          Waypoints::WP newWP;
          newWP.lng = longitude*T7;
          newWP.lat = lattitude*T7;
          nav.set_new_destination(newWP);
          break;
        default:
          // Nothing
          break;
        }
      }
      break;
    case 'g': //get
      {
        byteRead = getByte();
        switch (byteRead)
        {
        case 'w': //waypoint
          printwaypoint( &(nav.next_wp) );
          Serial1.print("Lattitude: ");
          Serial1.println(nav.next_wp.lat);
          Serial1.print("Longitude: ");
          Serial1.println(nav.next_wp.lng);
          break;
        default:
          break;
        }
      }
      break;
    case 'q': //quit
      quit = true;
      break;
    default:
      break;
    }
  }
}

void rad_event()
{
  counts++;
}

void intializeCount() // zero out counts and set start_time to seconds since power on or reset
{
  counts = 0;
  start_time = millis(); // start time in millis
}

float getRate() // return current rate in counts per second and zero out measurments
{
  float rate = (float) counts / (millis() - start_time) / 1000; // counts per second
  intializeCount();
  return rate;
}


void setup() {                
  // Nothing
  Serial.begin(9600);   // USB
  Serial1.begin(9600);  // Xbee
  Serial2.begin(9600);  // GPS
  setupCompass();
  Serial.println("Welcome to ANRAV, SeaVoyager I");
  Serial1.println("Welcome to ANRAV, SeaVoyager I");
  Rudder.attach(rudderpin);
  attachInterrupt(0, rad_event, RISING); // attach interrupt for Geiger counter
  intializeCount();	
  delay(1000);

  // From Google Maps:
  // Magnolia (across Chick-Fil-A
  // 32.606373,-85.486306
  //  Waypoints::WP Magnolia = {
  //    0, 0, 32.606373 * T7, -85.486306 * T7, 5000                                  };
  //  // Broun Hall
  //  // 32.604901,-85.486373
  //  Waypoints::WP Broun = {
  //    0, 0, 32.604901 * T7, -85.486373 * T7, 5000                                  };
  Waypoints::WP Magnolia;
  Magnolia.lat = 32.606373*T7;
  Magnolia.lng = -85.486306 * T7;
  Waypoints::WP Broun;
  Broun.lat = 32.606373*T7;
  Broun.lng = -85.486306 * T7;
  //
  wp.set_total(3);
  wp.set_index(1);
  Serial1.print("Total: ");
  Serial1.println(wp.get_total());
  //Serial1.print("Current Index!: ");
  //Serial1.println(wp.get_index());
  wp.set_waypoint_with_index(Broun,0);
  wp.set_waypoint_with_index(Magnolia,1);

  nav.set_wp(&wp);
  nav.load_home();
  nav.load_first_wp();
  Serial1.print("Total After nav: ");
  Serial1.println(wp.get_total());
  Serial1.print("Current Index After nav: ");
  Serial1.println(wp.get_index());
}

void loop()
{
  if( Serial.available())
  {
    manualLoop();
    Serial1.println("I've exited the manual loop and will restart in 1 second.");
  }
  if (millis() - start_time > measurement_interval)
  {
    Serial1.print("Counts per minute: ");
    Serial1.println(getRate());
  }
  gps.Read();
  if (gps.NewData)  // New GPS data?
  {
    nav.update_gps(gps.Altitude,gps.Longitude,gps.Lattitude,gps.Ground_Course);
    long distance_gps = nav.distance;
    long bearing_gps = nav.bearing;
    // Print Debug Info:
    // Goes to USB
    Serial.println("GPS Debug Data:");
    Serial.print("Number of Sattelites: ");
    Serial.println(gps.NumSats);
    Serial.print("GPS Signal Quality:");
    Serial.println(gps.Quality);
    Serial.print("GPS Fix:");
    Serial.println(gps.Fix);   
    Serial.print(" Time:");
    Serial.print(gps.Time);
    Serial.print(" Fix:");
    Serial.print((int)gps.Fix);
    Serial.print(" Lat:");
    Serial.print(gps.Lattitude);
    Serial.print(" Lon:");
    Serial.print(gps.Longitude);
    Serial.print(" Alt:");
    Serial.print(gps.Altitude/1000.0);
    Serial.print(" Speed:");
    Serial.print(gps.Ground_Speed/100.0);
    Serial.print(" Course:");
    Serial.print(gps.Ground_Course/100.0);
    Serial.print(" Compass Heading: ");
    Serial.println(getCurrentBearing());
    //
    //Goes to Xbee
    Serial1.println("GPS Debug Data:");
    Serial1.print("Number of Sattelites: ");
    Serial1.println(gps.NumSats);
    Serial1.print("GPS Signal Quality:");
    Serial1.println(gps.Quality);
    Serial1.print(" Time:");
    Serial1.print(gps.Time);
    Serial1.print(" Fix:");
    Serial1.print((int)gps.Fix);
    Serial1.print(" Lat:");
    Serial1.print(gps.Lattitude);
    Serial1.print(" Lon:");
    Serial1.print(gps.Longitude);
    Serial1.print(" Alt:");
    Serial1.print(gps.Altitude/1000.0);
    Serial1.print(" Speed:");
    Serial1.print(gps.Ground_Speed/100.0);
    Serial1.print(" Course:");
    Serial1.print(gps.Ground_Course/100.0);
    Serial1.print(" Compass Heading: ");
    Serial1.println(getCurrentBearing());
    Serial1.println();
    //
    Serial.println("Next Destination:");
    Serial1.println("Next Destination:");
    printwaypoint( &(nav.next_wp) );
    Serial.print("Distance = ");
    Serial.println(distance_gps,DEC);  
    Serial.print(" Bearing = ");
    Serial.println(bearing_gps, DEC);
    Serial.println();
    Serial.println("\n\n\n");
    //
    Serial1.print("Distance = ");
    Serial1.println(distance_gps,DEC);  
    Serial1.print(" Bearing = ");
    Serial1.println(bearing_gps, DEC);
    Serial1.println("\n\n\n");
    gps.NewData = 0;
    delay(1000);
  }
}
    //    if( gps.Fix != 0){
    //      Serial.println("No GPS Fix.");
    //      Serial1.println("No GPS Fix.");
    //    }
    // Navigation Code

    //    Serial1.print("Current Destination Index: ");
    //    Serial1.print(nav.get_current_wp_index());
    //    Serial1.print(",");
    //    Serial1.print(wp.get_index());
    //    Serial1.print("\n");



















