#ifndef DINAMICALLY_SIZED_ARRAY
#define DINAMICALLY_SIZED_ARRAY

#include <stdlib.h>

#define MAX_NUMBER_CHARACTERS 5000

/**
 * This is an struct that stores a pointer of pointer
 * to be navigated using its size, that defines
 * how much memory was stored for the array values.
*/
typedef struct
{
    char **array;
    size_t used;
    size_t size;
} Array;

void initArray(Array *a, size_t initialSize);
void insertInto(Array *a, char *element);
void freeArray(Array *a);
void printArray(Array *a);

#endif