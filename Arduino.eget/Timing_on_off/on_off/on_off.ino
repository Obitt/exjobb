void setup() {
  
  pinMode(10, OUTPUT);     // sätter pin 10 till output
  
}

void loop() {
 
  digitalWrite(10, HIGH);   // sätter pin 10 hög
  delay(2000);          // håller pin 10 höt i 2 minuter
  digitalWrite(10, LOW);    // sätter pin 10 låg
  delay(8000);          // håller pin 10 låg i 8 minuter
}
