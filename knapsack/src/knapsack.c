#include <stdlib.h>
#include <stdio.h>
#include "knapsack.h"

int max(int a, int b) { return (a > b) ? a : b; }

int max_value(box_t *boxes, int weightlimit, int n)
{
    if (n == 0 || weightlimit == 0)
        return 0;

    box_t lastitem = boxes[n - 1];

    if (lastitem.weigth > weightlimit)
        return max_value(boxes, weightlimit, n - 1);

    int includinglastitem = lastitem.value + max_value(boxes, weightlimit - lastitem.weigth, n - 1);
    int excludinglastitem = max_value(boxes, weightlimit, n - 1);

    return max(includinglastitem, excludinglastitem);
}