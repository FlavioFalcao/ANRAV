#!/usr/bin/env python
import easygui as eg
import serial
try:
    # Python2
    from Tkinter import *
except ImportError:
    # Python3
    from tkinter import *
####

# Globals
title       = "ANRAV SeaVoyager GUI"
components  = ["Manual Control","Tune PID Controls","New WayPoint", "Exit"]

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


def key(event):
    """traps the key and sends the code to SeaVoyager"""
    steering = ['Up','Left','Right','Down']
    kylesteer = ['+','l','r','-']
    if event.keysym == 'Escape':
        ser.write('x')
        root.destroy()
    ####
   ####
    ser.write('nnn')
    var = repr(event.keysym)
    if event.keysym == 'Up':
        print "Sending ",var
        ser.write('+')
    elif event.keysym == 'Left':
        print "Sending ",var
        ser.write('l')
    elif event.keysym == 'Right':
        print "Sending ",var
        ser.write('r')
    elif event.keysym == 'Down':
        print "Sending ",var
        ser.write('-')
    ####
    print ser.readline();
    #print( 'Key pressed: %r' % event.keysym )
####
	# n - into manual Control
	# x - exit manual Control

class Application(Frame):
    def say_hi(self):
        print "Manual Steering Control"
        print ser.readline()
    ####

    def createWidgets(self):
        self.QUIT = Button(self)
        self.QUIT["text"] = "QUIT"
        #self.QUIT["fg"]   = "red"
        self.QUIT["command"] =  self.quit
        self.QUIT.pack({"side": "left"})
        #
        self.hi_there = Button(self)
        self.hi_there["text"] = "Steer",
        self.hi_there["command"] = self.say_hi
        self.hi_there.pack({"side": "left"})
    ####
    
    def __init__(self, master=None):
        Frame.__init__(self, master)
        self.pack()
        self.createWidgets()
    ####
####

# Functions
# Entry function will loop forever unless it it is quit.
def entry():
        image = "2420.gif"
	msg='What would you like to do?'
	return eg.buttonbox(image=image,title=title,msg=msg,choices=components)
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
	msg = "Enter a New WayPoint (NNN.NNNNN, WWW.WWWWW"
	fieldNames =["NORTH:","WEST:"]
	return eg.multenterbox(msg=msg,title=title,fields=fieldNames)
####

# This function allows the boat to be steered manually. I need to figure out how
# to trap the arrow keys and translate it to Kyle's mapping.
def manualControl():
        root = Tk()
        root.bind_all('<Key>', key)
        app = Application(master=root)
        app.mainloop()
        root.destroy()
	# Stuff goes here
#        var = 0
#	while var != 'q':
#            var = raw_input()
#            print var
#            #serial.write(kylesteer[num])
#            serial.write(var)
#            print seral.read()
#        ####
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
        print "Sending ",mystring
	ser.write(mystring)
        mystring = "Sending: " + mystring
        eg.msgbox(msg=mystring, title='Data Sent', ok_button='(OK) SeaVoyager Happy',image=None)

####

def sendPID(listofvalues):
	# This function takes a list of 6 K parameters
	# Full String (as pseudo-regex): 's[ac][pid][0000000000]*1000'
	# type = [ac] (aggressive or conservative)
	# param = [pid] (Proportional, Integral, Derivative)
	# value = digits: [0000000000]
        # print listofvalues
        type = ['ap','ai','ad','cp','ci','cd']
        cnt = 0
        bigstr = ["Sending Data:"]
        for param in listofvalues:
            #print "Sending ",type[cnt],param
            mystring = 's'+ type[cnt] + str(int(float(param)*1000)) + "\n"
            print "Sending ", mystring 
	    ser.write(mystring)
            cnt = cnt + 1
            bigstr.append(mystring)
        ####
        #eg.codebox(msg='New Waypoint Sent!', title='Sent', text=bigstr)
        eg.msgbox(msg=bigstr, title='New Waypoint Sent!', ok_button='(OK) SeaVoyager Happy', image=None)

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


