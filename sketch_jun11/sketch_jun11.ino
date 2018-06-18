
 #include "pins.h"
 #include "motors.h"

  motors Motors;     //object of the motors clss

  void setup() {

  Serial.begin(9600);
  IRinit();
 calibrateSensors();
 delay(6000);
  //printReadLine();
  }
  
  void loop() {
 
maze();
 //printReadLine();
//printReadRaw();
  }


 
  
  
