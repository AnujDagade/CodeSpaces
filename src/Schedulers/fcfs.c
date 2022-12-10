#include "fcfs.h"


int main()
{

    processes proc[3];

    get_jobs(proc, 3);

    printf("pname, ArrTime, BurstTime\n");
    for(int i=0; i<3; i++)
    {
        printf("%s %d %d",proc[i]->pname, proc[i]->arrival_time, proc[i]->burst_time);
    }


    return 0;
}