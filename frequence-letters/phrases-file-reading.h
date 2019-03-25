#ifndef PHRASES_FILE_READING
#define PHRASES_FILE_READING

#define LETTERS_ALPHABET 26

#include "dinamically-sized-array.h"

typedef struct
{
    char letter;
    float percentageOccurrence;
} FrequenceLetter;

typedef struct
{
    FrequenceLetter lettersInLanguage[LETTERS_ALPHABET];
    char *languageName;
} FrequenceLanguage;

void readFileInto(Array *a, char filename[]);
void readFrequencesInto(FrequenceLanguage *fequence,
                        char filename[],
                        char alphabetfilename[],
                        char languagename[]);

#endif
