#include "fcfs.h"
#include <stdio.h>
#define SHOW_EXTRA_TIME_INFO false

void fcfs();

int main()
{

    fcfs();

    return 0;
}

void fcfs() 
{
  float avg_waiting_time, avg_turn_time;

  get_jobs(4);
  boot();
  avg_waiting_time = waiting_time(4, SHOW_EXTRA_TIME_INFO);
  printf("Average waiting time is %fs\n", avg_waiting_time);

  avg_turn_time = turnaround_time(4,SHOW_EXTRA_TIME_INFO);
  printf("Average turnaround time is %fs\n", avg_turn_time);

  
}