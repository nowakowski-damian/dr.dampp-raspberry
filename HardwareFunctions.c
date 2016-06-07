#include <wiringPi.h>
#include <softPwm.h>

void setMotors(int, int)
void setSwitch(char,char);
void left(char);
void right(char);
char getAccuLevel(void);
char getTemperature(void);
//****************************************
void setMotors(int right, int left){
	if(right>=0)
	{
		softPwmWrite(0, right);
        softPwmWrite(1, 0);
	}
	else
	{
		softPwmWrite(1,( (-1)*right) );
        softPwmWrite(0, 0);
	}
	
	if(left>=0)
    {
        softPwmWrite(2, left);
        softPwmWrite(3, 0);
    }
    else
    {
	    softPwmWrite(3, ((-1)*left));
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
int main(void){
	wiringPiSetup();
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT);
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	softPwmCreate(0, 0, 100);
	softPwmCreate(1, 0, 100);
	softPwmCreate(2, 0, 100);
	softPwmCreate(3, 0, 100);

while(1){	
	setMotors(-100, 100);
	delay(1000);
	setMotors(100, -100);
	delay(1000);
  }
	return 0;
}
