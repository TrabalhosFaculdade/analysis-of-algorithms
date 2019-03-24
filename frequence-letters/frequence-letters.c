#include <stdio.h>
#include <string.h>

#include "dinamically-sized-array.h"

#define FILE_NAME "phrases.txt"
#define READING_MODE "r"

/**
 * TODO separate file reading into a separated function
 * 
*/

int main()
{
    Array a;
    initArray(&a, 5); //5: initial size

    char ch;
    FILE *file;

    file = fopen(FILE_NAME, READING_MODE);
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
            insertInto(&a, line);
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

    insertInto(&a, line);

    printArray(&a);
    freeArray(&a);

    fclose(file);
    return 0;
}
