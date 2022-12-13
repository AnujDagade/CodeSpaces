#include <stdio.h>
#include <stdbool.h>

typedef struct process
{
    int burst_time, start_time, arrival_time, end_time, turn_time, waiting_time;
    char pname[10];

} processes;

processes proc[20], temp;
int total_arrival_time = 0;

void get_jobs(int pnum)
{
    printf("pname, ArrTime, BurstTime\n");
    for (int i = 0; i < pnum; i++)
    {
        scanf("%s %d %d", proc[i].pname, &proc[i].arrival_time, &proc[i].burst_time);
        total_arrival_time += proc[i].arrival_time;
    }
}

void show_jobs(int pnum)
{
    printf("pname Arrival time Burst time\n");
    for (int i = 0; i < pnum; i++)
    {
        printf("%s\t%d\t%d\n", proc[i].pname, proc[i].arrival_time, proc[i].burst_time);
    }
}

void sort(int pnum)
{

    int start_proc = total_arrival_time > 0 ? 1 : 0;

    for (int i = start_proc; i < pnum - 1; i++)
    {
        for (int j = start_proc; j < pnum - i - 1; j++)
        {
            if (proc[j].burst_time > proc[j + 1].burst_time)
            {
                temp = proc[j + 1];
                proc[j + 1] = proc[j];
                proc[j] = temp;
            }
        }
    }

    // if (total_arrival_time > 0)
    // {
    //     for (int i = 1; i < pnum - 1; i++)
    //     {
    //         for (int j = 1; j < pnum - i - 1; j++)
    //         {
    //             if (proc[j].burst_time > proc[j + 1].burst_time)
    //             {
    //                 temp = proc[j + 1];
    //                 proc[j + 1] = proc[j];
    //                 proc[j] = temp;
    //             }
    //         }
    //     }
    // }
    // else
    // {
    //     for (int i = 0; i < pnum - 1; i++)
    //     {
    //         for (int j = 0; j < pnum - i - 1; j++)
    //         {
    //             if (proc[j].burst_time > proc[j + 1].burst_time)
    //             {
    //                 temp = proc[j + 1];
    //                 proc[j + 1] = proc[j];
    //                 proc[j] = temp;
    //             }
    //         }
    //     }
    // }
}

void boot()
{
    proc[0].start_time = 0;
    proc[0].waiting_time = 0;
    proc[0].turn_time = proc[0].burst_time;
}

float waiting_time(int pnum, bool display_time)
{
    float avg_wait_time, wait_times = 0.0f;

    for (int i = 1; i < pnum; i++)
    {
        proc[i].start_time = proc[i - 1].start_time + proc[i - 1].burst_time;
        proc[i].waiting_time = proc[i].start_time - proc[i].arrival_time;
        wait_times += proc[i].waiting_time;
    }

    if (display_time)
    {
        printf("pn\tWaiting time\n");
        for (int i = 0; i < pnum; i++)
        {
            printf("%s\t%d\n", proc[i].pname, proc[i].waiting_time);
        }
        printf("Total waiting time is %fs\n", wait_times);
    }

    avg_wait_time = wait_times / pnum;
    return avg_wait_time;
}

float turn_time(int pnum, bool display_time)
{
    float total_turn_time = (float)proc[0].turn_time, avg_turn_time = 0.0f;

    for (int i = 0; i < pnum; i++)
    {
        proc[i].end_time = proc[i].start_time + proc[i].burst_time;
        proc[i].turn_time = proc[i].end_time - proc[i].arrival_time;
        total_turn_time += proc[i].turn_time;
    }
    if (display_time)
    {
        printf("pn\tTurnaround time\n");
        for (int i = 0; i < pnum; i++)
        {
            printf("%s\t%d\n", proc[i].pname, proc[i].turn_time);
        }
        printf("Total Turnaround time is %fs\n", total_turn_time);
    }

    avg_turn_time = total_turn_time / pnum;

    return avg_turn_time;
}