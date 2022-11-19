#include <stdio.h>
#include <string.h>

void tok(char *str, char *toka[])
{
    char *p;
    char *to[10];
    int pos =0 ;
    p = strtok(str, " ");
    



    while(p != NULL) 
    {
        toka[pos] = p;
        pos++;
        p = strtok(NULL," ");

    }
    toka[pos] = NULL;

  
    //printf("%s", to);

}


int main() 
{
    char in[80];
    char *arg[10];

    printf("Enter: ");
    fflush(stdin);
    //canf("%s",&in);
    fgets(in,80,stdin);
    //in[strlen(in)-1] = '\0';
    tok(in, arg);

    printf("%s", arg[1]);

    return 0;

}

