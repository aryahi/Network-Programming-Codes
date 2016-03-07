
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

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

  char name[10];
  printf("Type name of file to open : ");
  scanf("%s", name); 
  // input file used is in.txt
  // output file used is out.txt
  FILE *fp = fopen(name,"r");
  
  fgets(buffer,1024,fp);
  printf("Content of file : %s",buffer);

  //nBytes = strlen(buffer) + 1;

  //recv(clientSocket, buffer, 1024, 0);

  //printf("Data received: %s",buffer);
 
  send(clientSocket,buffer,1024,0);
  
  return 0;
}
