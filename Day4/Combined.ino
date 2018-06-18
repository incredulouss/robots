void runAll()
{
  switch(state)
  {
    case MAZE:  maze();
    break;
    case RIGHT_WALL_FOLLOW : followRightWall();
    break;
    case LEFT_WALL_FOLLOW: followLeftWall();
    break;
    case BLOCK_DETECTION: blinking();
    break;
    case BLINK: blinking();
    break;
  }
}

void blinking()
{
  stp();
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,5);
  display.print("Blocks- ");
  display.println(blocks);
  display.setTextSize(1);
  display.println();
  for(int i=0;i<blocks;i++)
  {
    display.print("Block ");
    display.print(i+1);
    display.print("- ");
    if(blockColour[i]=='R')
      display.println("Red");
    else if(blockColour[i]=='B')
      display.println("Blue");
    
  }
  display.display();
  delay(2);
  while(1)
  {
    digitalWrite(LED,1);
    delay(1000);
    digitalWrite(LED,0);
    delay(1000);
  }
}

