#!/usr/bin/env python
import easygui as eg
import serial
# The following line will vary between OS and environment. Set it as 
# appropriate.
ser = serial.Serial('/dev/tty.usbserial-A9014QOJ', 9600, timeout=1) 

# Example of receiving data. We need to work on this some more.
# while 1: # go forever
#      line = ser.readline() # read serial data until you encounter a newline.
#      if(line != ''):      # make sure there is something read from the buffer.
#          mylist = line.split(',') # create an array from line splitting every 
#                                     comma.
#          print mylist # print array
#      #### end if
# #### end while

# Globals
title       = "ANRAV SeaVoyager GUI"
components  = ["Manual Control","Tune PID Controls","New WayPoint", "Exit"]

# Functions
# Entry function will loop forever unless it it is quit.
def entry():
	msg='What would you like to do?'
	return eg.buttonbox(title=title,msg=msg,choices=components)
####

# This will display a window which will allow one to set PID Tuning parameters.
# It returns a list of values.
def getPID():
	msg = "Enter new PID Tuning Parameters"
	fieldNames = ["Aggressive Kp:","Aggressive Ki:","Aggressive Kd:","Conservative Kp:","Conservative Ki:","Conservative Kd:"]
	return eg.multenterbox(msg=msg,title=title,fields=fieldNames)
####

# This will display a window which lets one select a waypoint to navigate to.
# It returns a list with North and West coordinates.
def getWayPoint():
	msg = "Enter a New WayPoint"
	fieldNames =["NORTH:","WEST:"]
	return eg.multenterbox(msg=msg,title=title,fields=fieldNames)
####

# This function allows the boat to be steered manually. I need to figure out how
# to trap the arrow keys and translate it to Kyle's mapping.
def manualControl():
	# n - into manual Control
	# x - exit manual Control
	steering = ['Up','Left','Right','Down']
	kylesteer = ['+','l','r','-']
	# Stuff goes here
	#serial.write(kylesteer[num])
####

def sendWayPoints(listofNW):
	# This function takes an array with the N and W values.
	#north = '00000000'
	#west  = '000000000'
	north = listofNW[0]
	west  = listofNW[1]
	# Need regex for input checking here...
	#
	####
	# Compile string and send data.
	mystring = 'sw'+ north + 'N' + west + 'W' + "\n"
	serial.write(mystring)
####

def sendPID(listofvalues):
	# This function takes a list of 6 K parameters
	# Full String (as pseudo-regex): 's[ac][pid][0000000000]*1000'
	# type = [ac] (aggressive or conservative)
	# param = [pid] (Proportional, Integral, Derivative)
	# value = digits: [0000000000]
	mystring = 's'+ type + param + value*1000 + "\n"
	serial.write(mystring)
####

while True:
	reply = entry()
	# Manual Control
	if reply == components[0]:
		manualControl()	
	# PID Controls
	elif reply == components[1]:
		sendPID(getPID())
	# Waypoint Entry
	elif reply == components[2]:
		sendWayPoints(getWayPoint())
	else:
		exit()
####

# print ("Reply was:", fieldValues)


