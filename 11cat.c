#include<sys/types.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
main(int argc,char *argv[])
{
int fd,i;
char buf[2];
fd=open(argv[1],O_RDONLY);
if(fd==-1)
{
printf("file open error");
exit(1);
}
else
{
while(i=read(fd,buf,1)>0)
{
write(1,buf,i);
}
close(fd);
}
}
