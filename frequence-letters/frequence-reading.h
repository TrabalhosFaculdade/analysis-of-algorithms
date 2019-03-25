#ifndef FREQUENCE_READING
#define FREQUENCE_READING

#define LETTERS_ALPHABET 26

typedef struct
{
    char letter;
    int percentageOccurrence;
} Frequence;

typedef struct
{
    Frequence lettersInLanguage[LETTERS_ALPHABET];
    char languageName[20];
} FrequenceLanguage;

void readFrequenceInto(FrequenceLanguage *frequence, char languageFileName[]);
char *getAlphabetFrom(char alphabetFile[]);

#endif