#include <Servo.h>
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

// Navigation
int goal_thres = 10; // 10 meters
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

void setMotor(char motor_speed);
Servo Rudder;  // create servo object to control a servo 

/* 
 Functions needed:
 h - print all available commands --implement last
 s [name] [parameter] - sets a parameter
 	consKp cp 3 places
 	consKi ci 3 places
 	consKd cd 3 places
 	aggKp ap 3 places
 	aggKi ai 3 places
 	aggKd ad 3 places
 	rudderAngle r 1 place
 	waypointN w[latitude, 8 decimal digits][N/S][longitude, 9 decimal digits][W/E]
 g [name] - displays a parameter
 n - navigation mode allows for steering the vessel via the cmd line.
 q - terminates manual override mode
 
 test string: hscp98863sci123scd13256sap1934sai5927sad125850sr985sw12345678N085231234W
 */

void help()
{
  Serial1.println("help");
}
void set_consKp(long newval)
{
  consKp = newval / 1000;
  Serial1.print("consKp = ");
  Serial1.println(consKp);
}
void set_consKi(long newval)
{
  consKi = newval / 1000;
  Serial1.print("consKi = ");
  Serial1.println(consKi);
}
void set_consKd(long newval)
{
  consKd = newval / 1000;
  Serial1.print("consKd = ");
  Serial1.println(consKd);
}
void set_aggKp(long newval)
{
  aggKp = newval / 1000;
  Serial1.print("aggKp = ");
  Serial1.println(aggKp);
}
void set_aggKi(long newval)
{
  aggKi = newval / 1000;
  Serial1.print("aggKi = ");
  Serial1.println(aggKi);
}
void set_aggKd(long newval)
{
  aggKd = newval / 1000;
  Serial1.print("aggKd = ");
  Serial1.println(aggKd);
}
void set_rudder(long newval)
{
  Rudder.write((char) newval);
  Serial1.print("rudder = ");
  Serial1.println(Rudder.read());
}
void set_waypoint(long latitude, long longitude, char cardinalNS, char cardinalEW)
{
  Serial1.println("set_waypoint");
  Serial1.println(latitude);
  Serial1.println(longitude);
  Serial1.println(cardinalNS);
  Serial1.println(cardinalEW);
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
void get_consKp()
{
  Serial1.println("get_consKp");
}
void get_consKi()
{
  Serial1.println("get_consKi");
}
void get_consKd()
{
  Serial1.println("get_consKd");
}
void get_aggKp()
{
  Serial1.println("get_aggKp");
}
void get_aggKi()
{
  Serial1.println("get_aggKi");
}
void get_aggKd()
{
  Serial1.println("get_aggKd");
}
void get_rudder()
{
  Serial1.println("get_rudder");
}
void get_waypoint()
{
  Serial1.println("get_waypoint");
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
        case 'c': //constant
          byteRead = getByte();
          switch (byteRead)
          {
          case 'p':
            set_consKp(getLong());
            break;
          case 'i':
            set_consKi(getLong());
            break;
          case 'd':
            set_consKd(getLong());
            break;
          default:
            break;
          }
        case 'a': //aggressive
          byteRead = getByte();
          switch (byteRead)
          {
          case 'p':
            set_aggKp(getLong());
            break;
          case 'i':
            set_aggKi(getLong());
            break;
          case 'd':
            set_aggKd(getLong());
            break;
          default:
            break;
          }
        case 'r': //rudder
          set_rudder(getLong());
          break;
        case 'w': //waypoint
          long latitude, longitude;
          char cardinalNS, cardinalEW;
          latitude = getLong();
          cardinalNS = getByte();
          longitude = getLong();
          cardinalEW = getByte();
          set_waypoint(latitude, longitude, cardinalNS, cardinalEW);
          break;
        default:
          break;
        }
      }
      break;
    case 'g': //get
      {
        byteRead = getByte();
        switch (byteRead)
        {
        case 'c': //constant
          byteRead = getByte();
          switch (byteRead)
          {
          case 'p':
            get_consKp();
            break;
          case 'i':
            get_consKi();
            break;
          case 'd':
            get_consKd();
            break;
          default:
            break;
          }
        case 'a': //aggressive
          byteRead = getByte();
          switch (byteRead)
          {
          case 'p':
            get_aggKp();
            break;
          case 'i':
            get_aggKi();
            break;
          case 'd':
            get_aggKd();
            break;
          default:
            break;
          }
        case 'r': //rudder
          get_rudder();
          break;
        case 'w': //waypoint
          get_waypoint();
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


// Initialize Vessel Subsystems, etc.
void setup()
{  
  // Initialize the serial port.
  Serial1.begin(9600);
  Serial1.println("Welcome to ANRAV, SeaVoyager I");
  // Setup Rudder
  Rudder.attach(rudderpin);	

}

void loop()
{
  manualLoop();
  Serial1.println("I've exited the manual loop and will restart in 1 second.");
  delay(1000);
}

// Sets the PWM duty cycle.
void setMotor(char motor_speed){
  analogWrite(motorpin, motor_speed);
}





























