#include "ANRAV.h"

char getByte();
long getLong();
void manualLoop();
void help();
void set_consKp(long newval);
void set_consKi(long newval);
void set_consKd(long newval);
void set_aggKp(long newval);
void set_aggKi(long newval);
void set_aggKd(long newval);
void set_rudder(long newval);
void set_waypoint(long latitude, long longitude, char cardinalNS, char cardinalEW);
void increaseSpeed();
void decreaseSpeed();
void goLeft();
void goRight();
void get_consKp();
void get_consKi();
void get_consKd();
void get_aggKp();
void get_aggKi();
void get_aggKd();
void get_rudder();
void get_waypoint();
