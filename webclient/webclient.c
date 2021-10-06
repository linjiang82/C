#include <sys/socket.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdarg.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <netdb.h>

#define PORT 80
#define MAXLINE 4096



int main(int argc,char * argv[]){
  int sockfd,n;
  struct sockaddr_in address;
  int addlen = sizeof(address);
  char rval[MAXLINE];
  char sendline[100];
  int sendbytes;

  if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0){
    perror("socket creation failed");
    exit(-1);
  }
  memset(&address,0,addlen);
  address.sin_family = AF_INET;
  address.sin_port = htons(PORT);
 int a = inet_pton(AF_INET,"172.217.167.110", &(address.sin_addr));
  if(a<0){
    perror("invalid address");
    exit(-1);
  }
  if(connect(sockfd,(struct sockaddr *)&address, (socklen_t)addlen)<0){
    perror("connection failed");
    exit(-1);
  }
  sprintf(sendline,"GET / HTTP/1.1\r\n\r\n");
  sendbytes = strlen(sendline);
  if(write(sockfd, sendline,sendbytes)!=sendbytes){
    perror("write error");
    exit(-1);
  }
  memset(rval,0,MAXLINE);
  if((n=read(sockfd,rval,MAXLINE-1))>0){
    printf("%s",rval);
  }
  if(n<0){
    perror("read failed");
    exit(-1);
  }
  return 0;
}
