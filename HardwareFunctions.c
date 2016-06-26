#include <wiringPi.h>
#include <softPwm.h>

void init();
void setMotors(char, char);
void setSwitch(char,char);
void left(char);
void right(char);
char getAccuLevel(void);
char getTemperature(void);
//****************************************
void init()
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
void setMotors(char right, char left){
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
void setSwitch(char num,char boolean){
	digitalWrite(num, boolean);
}
//****************************************
void left(char angle){
	setMotors(100, -100);
	delay(angle*1000/180);
}
//****************************************
void right(char angle){
	setMotors(-100, 100);
	delay(angle*1000/180);
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

