
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "phrases-file-reading.h"

#define READING_MODE "r"

void readFileInto(Array *a, char filename[])
{
    initArray(a, 5); //5: initial size

    char ch;
    FILE *file;

    file = fopen(filename, READING_MODE);
    if (file == NULL)
    {
        perror("Error while opening the file.\n");
        return 1;
    }

    int currentChar = 0;
    char line[MAX_NUMBER_CHARACTERS];

    while ((ch = fgetc(file)) != EOF)
    {
        if (currentChar == MAX_NUMBER_CHARACTERS || ch == '\n')
        {
            insertInto(a, line);
            currentChar = 0;

            //clearing the array out by passig an empty string
            memset(line, 0, MAX_NUMBER_CHARACTERS);
        }
        else
        {
            line[currentChar] = ch;
            currentChar++;
        }
    }
    insertInto(a, line); //reading the lines that's leaft out
    fclose(file);
}