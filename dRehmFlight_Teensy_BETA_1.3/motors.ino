void commandMotorsWithPWM()
{
  //m1_command_PWM between 125-250
  setMotor(PROP_FL_PIN, ((m1_command_PWM+0.0)-125)/(250-125));//set the motor to the scaled command
  setMotor(PROP_FR_PIN, ((m2_command_PWM+0.0)-125)/(250-125));//set the motor to the scaled command
  setMotor(PROP_BR_PIN, ((m3_command_PWM+0.0)-125)/(250-125));//set the motor to the scaled command
  setMotor(PROP_BL_PIN, ((m4_command_PWM+0.0)-125)/(250-125));//set the motor to the scaled command
}
void setMotor(int pin, double s)//0-1
{
  //multishot timing: 5-25us minimum of 10% - 50%
  //oneshot 125-250
//  double count = .25+s*.25;//10% - 50% one shot timing?
  int freq = 2000;
  double minThrottle = 0.000005;
  double maxThrottle = 0.000025;
  double count = (minThrottle+s*(maxThrottle-minThrottle))/(1.0/freq);
  int writeable = count*32757;
//  Serial.println(writeable);
  analogWrite(pin, writeable);
}
void setAllMotors(double s)
{
  setMotor(PROP_FR_PIN, s);
  setMotor(PROP_BR_PIN, s);
  setMotor(PROP_FL_PIN, s);
  setMotor(PROP_BL_PIN, s);
}
void initMotors()
{
  Serial.println("arm start");
  analogWriteResolution(15);
  
  Serial.println("change freq");
  int freq = 2000;
  analogWriteFrequency(PROP_FR_PIN, freq);//change to 2khz for motor control
  analogWriteFrequency(PROP_BR_PIN, freq);
  analogWriteFrequency(PROP_FL_PIN, freq);
  analogWriteFrequency(PROP_BL_PIN, freq);
  analogWrite(PROP_FR_PIN, 0);
  analogWrite(PROP_BR_PIN, 0);
  analogWrite(PROP_FL_PIN, 0);
  analogWrite(PROP_BL_PIN, 0);

  delay(1000);
  
  Serial.println("0");
  setAllMotors(0);
  delay(1000);
  Serial.println(".1");
  setAllMotors(.1);
  delay(1000);
  Serial.println("0");
  setAllMotors(0);
  
//  propFR.attach(PROP_FR_PIN);
//  propBR.attach(PROP_BR_PIN);
//  propFL.attach(PROP_FL_PIN);
//  propBL.attach(PROP_BL_PIN);
//  Serial.println("1000");
//  propFR.writeMicroseconds(1000);
//  propBR.writeMicroseconds(1000);
//  propFL.writeMicroseconds(1000);
//  propBL.writeMicroseconds(1000);
//  delay(1000);
//  Serial.println("1300");
//  propFR.writeMicroseconds(1300);
//  propBR.writeMicroseconds(1300);
//  propFL.writeMicroseconds(1300);
//  propBL.writeMicroseconds(1300);
//  delay(1000);
//  Serial.println("1000");
//  propFR.writeMicroseconds(1000);
//  propBR.writeMicroseconds(1000);
//  propFL.writeMicroseconds(1000);
//  propBL.writeMicroseconds(1000);
//    motorInit = true;
}
