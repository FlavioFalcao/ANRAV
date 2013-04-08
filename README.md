Notes

No function definitions in header files, only function headers
System functional: return 0
System nonfunctional: return some (negative?) integer corresponding to point of failure
Xbee: how do I send a string?
Need to put all long STRINGS into PROGRMEM (program memory) instead of RAM. Trust me.


Markus Notes
The following is the order in which to include stuff.
ANRAV.h
	-> Servo.h
	-> HMC...h
	-> GPS_NMEA.h
	-> Navigation.h
SHELL.h


ANRAV.c
