Notes

No function definitions in header files, only function headers
System functional: return 0
System nonfunctional: return some (negative?) integer corresponding to point of failure
Xbee: how do I send a string?
Need to put all long STRINGS into PROGRMEM (program memory) instead of RAM. Trust me.


Markus Notes

To get all this working, you have to:
1) Have the latest Arduino IDE installed.
2) Clone the ANRAV repository to your computer.
3) Remove the existing Arduino libraries folder from your "~/Documents/Arduino/libraries" path. 
   NB: This path varies between OS.
4) Symlink  the ANRAV libraries folder to the Arduino User libraries folder.
