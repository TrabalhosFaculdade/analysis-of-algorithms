#include <stdlib.h>
#include <stdio.h>
#include "knapsack.h"

#define QUANTITY 3

box_t *initializeboxes()
{
    box_t a = {
        .value = 60,
        .weigth = 10
    };

    box_t b = {
        .value = 100,
        .weigth = 20
    };

    box_t c = {
        .value = 120,
        .weigth = 30
    };

    box_t *boxes = malloc(sizeof(box_t) * QUANTITY);
    if (boxes == NULL)
        exit(EXIT_FAILURE);

    boxes[0] = a;
    boxes[1] = b;
    boxes[2] = c;

    return boxes;
}

int main()
{
    box_t * boxes = initializeboxes();

    for (int weightlimit = 10; weightlimit < 70; weightlimit+= 10)
        printf("Result for %d: %d\n", weightlimit, max_value(boxes, weightlimit, QUANTITY));
    
    free(boxes);
    exit(EXIT_SUCCESS);
}