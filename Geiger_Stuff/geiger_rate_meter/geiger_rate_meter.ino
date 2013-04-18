/* Geiger Counter Rate Meter
 * Kyle Owen
 * 4/17/2013
 */
 

unsigned long start_time = 0;
unsigned long count = 0;


void event()
{
  count++;
}

float getRate() // cpm
{
  return (float) count / ((millis() - start_time) / 60000);
}

void initializeCount()
{
  count = 0;
  start_time = millis();
}

void setup()
{
  Serial.begin(9600);
  attachInterrupt(1, event, RISING);
  initializeCount();
}

void loop()
{
  if ((millis() / 1000) % 60 == 0)
  {
    Serial.print("Counts per minute: ");
    Serial.println(getRate());
    initializeCount();
  }
}
