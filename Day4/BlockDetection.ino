void blockDetection()
{
  pid();
  unsigned char foundLeft=0;
  unsigned char foundRight=0;
  unsigned char foundStraight=0;
  forward(70);
  delay(10);
  getval();                 //2ms delay latency
    
  if(s[0])
    foundLeft=1;
  if(s[7])
    foundRight=1;
  forward(40);    
  delay(inchDelay);
  getval();
  if(s[0] && s[7])
    {
      //stp();delay(100);
      state=BLINK;
      return;
    }
  if(s[2] || s[3] || s[4] || s[5])
      foundStraight=1;
  if(foundLeft && foundRight)
  {
    stp();
    delay(400);
    char clr=checkColour();
    blockColour[blocks++]=clr;
    if(clr == 'R')
      turn('R');
    else
      turn('L');
  }
  else if(foundLeft)
    turn('L');
  else if(foundRight)
    turn('R');
}

char checkColour()
{
  int red=getRed();
  int blue=getBlue();
  if(red > blue)
    return 'R';
  else
    return 'B';
}


