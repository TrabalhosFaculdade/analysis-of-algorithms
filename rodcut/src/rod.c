#include <stdlib.h>
#include <limits.h>

#include "rod.h"

int max(int a, int b) { return (a > b) ? a : b; }

int cutrod(int values[], int wantedsize)
{
    if (wantedsize <= 0)
        return 0; //length 0 is not part of the wanted solution

    int maxvalue = INT_MIN;
    for (int i = 0; i < wantedsize; i++)
        maxvalue = max(maxvalue, values[i] + cutrod(values, wantedsize - i - 1));

    return maxvalue;
}
