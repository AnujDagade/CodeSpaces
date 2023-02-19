#include <stdio.h>

#define N 5
#define M 3

int allocation[N][M] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
int max[N][M] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
int available[M] = {3, 3, 2};
int need[N][M];

void calculate_need() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

int is_safe(int processes[], int num_processes) {
    int work[M];
    for (int i = 0; i < M; i++) {
        work[i] = available[i];
    }

    int finish[N] = {0};
    int count = 0;

    while (count < num_processes) {
        int found = 0;
        for (int i = 0; i < num_processes; i++) {
            if (!finish[processes[i]]) {
                int j;
                for (j = 0; j < M; j++) {
                    if (need[processes[i]][j] > work[j])
                        break;
                }
                if (j == M) {
                    for (int k = 0; k < M; k++) {
                        work[k] += allocation[processes[i]][k];
                    }
                    finish[processes[i]] = 1;
                    found = 1;
                    count++;
                }
            }
        }
        if (!found) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int processes[] = {0, 1, 2, 3, 4};
    calculate_need();
    if (is_safe(processes, N)) {
        printf("The system is in safe state\n");
    } else {
        printf("The system is in unsafe state\n");
    }
    return 0;
}
