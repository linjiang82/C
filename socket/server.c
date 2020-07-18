#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 8080 

int main(int argc, char *argv[]){
  int sockfd, newsocket;
  struct sockaddr_in address;
  int addlen = sizeof(address);
  char buffer[1024];

//create socket
  if((sockfd = socket(AF_INET,SOCK_STREAM,0))==0){
    perror("create socket failed");
    exit(-1);
  }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr=INADDR_ANY;
  address.sin_port = htons(PORT);

//binding
  if(bind(sockfd,(struct sockaddr *)&address,addlen)==-1){
    perror("binding failed");
    exit(-1);
  }

//listening
  if(listen(sockfd,1)==-1){
    perror("listen failed");
    exit(-1);
  }  
//accept
  while(1){
  if((newsocket=accept(sockfd, (struct sockaddr *)&address, (socklen_t *)&addlen))==-1){
    perror("accept failed");
    exit(-1);
  }
  read(newsocket,buffer,1024);
  printf("%s\n",buffer);
  send(newsocket,"hello from server",strlen("hello from server"),0);
  printf("hello send from server\n");
  sleep(1);
  }
  return 1;
}