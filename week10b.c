#include<stdio.h>
main(int argc,char *argv[])
{
char c;
FILE *fr,*fw;
fr=fopen(argv[1],"r");
fw=fopen(argv[2],"w");
if(fr==NULL||fw==NULL)
printf("can't do copying");
while(!feof(fr))
{
c=fgetc(fr);
fputc(c,fw);
}
printf("%s file copied into the %s \n",argv[1],argv[2]);
}
