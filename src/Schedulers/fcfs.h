#include <stdio.h>
#include <stdbool.h>


typedef struct process
{
    int burst_time, start_time, arrival_time, end_time, turn_time, waiting_time;
    char pname[10];


}processes;

processes proc[20];

void get_jobs(int pnum)
{   printf("pname, ArrTime, BurstTime\n");
    for(int i=0; i<pnum; i++)
    {
        scanf("%s %d %d",proc[i].pname, &proc[i].arrival_time, &proc[i].burst_time);
    }
}

void boot()
{
    proc[0].waiting_time = 0;
    proc[0].start_time = 0;
}

int waiting_time(int pnum, bool display_time)
{
    //Start time - arrival time
    int total_waiting_time = 0;

    for(int i=1; i<pnum; i++)
    {
        //proc[i].start_time = proc[i-1].waiting_time+proc[i-1].burst_time;
        proc[i].start_time = proc[i-1].start_time+proc[i-1].burst_time;
        proc[i].waiting_time = proc[i].start_time-proc[i].arrival_time;

        total_waiting_time += proc[i].waiting_time;
    }

    if(display_time)
    {
        printf("pn\tWaiting time\n");
        for (int i=0; i<pnum; i++) {
            printf("%s\t%d\n",proc[i].pname,proc[i].waiting_time);
        }
    }

    return total_waiting_time;
}

