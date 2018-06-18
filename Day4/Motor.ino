void motorInit(){
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);
  pinMode(motorPower, OUTPUT);
}
void forward(int pwm)
{
  digitalWrite(motorPower, 1); 
  digitalWrite(rightMotor1, 1);
  digitalWrite(rightMotor2, 0);
  analogWrite(rightMotorPWM, pwm);
  digitalWrite(leftMotor1, 1);
  digitalWrite(leftMotor2, 0);
  analogWrite(leftMotorPWM, pwm);
}
void right(int pwm)
{
  digitalWrite(motorPower, 1); 
  digitalWrite(rightMotor1, 0);
  digitalWrite(rightMotor2, 1);
  analogWrite(rightMotorPWM, pwm);
  digitalWrite(leftMotor1, 1);
  digitalWrite(leftMotor2, 0);
  analogWrite(leftMotorPWM, pwm);
}
void left(int pwm)
{
  digitalWrite(motorPower, 1); 
  digitalWrite(rightMotor1, 1);
  digitalWrite(rightMotor2, 0);
  analogWrite(rightMotorPWM, pwm);
  digitalWrite(leftMotor1, 0);
  digitalWrite(leftMotor2, 1);
  analogWrite(leftMotorPWM, pwm);
}
void stp()
{
  digitalWrite(motorPower, 1);
  digitalWrite(rightMotor1, 0);
  digitalWrite(rightMotor2, 1);
  analogWrite(rightMotorPWM, 0);
  digitalWrite(leftMotor1, 0);
  digitalWrite(leftMotor2, 1);
  analogWrite(leftMotorPWM, 0);
  for(int i=100;i>=0;i=i-2)
  {
     analogWrite(leftMotorPWM, i);
     analogWrite(rightMotorPWM, i);
  }
}
