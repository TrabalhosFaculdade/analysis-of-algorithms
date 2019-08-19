#include <stdlib.h>
#include <stdio.h>

#include "fibonacci.h"

int dinamic(int n, int *memo)
{
    if (n < 0)
    {
        perror("Error. Trying to calculate fibonacci of a negative number");
        return -1;
    }

    if (n == 0)
        return 0;

    if (n == 1 || n == 2)
        return 1;

    if (memo[n] == UNDEFINED_RESULT)
        memo[n] = dinamic(n - 1, memo) + dinamic(n - 2, memo);

    return memo[n];
}

int naive(int n)
{
    if (n < 0)
    {
        perror("Error. Trying to calculate fibonacci of a negative number");
        return -1;
    }

    if (n == 0)
        return 0;

    if (n == 1 || n == 2)
        return 1;

    return naive(n - 1) + naive(n - 2);
}