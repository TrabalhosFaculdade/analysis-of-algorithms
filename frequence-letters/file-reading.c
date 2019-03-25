#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "file-reading.h"

char *nextline(FILE *file, int maxNumChars)
{
    char *line = malloc(sizeof(char) * maxNumChars);

    char fileChar;
    int currentChar = 0;
    bool reading = true;

    while ((fileChar = fgetc(file)) != EOF)
    {
        if (reading)
        {
            if (currentChar == (maxNumChars - 1))
                //reached the end of wanted characters
                //set reading to false to keep on reading until eof
                //-1 because we will fill the last value with \0
                reading = false;

            if (fileChar == '\n')
                //found the end of line
                //getting out of the loop to return value found
                break;

            line[currentChar] = fileChar;
            currentChar++;
        }
    }

    line[++currentChar] = '\0'; //to indicate the end of the string
    return line;
}

float nextfloat(FILE *file)
{
    float value;
    fscanf(file, "%f", &value);

    return value;
}