#include "fcfs.h"
#include <stdio.h>


int main()
{

    int total_waiting_time;

    get_jobs(4);
    boot();
    total_waiting_time = waiting_time(4,true);
    
 
    printf("Total waiting time is %ds\n",total_waiting_time);

    return 0;
}