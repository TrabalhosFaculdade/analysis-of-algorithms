
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dinamically-sized-array.h"

#define GROWING_RATE 2

/**
 * TODO encapsulate memory allocation into a separated function
 * 
*/

void initArray(Array *a, size_t initialSize)
{
    int size = initialSize * sizeof(char *);

    a->array = (char **)malloc(size);
    for (unsigned int i = 0; i < initialSize; i++)
    {
        a->array[i] = (char *)malloc(MAX_NUMBER_CHARACTERS * sizeof(char));
    }

    a->used = 0;
    a->size = initialSize;
}

void insertInto(Array *a, char *element)
{
    if (a->used == a->size)
    {
        a->size = a->size + GROWING_RATE;
        int allocSize = a->size * sizeof(char *);

        a->array = (char **)realloc(a->array, allocSize);
        for (unsigned int i = a->used; i < a->size; i++)
        {
            a->array[i] = (char *)malloc(MAX_NUMBER_CHARACTERS * sizeof(char));
        }
    }

    strcpy(a->array[a->used], element);
    a->used++;
}

void freeArray(Array *a)
{
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

void printArray(Array *a)
{

    printf("\nPrint array. Size: %lu, Used space: %lu\n", a->size, a->used);

    unsigned int i;
    for (i = 0; i < a->used; i++)
    {
        printf("%d = %s\n", i, a->array[i]);
    }
}