#include <ANRAV.h>

// Puts the boat into circle mode around the destination.
void circlePattern(){
	Rudder.write(45);
	delay(15); // waits for the servo to get there 
	setMotor(25);
}

// Sets the PWM duty cycle.
void setMotor(char motor_speed){
	analogWrite(motorpin, motor_speed);
}

// Gets two angles and returns the smallest angle.
int getShortAngle(int a1, int a2){
	int angle = (abs(a1 - a2)) % 360;
 	if(angle > 180){
    	angle = 360 - angle;
 	}
	return angle;
}
// Navigation
void storeWayPoint(){

}
void loadWayPoint(){

}
int  getCurrentBearing(){

}
int  calcDestBearing(){

}
int  calcDestDistance(){

}
int  calcSetPoint(){

}

// Returns 0 if goal is reached, 1 if not there yet.
bool goalReached(){


}
char convertRudder();
