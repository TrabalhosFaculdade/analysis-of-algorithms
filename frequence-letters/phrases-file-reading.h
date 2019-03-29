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
    char letter;
    unsigned int frequence;
} RawFrequenceLetter;

typedef struct
{
    FrequenceLetter lettersInLanguage[LETTERS_ALPHABET];
    char *languageName;
} Frequence;

void readFileInto(Array *a, char filename[]);
void readAlphabetInto(RawFrequenceLetter *frequences, char alphabetfilename[]);
void readFrequencesInto(Frequence *fequence,
                        char filename[],
                        char alphabetfilename[],
                        char languagename[]);

#endif
