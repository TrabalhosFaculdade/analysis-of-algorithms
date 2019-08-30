#include <stdlib.h>
#include "rod.h"

int cutrod(int values[], int wantedsize)
{
    if (wantedsize <= 0)
        return 0;

    int maxvalue = -1;
    for (int i = 0; i <= wantedsize; i++)
    {
        int temp = values[i] + cutrod(values, wantedsize - i - 1);
        if (maxvalue <= temp) maxvalue = temp;
    }

    return maxvalue;
}
