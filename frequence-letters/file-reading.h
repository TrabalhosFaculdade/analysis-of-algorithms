#ifndef FILE_READING
#define FILE_READING

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

char *nextline(FILE *file, int maxNumChars);
bool eof(FILE *file);

#endif