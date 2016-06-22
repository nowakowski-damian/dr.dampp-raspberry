#include <wiringPi.h>
#include <softPwm.h>

void setMotors(char, char);
void setSwitch(char,char);
void left(char);
void right(char);
char getAccuLevel(void);
char getTemperature(void);
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
char left(char angle){
	setMotors(100, -100);
	delay(angle*1000/180);
}
//****************************************
char right(char angle){
	setMotors(100, -100);
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

