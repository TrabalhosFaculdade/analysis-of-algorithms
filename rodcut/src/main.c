#include <stdlib.h>
#include <stdio.h>

#include "rod.h"

void testing(int values[], int length)
{

    for (int i = 1; i <= length; i++)
    {
        int result = cutrod(values, i);
        printf("Solution for size %d: %d\n", i, result);
    }

    printf("\n");
}

int main()
{
    int test1[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int test2[] = {3, 5, 8, 9, 10, 17, 17, 20};

    testing(test1, 8);
    testing(test2, 8);

    exit(EXIT_SUCCESS);
}