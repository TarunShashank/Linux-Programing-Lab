#define MAX_NUM_ARGS 30
#include<stdio.h>
#include<stdlib.h>
int main()
{
int fd[2],pid,k;
char *lsargs[MAX_NUM_ARGS]={"ls","-l",NULL};
char *sortargs[MAX_NUM_ARGS]={"sort",NULL};
k=pipe(fd);
if(k==-1)
{
perror("pipe");
exit(1);
}
pid=fork();
if(pid==0)
{
printf("child executing ls command \n");
close(fd[0]);
dup2(fd[1], 1);
close(fd[1]);
execvp("ls",lsargs);
// perror("execvp");
}
else
{
wait(2);
close(fd[1]);
dup2(fd[0],0);
close(fd[0]);
printf("parent sorting child output\n");
execvp("sort", sortargs);
//perror("execvp");
}
}
