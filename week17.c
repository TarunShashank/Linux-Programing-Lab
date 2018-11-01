#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
pid_t pid=fork();
if(pid>0)
{
sleep(10);
printf("parent process looking for terminated process\n");
}
else if(pid==0)
{
printf("child is terminated\n");
exit(0);
}
else
printf("fork() is unsuccessful");
return 0;
}
