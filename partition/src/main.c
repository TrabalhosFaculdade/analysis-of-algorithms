#include <stdlib.h>
#include <stdio.h>

#include "partition.h"

#define ARRAY_SIZE 10

void print_array(int nums[])
{
    printf("[");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf(" %d ", nums[i]);
    }
    printf("]\n");
}

int main()
{
    int nums[] = {5, 7, 9, 4, 2, 10, 8, 1, 3, 3};
    print_array(nums);
    partition(nums, ARRAY_SIZE);
    print_array(nums);
    exit(EXIT_SUCCESS);
}