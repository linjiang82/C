#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#define MAXCHAR 80
#define PORT 2000
#define CLIENTNUMBER 10

int main(int argc, char *argv[]) {
  typedef struct {
    int cId;
    struct sockaddr_in client_addr;
  } clientStruct;
  int sockfd;
  int idx = 0;
  clientStruct clients[CLIENTNUMBER];

  // setup defaultAdd and defaultClient and init the client array;
  struct sockaddr_in server_addr, client_addr, defaultAdd;
  defaultAdd.sin_family = AF_INET;
  defaultAdd.sin_addr.s_addr = inet_addr("0.0.0.0");
  defaultAdd.sin_port = htons(0);
  clientStruct defaultClient = {.cId = -1, .client_addr = defaultAdd};
  for (int i = 0; i < CLIENTNUMBER; i++) {
    clients[i] = defaultClient;
  }
  int len = sizeof(client_addr);
  char client_message[MAXCHAR], server_message[MAXCHAR];
  memset(client_message, '\0', MAXCHAR);
  memset(server_message, '\0', MAXCHAR);
  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
    perror("Create socket failed");
    exit(-1);
  }
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  server_addr.sin_port = htons(PORT);
  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) ==
      -1) {
    perror("Create socket failed");
    exit(-1);
  }
  while (1) {
    if (recvfrom(sockfd, client_message, sizeof(client_message), 0,
                 (struct sockaddr *)&client_addr, (socklen_t *)&len) < 0) {
      printf("Couldn't receive\n");
      return -1;
    }
    printf("Received message from IP: %s and port: %i\n",
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    for (int i = 0; i < CLIENTNUMBER; i++) {
      // if cId==-1, add a new Item, and break;
      /*printf("%s\n", inet_ntoa(clients[i].client_addr.sin_addr));*/
      /*printf("%i\n", ntohs(clients[i].client_addr.sin_port));*/
      /*printf("%i\n", clients[i].cId);*/
      if (clients[i].cId == -1) {
        clients[i].cId = idx++;
        clients[i].client_addr = client_addr;
        break;
      } else if (strcmp(inet_ntoa(clients[i].client_addr.sin_addr),
                        inet_ntoa(client_addr.sin_addr)) == 0 &&
                 ntohs(clients[i].client_addr.sin_port) ==
                     ntohs(client_addr.sin_port))
      // record alread exists, break;
      {
        break;
      }
    }
    printf("%s\n", client_message);

    // Get input from the user:
    printf("Enter message: ");
    gets(server_message);
    printf("%s\n", server_message);
    sendto(sockfd, server_message, sizeof(server_message), 0,
           (struct sockaddr *)&client_addr, len);
  }
}
