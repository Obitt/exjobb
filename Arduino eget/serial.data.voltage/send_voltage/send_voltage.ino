//char dataString[50] = {0};
//int a =0; 
 int sensorPin = A0;
 int sensorValue = 0;
 //float temp;

void setup() {
Serial.begin(9600);              //Starting serial communication
}
  
void loop() {
  
  sensorValue = analogRead(sensorPin);
  
  //a++;                          // a value increase every loop
  //sprintf(dataString,"%02X",a); // convert a value to hexa 
  Serial.println(sensorValue);   // send the data
  delay(1000);                  // give the loop some break
}
