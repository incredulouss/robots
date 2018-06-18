#define Kp 0.2
#define Kd 10
#define ki 0

int pid()
{
  int lastError = 0;
  float integralError=0;
  VFlag=0; 
  while(1)
  {
    getval();
    int error = 3500-position;
    integralError= integralError + error;
    int motorSpeed = Kp * error + Kd * (error - lastError) + ki * integralError;
    lastError = error;

    int rightMotorSpeed = BaseSpeed + motorSpeed;
    int leftMotorSpeed = BaseSpeed - motorSpeed;
  
    if (rightMotorSpeed > rightMaxSpeed ) rightMotorSpeed = rightMaxSpeed; // prevent the motor from going beyond max speed
    if (leftMotorSpeed > leftMaxSpeed ) leftMotorSpeed = leftMaxSpeed; // prevent the motor from going beyond max speed
    if (rightMotorSpeed < 0) rightMotorSpeed = 0; // keep the motor speed positive
    if (leftMotorSpeed < 0) leftMotorSpeed = 0; // keep the motor speed positive
  
    digitalWrite(motorPower, HIGH); // move forward with appropriate speeds
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    analogWrite(rightMotorPWM, rightMotorSpeed);
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    analogWrite(leftMotorPWM, leftMotorSpeed);

    if(s[1] && s[2] && s[3] && s[4] && s[5] && s[6] && (!s[0]) && (!s[7]))
      VFlag=1;
    else
      VFlag=0;
      
    if(!(s[0] || s[1] || s[2] || s[3] || s[4] || s[5] || s[6] || s[7]))
    {
      //no line visible
      stp();delay(20);
      turn('B'); 
    }
    else if(s[0] || s[7])
    {
      // Found an intersection.
      return 1;
    }
  }
}

void align()
{
  unsigned long delTime=millis();
  int lastError = 0;
  float integralError=0;
  while((millis()-delTime) < alignTime)
  {
    getval();
    int error = 3500-position; 
    integralError= integralError + error;
    int motorSpeed = Kp * error + Kd * (error - lastError) + ki * integralError;
    lastError = error;

    int rightMotorSpeed = BaseSpeed + motorSpeed;
    int leftMotorSpeed = BaseSpeed - motorSpeed;
  
    if (rightMotorSpeed > rightMaxSpeed ) rightMotorSpeed = rightMaxSpeed; // prevent the motor from going beyond max speed
    if (leftMotorSpeed > leftMaxSpeed ) leftMotorSpeed = leftMaxSpeed; // prevent the motor from going beyond max speed
    if (rightMotorSpeed < 0) rightMotorSpeed = 0; // keep the motor speed positive
    if (leftMotorSpeed < 0) leftMotorSpeed = 0; // keep the motor speed positive
  
    digitalWrite(motorPower, HIGH); // move forward with appropriate speeds
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    analogWrite(rightMotorPWM, rightMotorSpeed);
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    analogWrite(leftMotorPWM, leftMotorSpeed);

  }
}
void afterWallPID()//----------------------bas base speed 70 hai
{
  int lastError = 0;
  float integralError=0;
  while(s[0] || s[7])
  {
    getval();
    int error = 3500-position; 
    integralError= integralError + error;
    int motorSpeed = Kp * error + Kd * (error - lastError) + ki * integralError;
    lastError = error;

    int rightMotorSpeed = 50 + motorSpeed;
    int leftMotorSpeed = 50 - motorSpeed;
  
    if (rightMotorSpeed > rightMaxSpeed ) rightMotorSpeed = rightMaxSpeed; // prevent the motor from going beyond max speed
    if (leftMotorSpeed > leftMaxSpeed ) leftMotorSpeed = leftMaxSpeed; // prevent the motor from going beyond max speed
    if (rightMotorSpeed < 0) rightMotorSpeed = 0; // keep the motor speed positive
    if (leftMotorSpeed < 0) leftMotorSpeed = 0; // keep the motor speed positive
  
    digitalWrite(motorPower, HIGH); // move forward with appropriate speeds
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    analogWrite(rightMotorPWM, rightMotorSpeed);
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    analogWrite(leftMotorPWM, leftMotorSpeed);

  }
}
