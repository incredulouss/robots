/*
-> check voltage of battery
-> check line threshold value
-> check distance sensor value
-> check colour sensor
-> check inch delay
-> check the switching area of maze to wall
-> check left wall following and set distance according to black spot
-> check right wall following
-> check the switching area of right wall to left
-> check the switching area of left wall to block detection line
*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "pins.h"
#include "pitches.h"

void setup() {
  IRinit();  
  motorInit();
  distanceInit();
  colourSensorInit();
  buttonInit();
  OLEDinit();
  printLogo();
  startOptions();
}

void loop() {
  runAll();
  //afterWallPID()
  //followLeftWall();
  //followRightWall();
  //printColourData()
}

