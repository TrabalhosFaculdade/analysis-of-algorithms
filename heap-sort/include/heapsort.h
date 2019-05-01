#ifndef HEAP_SORT
#define HEAP_SORT

typedef struct
{
    int *values;
    int arraysize;
    int heapsize;
} heap_t;

void heapify (heap_t * heap, int index);
void build_max_heap (heap_t * heap);
void sort (heap_t *heap);

#endif