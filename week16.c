#include<stdio.h>
#include<fcntl.h>
void main()
{
pid_t pid;
pid=fork();
if(pid==-1)
printf("failed to fork");
else if(pid==0)
printf("Iam child process my id is:%d and my parent id is %d\n",getpid(),getppid());
else
printf("Iam parent process my id is :%d\n",getpid());
}
