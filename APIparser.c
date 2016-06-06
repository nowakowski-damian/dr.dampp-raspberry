#include "Errors.h"
#include "HardwareFunctions.c"

void parseMessage(char*,char*);

const int TEST_CONNECTION_VALUE = 127;

void parseMessage(char* data,char* answer){

	answer[0]=NO_ERRORS;

	switch( data[0] ){

		case 0:
			setMotors( data[1],data[2] );
			break;
		case 1: 
			setSwitch( data[1],data[2] );
			break;
		case 2:
			if( data[1]==0 ){
				left( data[2] );
			}
			else if( data[1]==1 ){
				right( data[2] );
			}
			break;
		case 127:
			//testConnection
			answer[1]=TEST_CONNECTION_VALUE;
			answer[2]=TEST_CONNECTION_VALUE;
			answer[3]=TEST_CONNECTION_VALUE;
			return;
		default:
			answer[0]=REQUEST_PARSE_ERROR;
	}

	answer[1]=getAccuLevel();
	answer[2]=getTemperature();
	answer[3]=127;
}


