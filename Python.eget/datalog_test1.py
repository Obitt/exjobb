import os
import time
import serial

from time import sleep #to create delays
from datetime import datetime


ser = serial.Serial('/dev/ttyACM0',9600)

    
str1 = ser.readline()  # read a string from the serial port
s = float(str1)    # convert a string to a floating point number
volt = 5.1 * 11.5 * s / 1023 #scales the analog input voltage 
    
rounded_real_volt = ("%.3f" % round (volt,3)) #rounds the voltage
#print (rounded_real_volt) # prints the  current voltage in the terminal

file = open("/media/pi/KINGSTON/data_log.csv", "a")
i=0
if os.stat("/media/pi/KINGSTON/data_log.csv").st_size == 0:
        file.write('Time, Voltage\n')

while True: 
    i=i+1
    now = datetime.now()
    file.write(str(now)+","+str(rounded_real_volt)+"\n")
    file.flush()
    time.sleep(10) #wait for some seconds
file.close()
