#include <Wire.h>

#define SLAVE_ADDRESS 0x04
int number = 0;

 int sensorPin = A0;
 int sensorPin2 = A2; 
 int sensorPin3 = A3; 
 
 int sensorValue = 0;
 int sensorValue2 = 0;
 int sensorValue3 = 0;
 uint32_t time = 0;
 
 int locked_sens = 0;
 int locked_sens2 = 0;
 int locked_sens3 = 0;
 uint32_t locked_time = 0;

void setup() {
//pinMode(13, OUTPUT);
// initialize i2c as slave
Wire.begin(SLAVE_ADDRESS);
pinMode(10, OUTPUT);

// define callbacks for i2c communication
Wire.onReceive(receiveData);
Wire.onRequest(sendData);
digitalWrite(10,HIGH);
}
void loop() {
  sensorValue = analogRead(sensorPin) * 11;
  sensorValue2 = analogRead(sensorPin2);
  sensorValue3 = analogRead(sensorPin3);
  
  noInterrupts();
  locked_sens = sensorValue;
  locked_sens2 = sensorValue2;
  locked_sens3 = sensorValue3;
  locked_time = time;
  interrupts();
  
  if (sensorValue2 < 640){ // if battery voltage drops below 3.65V, 640
    time = 0;
    delay(10000); //10 sekunder innan rasp stängs av
    digitalWrite(10, LOW);
  }
  else if (sensorValue2 > 765){ // keep Raspberry off until bateryvoltage is over 3.75V ,760
    digitalWrite(10, HIGH);
  } 
  
  delay(995);
  time = time + 1;
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
    uint8_t lower = locked_sens; 
    uint8_t upper = locked_sens >> 8;
    uint8_t barr[] = {lower,upper};
    Wire.write(barr,2);  
}
  else if (number == 0x01){
    uint8_t lower = locked_sens2;
    uint8_t upper = locked_sens2 >> 8;
    uint8_t barr[] = {lower,upper};
    Wire.write(barr, 2);
}
  else if (number == 0x02){
    uint8_t lower = locked_sens3;
    uint8_t upper = locked_sens3 >> 8;
    uint8_t barr[] = {lower,upper};
    Wire.write(barr, 2);
}  
  else if (number == 0x03){
    uint8_t lower_low = locked_time;
    uint8_t lower_high = locked_time >> 8;
    uint8_t upper_low = locked_time >> 16;
    uint8_t upper_high = locked_time >> 24;
    uint8_t barr[] = {lower_low,lower_high,upper_low,upper_high};
    Wire.write(barr, 4);
  }
  else
    Wire.write(69);
}
