#include <Wire.h>

#define SLAVE_ADDRESS 0x04
int number = 0;
//int state = 0;
 int sensorPin = A0;
 int sensorPin2 = A2;
 int sensorValue = 0;
 int sensorValue2 = 0;

void setup() {
//pinMode(13, OUTPUT);
// initialize i2c as slave
Wire.begin(SLAVE_ADDRESS);

// define callbacks for i2c communication
Wire.onReceive(receiveData);
Wire.onRequest(sendData);

}

void loop() {
  sensorValue = analogRead(sensorPin) * 11;
  sensorValue2 = analogRead(sensorPin2);
//delay(100);
}

// callback for received data
void receiveData(int byteCount){
 
while(Wire.available()) {
number = Wire.read();


}
}

// callback for sending data
void sendData(){
  if(number == 0x00){
    uint8_t lower = sensorValue; 
    uint8_t upper = sensorValue >> 8;
    uint8_t barr[] = {lower,upper};
    Wire.write(barr,2);  
}
  else if (number == 0x01){
    uint8_t lower = sensorValue2;
    uint8_t upper = sensorValue2 >> 8;
    uint8_t barr[] = {lower,upper};
    Wire.write(barr, 2);
  }
  else
    Wire.write(69);
}
