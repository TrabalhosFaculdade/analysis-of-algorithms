#include <stdlib.h>
#include <stdio.h>

#include "rod.h"

int *initialize(int n)
{
    if (n < 0)
    {
        perror("Trying to initialize an array with a negative amount of values");
        exit(EXIT_FAILURE);
    }

    int *values = malloc(sizeof(int) * n);

    if (values == NULL)
    {
        perror("Error while trying to initialize array for the memoization values");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
        values[i] = UNDEFINED_RESULT;

    return values;
}

void testing(int values[], int length)
{
    for (int i = 1; i <= length; i++)
    {
        int naivecount = 0, dinamicount = 0;
        int *memo = initialize(length);

        int naiveresult = cutrod(values, i, &naivecount);
        int dinamicresult = dinamic(values, i, &dinamicount, memo);

        printf("Length %d\n", i);
        printf("Naive {result = %d; calls = %d}\n", naiveresult, naivecount);
        printf("Dinamic {result = %d; calls = %d}\n", dinamicresult, dinamicount);

        free(memo);
    }

    printf("\n");
}

int main()
{
    int test1[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int test2[] = {3, 5, 8, 9, 10, 17, 17, 20};

    testing(test1, 8);
    testing(test2, 8);

    exit(EXIT_SUCCESS);
}