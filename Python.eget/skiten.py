import serial

ser = serial.Serial('/dev/ttyACM0',9600)


str = ser.readline()  # read a string from the serial port

value = float(str)    # convert a string to a floating point numberstr = ser.readline()  # read a string from the serial port
s = (0,1)

s = float(str)    # convert a string to a floating point number

volt = 5.1 * 11.5 * s / 1023
   # volt = volt * 11.5

print (volt)


