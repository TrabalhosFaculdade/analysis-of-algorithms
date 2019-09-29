#include <stdio.h>
#include <stdlib.h>
#include "selection.h"

/**
 * implements the behaviour of a grouwing list. 
 * Incrementing size using the value of the pointer
 * 
*/
void add(activity_t *group, activity_t newvalue, int *size);

/**
 * Assuming that activities passed as parameters 
 * are already sorted by ending time. Consider implementing 
 * some sorting algorithm
 * 
*/
selection_t select_activities(activity_t *group, int n)
{
    int addedactivities = 0;
    int lastendtime = 0;

    activity_t *selected = (activity_t *)malloc(sizeof(activity_t) * n);

    for (int i = 0; i < n; i++)
    {
        activity_t current = group[i];

        if (lastendtime <= current.start)
        {
            lastendtime = current.end;
            selected[addedactivities++] = current;
        }
    }

    selection_t selection = {
        .activities = selected,
        .n = addedactivities};

    return selection;
}

void add(activity_t *group, activity_t newvalue, int *size)
{
    group[(*size)++] = newvalue;
}