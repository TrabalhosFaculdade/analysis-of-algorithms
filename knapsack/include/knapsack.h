#ifndef KNAPSACK
#define KNAPSACK

typedef struct
{
    int value;
    int weigth;
} box_t;

typedef struct
{
    box_t *boxes;
    int quantity;
} options_t;

int max_value(box_t *boxes, int weightlimit, int n);

#endif