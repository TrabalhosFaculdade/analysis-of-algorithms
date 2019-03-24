#include <stdio.h>
#include <string.h>

#include "dinamically-sized-array.h"
#include "phrases-file-reading.h"

/**
 * TODO separate file reading into a separated function
 * 
*/

int main()
{
    Array a;
    readFileInto(&a, "phrases.txt");

    printArray(&a);
    return 0;
}
