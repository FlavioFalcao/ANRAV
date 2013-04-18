/* Scintillator Totalizer
 * Senior Design Spring '13
 * Kyle Owen
 * 2/22/2013
 */
 
#include <Wire.h>
#include "I2C_Anything.h"

#define MASTER_ADDR 17

#define TOTALIZER_ADDR 7

#define INITIALIZE 0
#define READ 1
#define DESTRUCTIVE_READ 2
#define UNDEFINED -1

volatile int command = UNDEFINED;

union
{
  volatile unsigned long data;
  volatile byte buffer[4];
} count;

union
{
  volatile unsigned long data;
  volatile byte buffer[4];
} old_count;

void setup()
{
  Wire.begin(TOTALIZER_ADDR);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  Serial.begin(9600);
  attachInterrupt(1, event, RISING);
}

void event()
{
  count.data++;
}

void loop()
{
  
  Serial.println(count.data);
  delay(1000);
  
}

void requestEvent()
{
  switch(command)
  {
    case INITIALIZE:
      count.data = 0;
      old_count.data = 0;
      break;
    case READ:
      old_count.data = count.data;
      break;
    case DESTRUCTIVE_READ:
      old_count.data = count.data;
      count.data = 0;
      break;
    default:
      old_count.data = UNDEFINED;
      break;
  }
  /*for (int i = 0; i < 4; i++)
  {
    Wire.write(old_count.buffer[i]);
    Serial.print(old_count.buffer[i]);
    Serial.print(" ");
  }*/
  I2C_writeAnything(old_count.data);
  //Serial.println();
  //Serial.println(old_count.data);
}

void receiveEvent(int howMany)
{
  while(Wire.available())
  {
    command = Wire.read();
    Serial.println("Mode changed");
    Serial.println(command);
  }
}
