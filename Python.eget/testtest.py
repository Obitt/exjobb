import serial

ser = serial.Serial('/dev/ttyACM0',9600)
s = (0,1)
while True:
    read_serial=ser.readline()
    s = float(ser.readline())
    volt = 5.1 * s / 1023
    real_volt = volt * 11.5
    rounded_real_volt = ("%.3f" % round (real_volt,3))
    print (rounded_real_volt)
    print (volt)
    #print (read_serial)
    print ( )