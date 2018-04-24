import serial

ser = serial.Serial('/dev/ttyACM0',9600)
s = (0,1)
while true:
    read_serial=ser.readline()
    s = str(int (ser.readline(),16))
    print s
    print read_serial