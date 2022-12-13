#include "sjf_np.h"
#define SHOW_EXTRA_TIME_INFO true

int main()
{

    float avg_wait, avg_turn;

    get_jobs(4);
    sort(4);
    show_jobs(4);

    avg_wait = waiting_time(4, SHOW_EXTRA_TIME_INFO);

    avg_turn = turn_time(4, SHOW_EXTRA_TIME_INFO);

    printf("Average waiting time is %fs\n", avg_wait);
    printf("Average turnaround time is %fs\n", avg_turn);

    return 0;
}