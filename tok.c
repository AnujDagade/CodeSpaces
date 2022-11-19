#include <stdio.h>
#include <string.h>

void tok(char *str, char *tok[])
{
    char *p;
    p = strtok(str, " ");
    printf("%s", p);
}


int main() 
{
    char in[80];
    char *arg[10];

    printf("Enter: ");
    scanf("%s",&in);

    tok(in, arg);

    return 0;

}

