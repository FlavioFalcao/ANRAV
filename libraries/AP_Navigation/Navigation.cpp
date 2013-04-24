#include "Navigation.h"
//#include <BetterStream.h>
//#include <FastSerial.h>
//#include <ftoa_engine.h>
//#include <ntz.h>
//#include <xtoa_fast.h>


//this is a fancy way to initialize variables in C++
//essentially the parentheses say...
//a(b)  a=b

/* old stuff!
Navigation::Navigation(GPS *withGPS, Waypoints *withWP) : 
		_gps(withGPS),
		_wp(withWP),
		_hold_course(-1)
{
}

void
Navigation::update_gps()
{
	location.alt 		= _gps->altitude;
	location.lng 		= _gps->longitude;
	location.lat 		= _gps->latitude;
	
	// target_bearing is where we should be heading 
	bearing 			= get_bearing(&location, &next_wp);

	// waypoint distance from plane
	distance 			= get_distance(&location, &next_wp);
	
	calc_bearing_error();
	calc_altitude_error();
	altitude_above_home = location.alt - home.alt;
			
	// check if we have missed the WP
	_loiter_delta 		= (bearing - _old_bearing) / 100;
	
	// reset the old value
	_old_bearing 		= bearing;
	
	// wrap values
	if (_loiter_delta > 170) _loiter_delta -= 360;
	if (_loiter_delta < -170) _loiter_delta += 360;
	loiter_sum += abs(_loiter_delta);

	if (distance <= 0){
		distance = -1;
		Serial.print("MSG wp error  ");
		Serial.println(distance, DEC);
	}
}
*/

//PATRICK WRITTEN STUFFFFFFF
Navigation::Navigation()
{
//	_gps = NULL;
	_wp = NULL;
	_hold_course = -1;
}

Navigation::Navigation(Waypoints *withWP)
{
//	_gps = NULL;
	_wp = withWP;
	_hold_course = -1;
}

void
Navigation::update_gps(int32_t altitude,int32_t longitude,int32_t latitude,int32_t ground_course)
{
	location.alt 		= altitude;//_gps->altitude;
	location.lng 		= longitude;//_gps->longitude;
	location.lat 		= latitude;//_gps->latitude;
	
	// target_bearing is where we should be heading 
	bearing 			= get_bearing(&location, &next_wp);

	// waypoint distance from plane
	distance 			= get_distance(&location, &next_wp);
	

	/////////////
	//JUST CALCULATE BEARING IN HERE INSTEAD OF CALLING A FUNCITON....
	//Navigation::calc_bearing_error(void)
	if(_hold_course == -1)
	{
		bearing_error = wrap_180(bearing - ground_course);
	}
	else
	{
		bearing_error = _hold_course;
	}
	//}

	//calc_bearing_error();
	////////

	calc_altitude_error();
	altitude_above_home = location.alt - home.alt;
			
	// check if we have missed the WP
	_loiter_delta 		= (bearing - _old_bearing) / 100;
	
	// reset the old value
	_old_bearing 		= bearing;
	
	// wrap values
	if (_loiter_delta > 170) _loiter_delta -= 360;
	if (_loiter_delta < -170) _loiter_delta += 360;
	loiter_sum += abs(_loiter_delta);

	if (distance <= 0){
		distance = -1;
		Serial.print("MSG wp error  ");
		Serial.println(distance, DEC);
	}
}


void
Navigation::set_wp(Waypoints* withWP)
{
	_wp = withWP;
}

uint8_t 
Navigation::get_current_wp_index(void)
{
	return _wp->get_index();
}


void
Navigation::set_next_wp(void)
{
	prev_wp = next_wp;
	_wp->next_index();//increments the current waypoint index
	next_wp = _wp->get_current_waypoint();

	total_distance = get_distance(&location,&next_wp);
	distance       = total_distance;

	bearing        = get_bearing(&location,&next_wp);
	_old_bearing   = bearing;

	_loiter_delta  = 0;
	loiter_sum     = 0;

	reset_crosstrack();

}

//this is the previous version of set_next_wp
void
Navigation::set_new_destination(Waypoints::WP loc)
{
	prev_wp = next_wp;
	next_wp = loc;
	
	if(_scaleLongDown == 0)
	calc_long_scaling(loc.lat);

	total_distance 		= get_distance(&location, &next_wp);
	distance			= total_distance;
	
	bearing 			= get_bearing(&location, &next_wp);
	_old_bearing 		= bearing;

	// clear loitering code
	_loiter_delta 		= 0;
	loiter_sum 			= 0;	

	// set a new crosstrack bearing
	// ----------------------------
	reset_crosstrack();
}



//END OF PATRICK WRITTEN STUFF
///////////////////////////

void
Navigation::load_first_wp(void)
{
	_wp->set_index(1);
	set_new_destination(_wp->get_current_waypoint());
}

void
Navigation::load_home(void)
{
	home = _wp->get_waypoint_with_index(0);
}

void
Navigation::return_to_home_with_alt(uint32_t alt)
{
	Waypoints::WP loc = _wp->get_waypoint_with_index(0);
	loc.alt += alt;
	set_new_destination(loc);
}

void
Navigation::reload_wp(void)
{
	set_new_destination(_wp->get_current_waypoint());
}

void
Navigation::load_wp_index(uint8_t i)
{
	_wp->set_index(i);
	set_new_destination(_wp->get_current_waypoint());
}

void
Navigation::hold_location()
{
  //	set_next_wp()	XXX needs to be implemented
}

void
Navigation::set_home(Waypoints::WP loc)
{
	_wp->set_waypoint_with_index(loc, 0);
	home 		= loc;
	//location 	= home;
}

void 
Navigation::calc_long_scaling(int32_t lat)
{
	// this is used to offset the shrinking longitude as we go towards the poles	
	float rads 			= (abs(lat) / T7) * 0.0174532925;
	_scaleLongDown 		= cos(rads);
	_scaleLongUp 		= 1.0f / cos(rads);
}

void
Navigation::set_hold_course(int16_t b)
{
	if(b)
		_hold_course = bearing;
	else
		_hold_course = -1;
}

int16_t
Navigation::get_hold_course(void)
{
	return _hold_course;
}

void
Navigation::calc_distance_error()
{	
	//distance_estimate 	+= (float)_gps->ground_speed * .0002 * cos(radians(bearing_error * .01));
	//distance_estimate 	-= DST_EST_GAIN * (float)(distance_estimate - GPS_distance);
	//distance  		= max(distance_estimate,10);
}

int32_t
Navigation::wrap_180(int32_t error)
{
	if (error > 18000)	error -= 36000;
	if (error < -18000)	error += 36000;
	return error;
}

int32_t
Navigation::wrap_360(int32_t angle)
{
	if (angle > 36000)	angle -= 36000;
	if (angle < 0)		angle += 36000;
	return angle;
}

void
Navigation::set_bearing_error(int32_t error)
{
	bearing_error = wrap_180(error);
}


/*****************************************
 * Altitude error with Airspeed correction
 *****************************************/
void
Navigation::calc_altitude_error(void) 
{
	// limit climb rates
	_target_altitude = next_wp.alt - ((float)((distance -20) * _offset_altitude) / (float)(total_distance - 20));
	if(prev_wp.alt > next_wp.alt){
		_target_altitude = constrain(_target_altitude, next_wp.alt, prev_wp.alt);
	}else{
		_target_altitude = constrain(_target_altitude, prev_wp.alt, next_wp.alt);
	}
	altitude_error 	= _target_altitude - location.alt;
}

void
Navigation::set_loiter_vector(int16_t v)
{
  //	_vector = constrain(v, -18000, 18000);	XXX needs to be implemented
}

void
Navigation::update_crosstrack(void)
{
	// Crosstrack Error
	// ----------------
	if (abs(bearing - _crosstrack_bearing) < 4500) {	 // If we are too far off or too close we don't do track following
		_crosstrack_error = sin(radians((bearing - _crosstrack_bearing) / 100)) * distance;	 // Meters we are off track line
		bearing += constrain(_crosstrack_error * XTRACK_GAIN, -XTRACK_ENTRY_ANGLE, XTRACK_ENTRY_ANGLE);
	}
}

void
Navigation::reset_crosstrack(void)
{
	_crosstrack_bearing 	= get_bearing(&location, &next_wp);	// Used for track following
}

long
Navigation::get_distance(Waypoints::WP *loc1, Waypoints::WP *loc2)
{
	if(loc1->lat == 0 || loc1->lng == 0) 
		return -1;
	if(loc2->lat == 0 || loc2->lng == 0) 
		return -1;
	if(_scaleLongDown == 0)
		calc_long_scaling(loc2->lat);
	float dlat 	= (float)(loc2->lat - loc1->lat);
	float dlong = ((float)(loc2->lng - loc1->lng)) * _scaleLongDown;
	return sqrt(sq(dlat) + sq(dlong)) * .01113195;
}

long 
Navigation::get_bearing(Waypoints::WP *loc1, Waypoints::WP *loc2)
{
	if(loc1->lat == 0 || loc1->lng == 0) 
		return -1;
	if(loc2->lat == 0 || loc2->lng == 0) 
		return -1;
	if(_scaleLongDown == 0)
		calc_long_scaling(loc2->lat);
	long off_x 			= loc2->lng - loc1->lng;
	long off_y 			= (loc2->lat - loc1->lat) * _scaleLongUp;
	long bearing 		=	9000 + atan2(-off_y, off_x) * 5729.57795;
	if (bearing < 0) 
		bearing 		+= 36000;
	return bearing;
}
