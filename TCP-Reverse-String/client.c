
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

char reverse(char s[])
{
  int c, i, j;
  for (i = 0, j = strlen(s)-1; i < j; i++, j--) 
  {
	c = s[i];
	s[i] = s[j];
	s[j] = c;
  }
  //printf("Data reverses : %s",s);
}

int main(){
  int clientSocket;int i, newSocket;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;

  clientSocket = socket(PF_INET, SOCK_STREAM, 0);

  serverAddr.sin_family = AF_INET;

  serverAddr.sin_port = htons(7891);

  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  addr_size = sizeof serverAddr;
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

  recv(clientSocket, buffer, 1024, 0);

  printf("Data received: %s",buffer);

 
  reverse(buffer);
 
  send(clientSocket,buffer,13,0);
  return 0;
}
