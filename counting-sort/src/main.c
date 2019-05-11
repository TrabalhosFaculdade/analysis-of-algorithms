#include <stdlib.h>
#include <stdio.h>

#include "countingsort.h"

#define DEBUG

#define SIZE 50
#define MIN_VALUE 0
#define MAX_VALUE 100

int *init_random_array(int num_values, int lower_value, int upper_value);
void print_array(array_t *array);

int main()
{
    array_t array;
    array.values = init_random_array(SIZE, MIN_VALUE, MAX_VALUE);
    array.size = SIZE;
    array.min_value = MIN_VALUE;
    array.max_value = MAX_VALUE;

#ifdef DEBUG
    print_array(&array);
#endif

    sort(&array);

#ifdef DEBUG
    print_array(&array);
#endif

    free(array.values);
    exit(EXIT_SUCCESS);
}

int *init_random_array(int num_values, int lower_value, int upper_value)
{
    int *values = malloc(sizeof(int) * num_values);
    if (values == NULL)
    {
        perror("Error while allocating memory for random numbers");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_values; i++)
    {
        int n = n = rand() % upper_value + lower_value;
        values[i] = n;
    }

    return values;
}

void print_array(array_t *array)
{
    for (int i = 0; i < array->size; i++)
        printf("%d ", array->values[i]);

    printf("\n");
}