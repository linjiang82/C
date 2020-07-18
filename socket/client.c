#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 8080
int main(int argc, char *argv[]){
  int sockfd;
  struct sockaddr_in address;
  int addlen = sizeof(address);
  char buffer[1024];

  //create socket
  if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0){
    perror("create failed");
    exit(-1);
  }
  address.sin_family =AF_INET;
  address.sin_port = htons(PORT);
  if(inet_pton(AF_INET,"127.0.0.1", &address.sin_addr)<0){
    perror("Invalid address");
    exit(-1);
  }
  //connection
  if(connect(sockfd,(struct sockaddr *)&address, addlen)<0){
    perror("connection failed");
    exit(-1);
  }
  send(sockfd,"hello from client",strlen("hello from client"),0);
  printf("hello sent from client\n");
  read(sockfd,buffer,1024);
  printf("%s\n",buffer);
  return 1;
}