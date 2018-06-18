void rightTurn(){
  getval();
  right(turnSpeed);
  while(s[3] || s[4])
  {
    getval();
  }
  while((!s[3]) || (!s[4]))
  {
    getval();
  }
}

void leftTurn(){
  getval();
  left(turnSpeed);
  while(s[3] || s[4])
  {
    getval();
  }
  while((!s[3]) || (!s[4]))
  {
    getval();
  }
}

void turn(char direction)
{
  switch(direction)
  {
  case 'L':
    // Turn left.
    leftTurn();
    break;
  case 'R':
    // Turn right.
    rightTurn();
    break;
  case 'B':
    // Turn around.
    turnAround();
    break;
  case 'S':
    forward(BaseSpeed);
    delay(10);// Don't do anything!
    break;
  }
  stp();
  delay(20);
  align();
}

void turnAround(){
  getval();
  left(turnSpeed);
  while((!s[3]) || (!s[4]))
  {
    getval();
  }
}


