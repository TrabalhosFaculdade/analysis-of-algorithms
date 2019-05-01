#include "heapsort.h"

void sort(heap_t *heap)
{
    build_max_heap(heap);

    for (int i = heap->arraysize - 1; i > 0; i--)
    {
        int temp = *(heap->values);
        *(heap->values) = *(heap->values + i);
        *(heap->values + i) = temp;
        heap->heapsize = i;
        heapify(heap, 0);
    }
}

void build_max_heap(heap_t *heap)
{
    for (int i = heap->arraysize / 2 - 1; i > -1; i--)
        heapify(heap, i);
}

void heapify(heap_t *heap, int index)
{
    int largest = index;
    int left_index = 2 * index;
    int right_index = 2 * index + 1;

    if (left_index < heap->heapsize && *(heap->values + left_index) > * (heap->values + largest))
        largest = left_index;

    if (right_index < heap->heapsize && *(heap->values + right_index) > * (heap->values + largest))
        largest = right_index;

    if (largest != index)
    {
        int temp = *(heap->values + largest);
        *(heap->values + largest) = *(heap->values + index);
        *(heap->values + index) = temp;
        heapify(heap, largest);
    }
}