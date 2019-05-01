#include <stdlib.h>
#include <stdio.h>

#include "heapsort.h"

#define DEBUG

int *init_random_array(int num_values, int lower_value, int upper_value);
void print_heap(heap_t *heap);

int main()
{
    int size;
    heap_t heap;

    size = 100;
    heap.values = init_random_array(size, 0, 1000);
    heap.heapsize = size;
    heap.arraysize = size;

#ifdef DEBUG
    print_heap(&heap);
#endif

    sort(&heap);

#ifdef DEBUG
    print_heap(&heap);
#endif

    exit(EXIT_SUCCESS);
}

int *init_random_array(int num_values, int lower_value, int upper_value)
{
    int *values = malloc(sizeof(int) * num_values);
    for (int i = 0; i < num_values; i++)
    {
        int n = n = rand() % upper_value + lower_value;
        values[i] = n;
    }

    return values;
}

void print_heap(heap_t *heap)
{
    for (int i = 0; i < heap->arraysize; i++)
    {
        if (i == 0)
            printf("%d", heap->values[i]);
        else
            printf(", %d", heap->values[i]);
    }
    printf("\n \n \n");
}