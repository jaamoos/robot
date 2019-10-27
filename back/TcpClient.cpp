#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

#include "Protocol.h"

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Usage: %s <server ip>\n\n", argv[0]);
    return 1;
  }

  int sockFd = 0, n = 0;
  char recvBuff[1024];

  struct sockaddr_in address;
  memset(recvBuff, '0', sizeof(recvBuff));
  
  if ((sockFd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("Error: Could not create socket\n\n");
    return 1;
  }

  memset(&address, '0', sizeof(address));
  address.sin_family = AF_INET;
  address.sin_port = htons(5000);

  if (inet_pton(AF_INET, argv[1], &address.sin_addr) <= 0) {
    printf("Error: inet_pton error occuried\n\n");
    return 1;
  }

  if (connect(sockFd, (struct sockaddr *) &address, sizeof(address)) < 0) {
    printf("Error: connect failed\n\n");
    return 1;
  }

  /*
  while (n = read(sockFd, recvBuff, sizeof(recvBuff) - 1) > 0) {
      recvBuff[n] = 0;
      if (fputs(recvBuff, stdout) == EOF) {
	printf("Error: fputs error\n\n");
      }
  }
  */

  struct Request request;

  request.command = COMMAND_RUN;
  printf("Sending run command\n");
  write(sockFd, &request, sizeof(request));
  sleep(1);

  request.command = COMMAND_STOP;
  printf("Sending stop command\n");
  write(sockFd, &request, sizeof(request));

  request.command = COMMAND_CLOSE;
  printf("Sending close command\n");
  write(sockFd, &request, sizeof(request));

  close(sockFd);

    /*
  if (n < 0) {
    printf("Error: Read error\n\n");
  }
    */

  return 0;
}
