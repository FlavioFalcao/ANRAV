#include "shell.h"

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

char getByte()
{
	while (!Serial.available());
	return Serial.read();
}

long getLong()
{
  long constructedLong = 0;
  char negate = 1;
  unsigned char byteRead;
  boolean stillDigit = true;
  while (!Serial.available());
  if (Serial.peek() == '-')
  {
    Serial.read();
    negate = -1;
  }
  while (stillDigit)
  {
    while (!Serial.available());
    byteRead = Serial.peek();
    if (isdigit(byteRead))
    {
      Serial.read();
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
				break;
			case 's': //set
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
			case 'g': //get
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
			case 'q': //quit
				quit = true;
				break;
			default:
				break;
		}
	}
}
