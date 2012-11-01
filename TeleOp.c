#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     motorF,        tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     motorG,        tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C4_1,     motorH,        tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     motorI,        tmotorTetrix, openLoop, encoder)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"
void initializeRobot()
{
  return;
}
#pragma platform(Tetrix)
void omniDrive(int joyx, int joyy);
task main()
{
  initializeRobot();
while(true){
getJoystickSettings(joystick);
omniDrive(joystick.joy1_x1, joystick.joy1_y1);
if (joy1btn(5)==1)
	{
		motor[motorH]=50;
  }

	switch(joystick.joy1_TopHat)
	{
		case 0:
		case 1:
		case 7:
		servo[servo1] = 40;
		break;

		case 5:
		case 4:
		case 3:
		servo[servo1] = -40;
		break;

		default:
		servo[servo1] = 0;
	}
}
void omniDrive(int joyx, int joyy)
{
motor[motorE] = motor[motorD] = ((100.0/128)*(float)joyx + (100.0/128)*(float)joyy)/sqrt(2);
motor[motorG] = motor[motorF]= ((100.0/128)*-(float)joyx + (100.0/128)*(float)joyy)/sqrt(2);
}