#include <stdio.h>
#include <string.h>

#include "dinamically-sized-array.h"
#include "phrases-file-reading.h"

float difference(Frequence *languageFrequence, Frequence *phraseFrequence)
{
    unsigned int i;
    float totalDifference = 0;

    for (i = 0; i < LETTERS_ALPHABET; i++)
    {
        float charFrequenceLanguage = languageFrequence->lettersInLanguage[i].percentageOccurrence;
        float charFrequencePhrase = phraseFrequence->lettersInLanguage[i].percentageOccurrence;

        totalDifference += abs(charFrequenceLanguage - charFrequencePhrase);
    }

    return totalDifference;
}

Frequence getFrequenceFrom(RawFrequenceLetter *rawFrequences,
                           int totalchars,
                           char languagename[])
{
    unsigned int i;
    Frequence *frequence;

    //x = (100 * rawFrequenceValue)/total
    frequence = malloc(sizeof(Frequence));
    frequence->languageName = languagename;

    for (i = 0; i < LETTERS_ALPHABET; i++)
    {
        FrequenceLetter frequenceletter;

        //calculating values and placing it into propert structs
        float result = (100.0 * rawFrequences[i].frequence) / (float)totalchars;
        frequenceletter.letter = rawFrequences[i].letter;
        frequenceletter.percentageOccurrence = result;

        frequence->lettersInLanguage[i] = frequenceletter;
    }

    return *frequence;
}

void incrementInto(RawFrequenceLetter *frequences, char wanted)
{
    unsigned int i;
    for (i = 0; i < LETTERS_ALPHABET; i++)
    {
        if (frequences[i].letter == wanted)
        {
            frequences[i].frequence++;
            return; //not need to continue
        }
    }
}

int main()
{
    Array phrases;
    readFileInto(&phrases, "resources/phrases.txt");

    Frequence englishfrequence;
    Frequence portuguesefrequence;
    Frequence germanfrequence;

    readFrequencesInto(&englishfrequence,
                       "resources/english.txt",
                       "resources/letters.txt", "English");

    readFrequencesInto(&portuguesefrequence,
                       "resources/portuguese.txt",
                       "resources/letters.txt", "Portuguese");

    readFrequencesInto(&germanfrequence,
                       "resources/german.txt",
                       "resources/letters.txt", "German");

    printf("\n\nNote: the lower the number, the better.\n\n");

    unsigned int i;
    for (i = 0; i < phrases.used; i++)
    {
        RawFrequenceLetter *rawFrequences;
        Frequence phraseFrequence;

        char *line = phrases.array[i];
        unsigned int j;
        unsigned total = 0;

        rawFrequences = (RawFrequenceLetter *) malloc(sizeof(RawFrequenceLetter) * LETTERS_ALPHABET);
        readAlphabetInto(rawFrequences, "resources/letters.txt");

        for (j = 0; j < strlen(line); j++)
        {
            char currentchar = line[j];
            incrementInto(rawFrequences, currentchar);
            total++;
        }

        phraseFrequence = getFrequenceFrom(rawFrequences, total, "Guessing");

        float englishDiff, germanDiff, portugueseDiff;
        englishDiff = difference(&englishfrequence,&phraseFrequence);
        germanDiff = difference(&germanfrequence,&phraseFrequence);
        portugueseDiff = difference(&portuguesefrequence,&phraseFrequence);

        printf("Phrase: %s \n", line);
        printf("English: %.1f, German: %.1f, Portuguese: %.1f \n \n \n", englishDiff, germanDiff, portugueseDiff);
    }

    return 0;
}
