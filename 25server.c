#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#define UNIX_PATH_MAX 100
#define ADDRESS "mysocket"
#define MAXSIZE 1000
char reverse(char buff[]);
int main(void)
{
 struct sockaddr_un address;
 int socket_fd, cfd,n,i,k;
 socklen_t address_length;
 pid_t child;
char buff[MAXSIZE],buff2[100];
char rev[20];
 socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
 if(socket_fd < 0)
 {
  printf("socket() failed\n");
  return 1;
 }

 /* start with a clean address structure */
 memset(&address, 0, sizeof(struct sockaddr_un));
 address.sun_family = AF_UNIX;
strcpy(address.sun_path, ADDRESS);
unlink(address.sun_path);
if(bind(socket_fd,(struct sockaddr *) &address,sizeof(struct sockaddr_un)) != 0)
 {
  printf("bind() failed\n");
  return 1;
 }
 if(listen(socket_fd, 5) != 0)
 {
  printf("listen() failed\n");
  return 1;
 }

while((cfd = accept(socket_fd, (struct sockaddr *)&address,&address_length))> -1)
 {

read(cfd,buff,sizeof(buff2));
printf("\n");
printf("server Recieved client request %s",buff);

n=strlen(buff);
for(i=n;i>0;i--)
{
rev[k++]=buff[i-1];
}
rev[k]='\0';
printf("server processed client request %s",rev);

  write(cfd,rev,strlen(rev));

close(cfd);
 }
 close(socket_fd);
 return 0;
}



