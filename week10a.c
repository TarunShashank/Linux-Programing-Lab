#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[])
{
int source,destination,n;
char buf[256];
if(argc!=3)
{
printf("no sufficient arguments \n");
exit(1);
}
source=open(argv[1],O_RDONLY);
if(source==-1)
{
perror(argv[1]);
exit(1);
}
destination=open(argv[2],O_WRONLY|O_CREAT,0640);
if(destination==-1)
{
perror(argv[2]);
exit(1);
}
while((n=read(source,buf,sizeof(buf)))>0)
write(destination,buf,n);
printf("%s successfully copied to %s \n",argv[1],argv[2]);
}
