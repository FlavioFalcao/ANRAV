/*
  Example of GPS UBLOX library.
  Code by Jordi Mu�oz and Jose Julio. DIYDrones.com

  Works with Ardupilot Mega Hardware (GPS on Serial Port1)
  and with standard ATMega168 and ATMega328 on Serial Port 0
*/

//#include <GPS_UBLOX.h> // UBLOX GPS Library
#include "/Users/markuskreitzer/Documents/Arduino/libraries/GPS_UBLOX/GPS_UBLOX.h"
void setup()
{
  Serial.begin(9600);
  Serial.println("GPS UBLOX library test");
  GPS.Init();   // GPS Initialization
  Serial.println("Past INIT");
  delay(1000);
}
void loop()
{
  Serial.println("About to read()");
  GPS.Read();
  Serial.println("I just read");
  if (GPS.NewData)  // New GPS data?
    {
    Serial.print("GPS:");
    Serial.print(" Time:");
    Serial.print(GPS.Time);
    Serial.print(" Fix:");
    Serial.print((int)GPS.Fix);
    Serial.print(" Lat:");
    Serial.print(GPS.Lattitude);
    Serial.print(" Lon:");
    Serial.print(GPS.Longitude);
    Serial.print(" Alt:");
    Serial.print(GPS.Altitude/1000.0);
    Serial.print(" Speed:");
    Serial.print(GPS.Ground_Speed/100.0);
    Serial.print(" Course:");
    Serial.print(GPS.Ground_Course/100000.0);
    Serial.println();
    GPS.NewData = 0; // We have readed the data
    }else{
      Serial.println("Aint got shit...");
    }
  delay(1000);
}
