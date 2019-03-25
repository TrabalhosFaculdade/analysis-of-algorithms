
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "phrases-file-reading.h"
#include "file-reading.h"

#define READING_MODE "r"

void readFileInto(Array *a, char filename[])
{
    initArray(a, 5); //5: initial size
    FILE *file;

    file = fopen(filename, READING_MODE);
    if (file == NULL)
    {
        perror("Error while opening file");
        return;
    }

    while (!feof(file))
    {
        char *line = nextline(file, MAX_NUMBER_CHARACTERS);
        insertInto(a, line);
    }

    fclose(file);
}