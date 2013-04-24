#include <Waypoints.h>
#include <Navigation.h>
#include <GPS_NMEA.h>


//AP_GPS_IMU gps;
Navigation nav;
GPS_NMEA_Class gps;
//void        update_gps(int32_t altitude,int32_t longitude,int32_t latitude,int32_t ground_course);
void setup()
{
	Serial.begin(38400);
	Serial.println("Navigation test");

	
	Waypoints::WP	location_A = ;
	Waypoints::WP	location_B = {0, 0, 38.578743 * T7, -122.572782 * T7, 5000};
	

	long distance 	= nav.get_distance(&location_A, &location_B);
	long bearing 	= nav.get_bearin(&location_A, &location_B);

	nav.update_gps(gps.altitude,gps.longitude,gps.latitude,gps.ground_course);
	long distance_gps = nav.distance;
	long bearing_gps = nav.bearing;

	Serial.print("\tDistance = ");
	Serial.print(distance, DEC);	
	Serial.print(" Bearing = ");
	Serial.println(bearing, DEC);
}

void loop()
{
}
