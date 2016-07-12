#include <wiringPi.h>
#include <softPwm.h>

#define LEFT_RIGHT_CONST_SPEED 50
#define TURNAROUND_TIME_MS 2000

void initWiringPi(void);
void setMotors(signed char, signed char);
void setSwitch(signed char,signed char);
void left(signed char);
void right(signed char);
char getAccuLevel(void);
char getTemperature(void);
//****************************************
void initWiringPi()
{
	wiringPiSetup();
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT);
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	softPwmCreate(0, 0, 100);
}
//****************************************
void setMotors(signed char right, signed char left){
	if(right>=0)
	{
		softPwmWrite(0, (int)right);
        	softPwmWrite(1, 0);
	}
	else
	{
		softPwmWrite(1,( (-1)*(int)right) );
        	softPwmWrite(0, 0);
	}
	
	if(left>=0)
    	{
        	softPwmWrite(2, (int)left);
        	softPwmWrite(3, 0);
    	}
    	else
    	{
	    softPwmWrite(3, ((-1)*(int)left));
   	    softPwmWrite(2, 0);
	}
}
//****************************************
void setSwitch(signed char num,signed char boolean){
	digitalWrite((int)num,(int)boolean);
}
//****************************************
void left(signed char angle){
	setMotors(LEFT_RIGHT_CONST_SPEED, -LEFT_RIGHT_CONST_SPEED);
	delay(angle*TURNAROUND_TIME_MS/180);
	setMotors(0, 0);
}
//****************************************
void right(signed char angle){
	setMotors(-LEFT_RIGHT_CONST_SPEED, LEFT_RIGHT_CONST_SPEED);
	delay(angle*TURNAROUND_TIME_MS/180);
	setMotors(0, 0);
}
//******************************************
char getAccuLevel(){
	return -1;
}
//****************************************
char getTemperature(){	
	return -1;
}
//****************************************

