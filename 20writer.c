#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
int fd;
char *tmp = "/tmp/fifo";
mkfifo(tmp, 0666);
fd=open(tmp, O_WRONLY);
write(fd, "welcome", sizeof("welcome"));
close(fd);
return 0;
}                                       
