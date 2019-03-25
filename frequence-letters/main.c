#include <stdio.h>
#include <string.h>

#include "dinamically-sized-array.h"
#include "phrases-file-reading.h"

int main()
{
    Array a;
    readFileInto(&a, "phrases.txt");

    printArray(&a);
    return 0;
}
