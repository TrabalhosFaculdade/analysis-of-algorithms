
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "phrases-file-reading.h"
#include "file-reading.h"

#define READING_MODE "r"

/**
 * Initializes a dinamically growing Array, with the initial 
 * value of 5. The result is the lines, separated by "\0", gotten 
 * from the informed parameters.
 * 
*/
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
        //getting untill it reachs the end of the characters
        char *line = nextline(file, MAX_NUMBER_CHARACTERS);
        insertInto(a, line);
    }

    fclose(file);
}

/**
 * Receives as parameteres the frequence into which the initialized and clean 
 * will be placed, and the alphabet file path, which defines the characters of
 * the alphabet.
 * 
 * Uniqueness of the letters not checked, so watch out for what you write there.
 * The clean result that i mentioned earlier is simply the RawFrequenceLetter 
 * intialized with the corresponding character ocupping each positon, with the 
 * total values of appereaces as 0.
 * 
*/
void readAlphabetInto(RawFrequenceLetter *frequences, char alphabetfilename[])
{
    FILE *alphabetfile;
    alphabetfile = fopen(alphabetfilename, READING_MODE);

    //file not found, or the alphabet file is at its end, problably empty.
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

/**
 * Initializes the frequence struct from frequence file,
 * using the alphabet as the basics of structring 
 * 
 * Frequence 
 * -> language name;
 * -> List of Frequence letter:
 *      -> letter (value)
 *      -> percentageOccurrence
*/
void readFrequencesInto(Frequence *frequence,
                        char filename[],
                        char alphabetfilename[],
                        char languagename[])
{
    FILE *alphabetfile;
    alphabetfile = fopen(alphabetfilename, READING_MODE);
    if (alphabetfilename == NULL || feof(alphabetfile))
    {
        perror("Error while opening alphabet file");
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