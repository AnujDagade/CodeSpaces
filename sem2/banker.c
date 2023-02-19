#include <stdio.h>

int Available[4];
int Total[4] = {6, 5, 7, 6};
int Max[3][4] = {{3, 3, 2, 2}, {1, 2, 3, 4}, {1, 3, 5, 0}};
int Need[3][4] = {};
int Allocated[3][4] = {{1, 2, 2, 1}, {1, 0, 3, 3}, {1, 2, 1, 0}};

void calculateNeed()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            Need[i][j] = Max[i][j] - Allocated[i][j];
            
        }
        
    }
}

void printArray(int array[3][4])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf(" %d", array[i][j]);
        }
        printf("\n");
    }
}

void calculateAvailable()
{
}

int main()
{

    printf("Max: \n");
    printArray(Max);

    printf("Allocated: \n");
    printArray(Allocated);

    calculateNeed();
    printf("Need: \n");
    printArray(Need);

    return 0;
}