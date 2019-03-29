
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
        perror("Error while opening phrases file");
        return;
    }

    while (!feof(file))
    {
        char *line = nextline(file, MAX_NUMBER_CHARACTERS);
        insertInto(a, line);
    }

    fclose(file);
}

void readAlphabetInto(RawFrequenceLetter *frequences, char alphabetfilename[])
{
    FILE *alphabetfile;
    alphabetfile = fopen(alphabetfilename, READING_MODE);
    if (alphabetfile == NULL || feof(alphabetfile))
    {
        perror("Error while opening alphabet file");
        return;
    }

    int i;
    char *alphabetchars;

    alphabetchars = nextline(alphabetfile, LETTERS_ALPHABET);
    for (i = 0; i < LETTERS_ALPHABET; i++)
    {
        frequences[i].letter = alphabetchars[i];
        frequences[i].frequence = 0;
    }
}

void readFrequencesInto(Frequence *frequence,
                        char filename[],
                        char alphabetfilename[],
                        char languagename[])
{
    FILE *alphabetfile;
    alphabetfile = fopen(alphabetfilename, READING_MODE);
    if (alphabetfilename == NULL)
    {
        perror("Error while opening alphabet file");
        return;
    }

    if (feof(alphabetfile))
    {
        perror("Alphabet is not defined in informed file");
        return;
    }

    FILE *frequencelanguagefile;
    frequencelanguagefile = fopen(filename, READING_MODE);
    if (frequencelanguagefile == NULL)
    {
        perror("Error while opening frequence file");
        return;
    }

    char *alphabetchars = nextline(alphabetfile, LETTERS_ALPHABET);
    unsigned int i = 0;

    while (!feof(frequencelanguagefile))
    {
        FrequenceLetter letter;
        letter.letter = alphabetchars[i];
        letter.percentageOccurrence = nextfloat(frequencelanguagefile);

        frequence->lettersInLanguage[i++] = letter;
    }

    frequence->languageName = languagename;
}