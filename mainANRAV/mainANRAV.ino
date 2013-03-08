void setup()
{
  initialize();
  // Initialize the serial port.
  Serial.begin(9600);
  Serial.println("Starting the I2C interface.");
  Wire.begin(); // Start the I2C interface.
}

void loop()
{
}
