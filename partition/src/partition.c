#include <stdlib.h>
#include "partition.h"

#define INITIAL_SIZE 5
#define GROWTH_RATE 5

void partition(int numbers[], int size)
{
    //initing values
    partition_side left, right;
    left.side_size = right.side_size = INITIAL_SIZE;
    left.side_used = right.side_used = 0;
    left.values = (int *)malloc(sizeof(int) * left.side_size);
    right.values = (int *)malloc(sizeof(int) * right.side_size);

    int pivot_value = numbers[0];

    for (int i = 1; i < size; i++)
    {
        if (numbers[i] <= pivot_value)
            add_value_partition_side(&left, numbers[i]);
        else
            add_value_partition_side(&right, numbers[i]);
    }

    int index = 0;
    int left_index, right_index;
    for (left_index = 0; left_index < left.side_used; left_index++, index++)
        numbers[left_index] = left.values[left_index];

    numbers[index++] = pivot_value;

    for (right_index = 0; right_index < right.side_used; right_index++, index++)
        numbers[index] = right.values[right_index];
}

void add_value_partition_side(partition_side *side, int new_value)
{
    //no space left on array
    //needs to realocate, increase size
    if (side->side_used >= side->side_size)
    {
        side->side_size += GROWTH_RATE;
        side->values = (int *)realloc(side->values, sizeof(int) * side->side_size);
    }

    side->values[side->side_used++] = new_value;
}