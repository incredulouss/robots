#define R_LED (25)
#define B_LED (27)
#define LDR (A13)

void colourSensorInit()
{
  pinMode(R_LED,OUTPUT);
  pinMode(B_LED,OUTPUT);
  pinMode(LDR,INPUT);
}


void colourCalibrate()
{
  for(int i=0;i<30;i++)
  {
    if(i%2==0)
    {
      blueOn();
      int r=analogRead(LDR);
      colourMin[1]=(r<colourMin[1]) ? r : colourMin[1];
      colourMax[1]=(r>colourMax[1]) ? r : colourMax[1];
      blueOff();
    }
    else
    {
      redOn();
      int r=analogRead(LDR);
      colourMin[0]=(r<colourMin[0]) ? r : colourMin[0];
      colourMax[0]=(r>colourMax[0]) ? r : colourMax[0];
      redOff();
    }
  }
}

int getRed()
{
  redOn();
  int r=analogRead(LDR);
  redOff();
  r=constrain(r,colourMin[0],colourMax[0]);
  r=map(r,colourMin[0],colourMax[0],0,1000);
  return r;
}
int getBlue()
{
  blueOn();
  int r=analogRead(LDR);
  blueOff();
  r=constrain(r,colourMin[1],colourMax[1]);
  r=map(r,colourMin[1],colourMax[1],0,1000);
  return r;
}

void blueOn()
{
  digitalWrite(B_LED,1);
  delay(100);
}
void blueOff()
{
  digitalWrite(B_LED,0);
  delay(100);
}
void redOn()
{
  digitalWrite(R_LED,1);
  delay(100);
}
void redOff()
{
  digitalWrite(R_LED,0);
  delay(100);
}

void printColourData()
{
  Serial.print("RED- ");
  Serial.print(colourMin[0]);
  Serial.print(" - ");
  Serial.println(colourMax[0]);
  Serial.print("BLUE- ");
  Serial.print(colourMin[1]);
  Serial.print(" - ");
  Serial.println(colourMax[1]);
  Serial.print("\nRed= ");
  Serial.println(getRed());
  delay(500);
  Serial.print("Blue= ");
  Serial.println(getBlue());
  delay(1000);
}

