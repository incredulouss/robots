void buttonInit()
{
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(LED,OUTPUT);
}

void startOptions()
{ 
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,5);
  display.print("Calibrate");
  display.setCursor(0,40);
  display.setTextSize(1);
  display.println("1: Calibrate IR");
  display.print("2: Skip");
  display.display();
  delay(10);
  //----------------------------------------------------------
  int b1=1,b2=1;
  while(b1 && b2)
  {
    b1 = digitalRead(BUTTON_1);
    b2 = digitalRead(BUTTON_2);
  }
  delay(700);
  if(b1 == 0)
  {
    calibrateSensors();
    while((digitalRead(BUTTON_1)))
    printNormVal();
    delay(700);  
  }
  b1=1,b2=1;
  //----------------------------------------------------------
//  while((digitalRead(BUTTON_1)));
//  delay(700);
//  calibrateSensors();

//  while((digitalRead(BUTTON_1)))
//    printNormVal();

//  delay(100);
//  while(!(digitalRead(BUTTON_1)));
  

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,5);
  display.print("Calibrate");
  display.setCursor(0,40);
  display.setTextSize(1);
  display.println("1: Colour Sensor");
  display.print("2: Skip");
  display.display();
  delay(10);

  
  while(b1 && b2)
  {
    b1 = digitalRead(BUTTON_1);
    b2 = digitalRead(BUTTON_2);
  }
  delay(700);
  if(b1 == 0)
  {
    colourCalibrate();
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,5);
    display.print("Calibrated");
    display.setCursor(0,50);
    display.setTextSize(1);
    display.print("1: Maze     ");
    display.print("2: Check");
    display.display();
    delay(10);
    b1=1,b2=1;
    while((digitalRead(BUTTON_1)))
    {
      if(!(digitalRead(BUTTON_2)))
      {
        char c=checkColour();
        display.clearDisplay();
        display.setTextSize(2);
        display.setTextColor(WHITE);
        display.setCursor(0,5);
        if(c=='R')
          display.print("Red");
        else
          display.print("Blue");
        display.setCursor(0,50);
        display.setTextSize(1);
        display.print("1: Maze     ");
        display.print("2: Check");
        display.display();
        delay(10); 
      }
    }
  }
  delay(700);
  int s=0;
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0,5);
  display.print("Maze");
  display.setCursor(0,50);
  display.setTextSize(1);
  display.print("1:Run        ");
  display.println("2:Next");
  display.display();
  delay(10);
  
  while((digitalRead(BUTTON_1)))
  {
    if(!(digitalRead(BUTTON_2)))
    {
      delay(700);
      s++;
      s=s%4;
      display.clearDisplay();
      switch(s)
      {
        case 0:
          display.setTextSize(2);
          display.setCursor(0,5);
          display.print("Maze");
          display.setCursor(0,50);
          display.setTextSize(1);
          display.print("1:Run        ");
          display.print("2:Next");
          display.display();
          delay(10);
          state=MAZE;
        break;
        case 1:
          display.setTextSize(2);
          display.setCursor(0,5);
          display.print("Right Wall Follow");
          display.setCursor(0,50);
          display.setTextSize(1);
          display.print("1:Run        ");
          display.println("2:Next");
          display.display();
          delay(10);
          state=RIGHT_WALL_FOLLOW;
        break;
        case 2:
          display.setTextSize(2);
          display.setCursor(0,5);
          display.print("Left Wall Follow");
          display.setCursor(0,50);
          display.setTextSize(1);
          display.print("1:Run        ");
          display.println("2:Next");
          display.display();
          delay(10);
          state=LEFT_WALL_FOLLOW;
        break;        
        case 3:
          display.setTextSize(2);
          display.setCursor(0,5);
          display.println("Block");
          display.print("Detection");
          display.setCursor(0,50);
          display.setTextSize(1);
          display.print("1:Run        ");
          display.println("2:Next");
          display.display();
          delay(10);
          state=BLOCK_DETECTION;
        break;
      }
    }
  }

  delay(1000); 
}

