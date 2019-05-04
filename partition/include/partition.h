#ifndef PARTITION
#define PARTITION

typedef struct
{
    int side_size;
    int side_used;
    int *values;
} partition_side;

void partition(int numbers[], int index);
void add_value_partition_side(partition_side *side, int new_value);

#endif