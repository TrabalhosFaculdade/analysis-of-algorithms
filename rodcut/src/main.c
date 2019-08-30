#include <stdlib.h>
#include <stdio.h>

#include "rod.h"

#define RODS_SIZES 8

int main()
{

    int values[] = {1, 5, 8, 9, 10, 17, 17, 70}; 
    
    for (int i = 0; i < 8; i++)
    {
        int result = cutrod(values, i);
        printf("Solution for size %d: %d\n", i, result);
    }

    exit(EXIT_SUCCESS);
}