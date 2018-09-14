#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int c=0,w=1,l=1;
void count(char *name)
{
	FILE *fp=NULL;
	char a;
	fp=fopen(name,"r");
	if(fp==NULL)
	{
		printf("输入错误");
		_getch();
		exit(0);
	}
	while(!feof(fp))
	{
		a=fgetc(fp);
		if(a!=' '&&a!='\n'&&a!='\t'&&a!=','&&a!='.'&&a!='!'&&a!=';'&&a!='=')
		{
			c++;
		}
		else if(a==' '||a==','||a=='.'||a=='!'||a=='?'||a==';')
		{
			w++;
		}
		else if(a=='\n'||a=='\t')
		{
			w++;
			l++;
		}
		else if(a=EOF)break;
	}
	fclose(fp);
}
int main(int argc, char* argv[])
{
	
	FILE *fp;
	count(argv[2]);
    if(!strcmp(argv[1],"-c")) 
	printf("字符数：%d\n",c);
	else if(!strcmp(argv[1],"-w"))
	printf("词数：%d\n",w);
	else if(!strcmp(argv[1],"-l"))
	printf("行数：%d\n",l);
}
