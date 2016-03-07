
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <ctype.h>


char count(char str[])
{
   int count = 0, c = 0, i, j = 0, k, space = 0;
   char p[100][100], str1[100], ptr1[100][100];
   char *ptr;
   printf("string length is %d\n", strlen(str));

   for (i = 0 ;i < strlen(str) ;i++)
   {
      if ((str[i] == ' ')||(str[i] == ', ')||(str[i] == '.'))
      {
         space++;
      }
   }

   for (i = 0, j = 0, k = 0;j < strlen(str);j++)
   {
      if ((str[j] == ' ')||(str[j] == 44)||(str[j] == 46))  
      {    
         p[i][k] = '\0';
         i++;
         k = 0;
      }        
      else
         p[i][k++] = str[j];
   }
   k = 0;
   
   for (i = 0;i <= space+1;i++)
   {
      for (j = 0;j <= space+1;j++)
      {
         if (i == j)
         {
            strcpy(ptr1[k], p[i]);
            k++;
            count++;
            break;
         }
         else
         {
         if(strcmp(ptr1[j], p[i]) != 0)
            continue;
         else
            break;
         }
      }
   }
   for (i = 0;i < count;i++) 
   {
      for (j = 0;j <= space+1;j++)
      {
         if(strcmp(ptr1[i], p[j]) == 0)
            c++;
      }
      printf("%s -> %d times\n", ptr1[i], c);
      c = 0;
   }
}

int main()
{
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
 
  count(buffer);
 
  //send(clientSocket,buffer,53,0);
  return 0;
}
