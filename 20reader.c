#include<stdio.h>
#include<fcntl.h>
#include<sysstat.h>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
#include<unistd.h>
#define MAX_BUF 1024
int main()
{
int fd;
char * tmp = "/tmp/fifo";
char buf[MAX_BUF];
fd = open(tmp, O_RDONLY);
read(fd, buf, MAX_BUF);
printf("Received: %s\n", buf);
close(fd);
return 0;
}
