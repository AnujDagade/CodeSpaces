#include<stdio.h>
void sort(int n);
struct process
{
    char pname[10];
    int at,bt,et,st,tat,awt,wt,twt;

}p[10],temp;

int i,j,n;

void sort(int n)
{
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[i].at>p[j].at)
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
}

main()
{
    int i,j,tat=0,twt=0,n;
    printf("enter the process no. of process:");
    scanf("%d",&n);
    printf("enter the process name:");



    for(i=0;i<n;i++)
    {
        scanf("%s",&p[i].pname);
    }

    printf("\n Enter the burst time:");


    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i].bt);
    }

    printf("\n Enter the Arrival time:");

    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i].at);
    }
    
    sort (n);
    p[0].st=0;
    p[0].et=p[0].bt;
    p[0].wt=p[0].st-p[0].at;
    p[0].tat=p[0].et-p[0].at;

    for(i=1;i<n;i++)
    {
        p[i].st=p[i-1].et;
        p[i].et=p[i-1].et+p[i].bt;
        p[i].wt=p[i-1].st-p[i].at;
        p[i].tat=p[i].et-p[i].at;
        twt=twt+p[i].wt;
        p[i].tat=p[i].et-p[i].at;
        tat=tat+p[i].tat;
    }

    printf("\n pname \t at \t bt \t st \t et \t twt \t tat \n");
    for(i=0;i<n;i++)
    {
        printf("\n");
        printf("p%d\t %d\t %d\t %d\t %d\t %d\t %d",p[i].pname,p[i].at,p[i].bt,p[i].st,p[i].et,p[i].wt,p[i].tat);

    }

    printf("\n");
    printf("The Gantt Chart is:");
    printf("0_");
    for(i=0;i<n;i++)
    {
        printf("p %d-%d",p[i].pname,p[i].et);
    }

    p[i].awt=twt/n;
    printf("\n Average wait time is:%d\t",p[i].awt);

    p[i].tat=tat/n;
     printf("\n Average turn around time is:%d\t",p[i].tat);

}
