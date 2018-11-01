#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <string.h>
#define UNIX_PATH_MAX 100
#define ADDRESS "mysocket"
int main(void)
{
 struct sockaddr_un address;
 int  socket_fd, nbytes;
 char buffer[256],buffer2[256];
 socket_fd = socket(PF_UNIX, SOCK_STREAM, 0);
 if(socket_fd < 0)
 {
  printf("socket() failed\n");
  return 1;
 }

 memset(&address, 0, sizeof(struct sockaddr_un));
 address.sun_family = AF_UNIX;
strcpy(address.sun_path, ADDRESS);
 if(connect(socket_fd,(struct sockaddr *) &address,sizeof(struct sockaddr_un)) != 0)
 {
  printf("connect() failed\n");
  return 1;
 }
 nbytes = snprintf(buffer, 256, "welcome");
 write(socket_fd, buffer, nbytes);
 nbytes = read(socket_fd, buffer2, 256);
 buffer[nbytes] = 0;
 printf("MESSAGE FROM SERVER: %s\n", buffer2);
 close(socket_fd);
 return 0;
}
