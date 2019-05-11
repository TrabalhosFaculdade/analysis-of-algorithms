#ifndef COUNTING_SORT
#define COUNTING_SORT

typedef struct
{
    int *values;
    int size;
    int min_value;
    int max_value;
} array_t;

void sort(array_t *array);

#endif