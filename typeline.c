#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
    
int cnt =0; 

void make_toks(char *s,char *tok[])
{
	int i=0;
	char *p;
  	p=strtok(s," ");
  	while(p!=NULL)
	{
  		tok[i++]=p;
  		p=strtok(NULL," ");
	}
  	tok[i]=NULL;
}


void typeline(char *fn,char *op)
{
  	int fh;
	
	int n = atoi(op);
  	char c;
  	fh=open(fn,O_RDONLY);
  	if(fh==-1)
	{
  		printf("file %s not found.\n",fn);
  		return;
	}
 
  
	 if(isdigit(*op))
	{
		cnt = 0;
		while((read(fh,&c,1)>0))
		{
			if(c == '\n')
			{
				cnt++;
				if(cnt == n)
				{
					return;
				}
			}
 			printf("%c",c);
			
		}
	}
	else if(*op == 'a')
	{
		while((read(fh,&c,1)>0))
		{
			printf("%c",c);
		}
	}

	close(fh);
  	
	
}

int main()
{
  char buff[80],*args[10];
  int pid;

  while(1)
{
    printf("\n myshell$");
    fflush(stdin);
    fgets(buff,80,stdin);
    buff[strlen(buff)-1]='\0';
    make_toks(buff,args);

   if(strcmp(args[0],"typeline")==0)
   	typeline(args[2],args[1]);
   else
   {
    	pid=fork();
	if(pid>0)
    	wait();
   else
   {
     if(execvp(args[0],args)==-1)
     printf("Bad command.\n");
   }
  }

}
	return 0;
}