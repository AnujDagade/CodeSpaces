#include "fcfs.h"
#include <stdio.h>
#define SHOW_TOTAL_WAIT_TIME false

void fcfs();

int main()
{

    fcfs();

    return 0;
}

void fcfs() 
{
  float avg_waiting_time;

  get_jobs(4);
  boot();
  avg_waiting_time = waiting_time(4, SHOW_TOTAL_WAIT_TIME);

  printf("Average waiting time is %fs\n", avg_waiting_time);
  
}