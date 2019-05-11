#include <stdlib.h>
#include <stdio.h>
#include "countingsort.h"

void sort(array_t *array)
{
    if (array->min_value > array->max_value)
    {
        perror("Invalid state. min_value on array is bigger than max_value");
        exit(EXIT_FAILURE);
    }

    int size, returning_index;
    int *aux_array = NULL;

    //creating aux_array with the numbers of necessary positions
    //intializing all of them with 0
    size = (array->max_value - array->min_value + 1);
    aux_array = (int *)calloc(size, sizeof(int));
    if (aux_array == NULL)
    {
        perror("Error while initializing auxiliary array");
        exit(EXIT_FAILURE);
    }

    //couting how many values are there for each position
    for (int i = 0; i < array->size; i++)
    {
        int position = abs(array->min_value - array->values[i]);
        aux_array[position]++;
    }

    //putting values back to its original array
    returning_index = 0;
    for (int i = 0; i < size; i++)
    {
        int value = array->min_value + i;
        for (int j = 0; j < aux_array[i]; j++)
            array->values[returning_index++] = value;
    }

    free(aux_array);
}