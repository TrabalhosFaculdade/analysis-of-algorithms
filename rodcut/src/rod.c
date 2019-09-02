#include <stdlib.h>
#include <limits.h>

#include "rod.h"

int max(int a, int b) { return (a > b) ? a : b; }

/**
 * Complexity for naive solution: 2 ^ n
*/
int cutrod(int values[], int wantedsize, int *count)
{
    (*count)++;

    if (wantedsize <= 0)
        return 0; //length 0 is not part of the wanted solution

    int maxvalue = INT_MIN;
    for (int i = 0; i < wantedsize; i++)
        maxvalue = max(maxvalue, values[i] + cutrod(values, wantedsize - i - 1, count));

    return maxvalue;
}

int dinamic(int values[], int wantedsize, int *count, int *memo)
{
    (*count)++;

    if (wantedsize <= 0)
        return 0; //length 0 is not part of the wanted solution

    if (memo[wantedsize - 1] != UNDEFINED_RESULT)
        return memo[wantedsize - 1];

    int maxvalue = INT_MIN;
    for (int i = 0; i < wantedsize; i++)
        maxvalue = max(maxvalue, values[i] + dinamic(values, wantedsize - i - 1, count, memo));

    memo[wantedsize - 1] = maxvalue;

    return maxvalue;
}