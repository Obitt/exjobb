/*
  The new OLED module drive IC has two version,
  1. SH1107G
  2. SSD1327
  
  Change the paramater of the drive IC name to init the module.
  **
  ** SeeedGrayOled.init(SSD1327);  // SSD1327 or SH1107G
  **

  Copyright - Seeedstudio
  Author - lambor
  Date - 4/24/2017
*/
#include <Wire.h>
#include <SeeedGrayOLED.h>


 int sensorPin = A0;
 int sensorValue = 0;
 float temp;

 
void setup()
{
  Wire.begin();	
  SeeedGrayOled.init(SH1107G);  //initialize SEEED Gray OLED display

  SeeedGrayOled.clearDisplay();           //clear the screen and set start position to top left corner
  SeeedGrayOled.setNormalDisplay();       //Set display to Normal mode
  SeeedGrayOled.setVerticalMode();        // Set to vertical mode for displaying text

}

void loop()
{

  int sensorValue = analogRead(sensorPin);
  temp = (sensorValue * 5.0 /1024 );

  
  SeeedGrayOled.setTextXY(8,4);           //Set the cursor to 0th line, 0th Column  
  SeeedGrayOled.putFloat(temp, 3);        //Print number
  SeeedGrayOled.setTextXY(5,3);           //set Cursor to ith line, 0th column
  SeeedGrayOled.putString("Voltage");     //Print Hello World
  SeeedGrayOled.setTextXY(6,3);           //set Cursor to ith line, 0th column
  SeeedGrayOled.putString("-------");
  delay(1000);

}


