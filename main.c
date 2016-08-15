#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <arpa/inet.h>
#include <ctype.h>
#include "APIparser.c"

const int SERVER_PORT = 9876;
const char* SERVER_IP = "13.13.13.1";
const int PACKET_SIZE_BYTES = 4;


void configureAddresStruct(struct sockaddr_in*);

int main(){
  initWiringPi();
  int udpSocket, nBytes;
  signed char buffer[PACKET_SIZE_BYTES];
  struct sockaddr_in serverAddr, clientAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size, client_addr_size;
  /*Create UDP socket*/
  udpSocket = socket(PF_INET, SOCK_DGRAM, 0);
  /*Configure settings in address struct*/
  configureAddresStruct(&serverAddr);
  /*Bind socket with address struct*/
  bind(udpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
  /*Initialize size variable to be used later on*/
  addr_size = sizeof serverStorage;

  while(1){

    /* Try to receive any incoming UDP datagram. Address and port of
      requesting client will be stored on serverStorage variable */
    nBytes = recvfrom(udpSocket,buffer,PACKET_SIZE_BYTES,0,(struct sockaddr *)&serverStorage, &addr_size);
    /*Parse received message and make response*/
    printf( "MSSG: %d %d %d \n",buffer[0],buffer[1],buffer[2] );
    char answer[]={(char)1,(char)1,(char)1,(char)1};
    parseMessage(buffer,answer);
    sendto(udpSocket,answer,PACKET_SIZE_BYTES,0,(struct sockaddr *)&serverStorage,addr_size);
  }

  return 0;
}

void configureAddresStruct(struct sockaddr_in* serverAddr){
  serverAddr->sin_family = AF_INET;
  serverAddr->sin_port = htons(SERVER_PORT);
  serverAddr->sin_addr.s_addr = inet_addr(SERVER_IP);
  memset(serverAddr->sin_zero, '\0', sizeof serverAddr->sin_zero);
}
