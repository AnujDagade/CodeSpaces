#include <stdio.h>


typedef struct process
{
    int burst_time, start_time, arrival_time, end_time, turn_time, waiting_time;
    char pname[10];


}*processes, pr;

void get_jobs(processes *proc, int pnum)
{   printf("pname, ArrTime, BurstTime\n");
    for(int i=0; i<pnum; i++)
    {
        scanf("%s %d %d",proc[i]->pname, &proc[i]->arrival_time, &proc[i]->burst_time);
    }
}

void waiting_time();