#include <stdlib.h>
#include <stdio.h>

#include "fibonacci.h"

#define DEBUG
#define VALUE 20

int *initialize(int n)
{
    if (n < 0)
    {
        perror("Trying to initialize an array with a negative amount of values");
        return NULL;
    }

    int *values = malloc(sizeof(int) * n);

    if (values == NULL)
    {
        perror("error while trying to initialize array for the memoization values");
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        values[i] = UNDEFINED_RESULT;
    }

    return values;
}

int main()
{
    int *memo = initialize(VALUE + 1);
    if (memo == NULL)
    {
        perror("Error while trying to initialize array, nothing to do.");
        exit(EXIT_FAILURE);
    }

    int dinamicCounter, naiveCounter;
    dinamicCounter = naiveCounter = 0;

    int dinamicResult = dinamic(VALUE, memo, &dinamicCounter);
    printf("Calculated dinamic result: %d, number of calls: %d\n", dinamicResult, dinamicCounter);

    int naiveResult = naive(VALUE, &naiveCounter);
    printf("Calculated value: %d, number of calls: %d\n", naiveResult, naiveCounter);

    free(memo);
}