#include<stdio.h>
void main()
{
int pid;
printf("Iam the original process with PID:%d and PPID:%d\n",getpid(),getppid());
pid=fork();
if(pid!=0)
{
printf("Iam the parent with PID:%d and PPID:%d\n",getpid(),getppid());
printf("my child's PID is %d\n",pid);
}
else
{
sleep(4);
printf("I'm the child with PID:%d and PPID:%d \n",getpid(),getppid());
}
printf("PID:%d terminated\n",getpid());
}
