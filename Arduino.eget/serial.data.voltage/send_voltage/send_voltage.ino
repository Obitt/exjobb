//char dataString[50] = {0};
//int a =0; 
 int sensorPin = A0;
 int sensorPin2 = A5;
 int sensorValue = 0;
 int sensorValue2 = 0;

void setup() {
Serial.begin(9600);              //Starting serial communication
}
  
void loop() {
  
  sensorValue = analogRead(sensorPin);
  sensorValue2 = analogRead(sensorPin2);
  
  //a++;                          // a value increase every loop
  //sprintf(dataString,"%02X",a); // convert a value to hexa 
  Serial.println(sensorValue);   // send the data
  delay(100);
  Serial.println(sensorValue2);
  delay(5000);                  // give the loop some break, in milliseconds
}
