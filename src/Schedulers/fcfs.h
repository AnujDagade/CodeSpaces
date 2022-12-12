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
    proc[0].end_time = proc[0].burst_time;
}

float waiting_time(int pnum, bool display_time)
{
    //Start time - arrival time
    float avg_wait_times, wait_times=0.0f;

    for(int i=1; i<pnum; i++)
    {
        //proc[i].start_time = proc[i-1].waiting_time+proc[i-1].burst_time;
        proc[i].start_time = proc[i-1].start_time+proc[i-1].burst_time;
        proc[i].waiting_time = proc[i].start_time-proc[i].arrival_time;

        wait_times += proc[i].waiting_time;
    }

    if(display_time)
    {
        printf("pn\tWaiting time\n");
        for (int i=0; i<pnum; i++) {
            printf("%s\t%d\n",proc[i].pname,proc[i].waiting_time);
        }
        printf("Total waiting time is %fs\n",wait_times);
    }
    avg_wait_times = wait_times/pnum;

    return avg_wait_times;
}


float turnaround_time(int pnum)
{
    //Ending time - Arrival time

    float total_turn_time =0.0f, avg_turn_time = 0.0f;

    for(int i=1; i<pnum; i++)
    {
        proc[i].end_time = proc[i].start_time+proc[i].burst_time;
        proc[i].turn_time = proc[i].end_time - proc[i].arrival_time;
    }
}
