/* Scintillator Totalizer Tester
 * Senior Design Spring '13
 * Kyle Owen
 * 2/22/2013
 */

#include <Wire.h>
#include "I2C_Anything.h"

#define MASTER_ADDR 17

#define TOTALIZER_ADDR 7
#define MESSAGE_LENGTH 4

#define INITIALIZE 0
#define READ 1
#define DESTRUCTIVE_READ 2
#define UNDEFINED -1

union
{
  volatile unsigned long data;
  volatile byte buffer[4];
} count;

void setup()
{
  Wire.begin(MASTER_ADDR);
  Serial.begin(9600);
  count.data = 0;
  Serial.println("Geiger counter test begin");
  Serial.println(count.data);
}

void loop()
{
  changeMode(INITIALIZE);
  getData();
  Serial.println(count.data);
  delay(1000);
  changeMode(READ);
  while (true)
  {
    getData();
    Serial.println(count.data);
    delay(1000);
  }
  /*
  Serial.println("Initializing");
   changeMode(INITIALIZE);
   Serial.println("Change mode: read");
   changeMode(READ);
   Serial.println("Request from totalizer");
   Wire.requestFrom(TOTALIZER_ADDR, MESSAGE_LENGTH);
   while(Wire.available())
   {
   Serial.println((char) Wire.read());
   }
   delay(1000);
   */
}

void getData()
{
  Wire.requestFrom(TOTALIZER_ADDR, MESSAGE_LENGTH);
  while(Wire.available() < MESSAGE_LENGTH);
  Serial.println(I2C_readAnything(count.data));
}

void changeMode(byte mode)
{
  Wire.beginTransmission(TOTALIZER_ADDR);
  Wire.write(mode);
  Wire.endTransmission();
}

