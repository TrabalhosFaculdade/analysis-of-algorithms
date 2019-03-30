#include <stdio.h>
#include <string.h>

#include "dinamically-sized-array.h"
#include "phrases-file-reading.h"

/**
 * The raw difference between two Frequence structs.
 * Iterating over each letter of the alphabet in the 
 * speciifed structs, and getting the absolute difference 
 * between those two. Adding all of this up, and returning 
 * the result. 
*/
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

/**
 * Convert RawFrequenceLetters into a Frequence 
 * struct. This is done by getting the percentage 
 * equivalent of the total appereance of a specified 
 * character, having the total number of characters as
 * the 100%. 
 * 
 * A new Frequence struct will be instantied and 
 * returned as a result.
*/
Frequence getFrequenceFrom(RawFrequenceLetter *rawFrequences,
                           int totalchars,
                           char languagename[])
{
    unsigned int i;
    Frequence *frequence;

    frequence = malloc(sizeof(Frequence));
    frequence->languageName = languagename;

    for (i = 0; i < LETTERS_ALPHABET; i++)
    {
        FrequenceLetter frequenceletter;

        //calculating values and placing it into propert structs
        //rawFrequenceValue / total = x /100
        //x = (100 * rawFrequenceValue)/total

        float result = (100.0 * rawFrequences[i].frequence) / (float)totalchars;
        frequenceletter.letter = rawFrequences[i].letter;
        frequenceletter.percentageOccurrence = result;

        frequence->lettersInLanguage[i] = frequenceletter;
    }

    return *frequence;
}

/**
 * The goal of this function in to increment the 
 * total ocurrence of a specified (wanted) character
 * into the RawFrequenceLetter struct passed as
 * parameter.
 * 
 * Nothing will be done if character could not be found,
 * which will include special characters not defined into
 * our "standart" 26 letter alphabet.
*/
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

/**
 * Application entry point. Flow of execution:
 * 
 * 1. Read phrases whose idioms will be guessed by 
 * the program and place them into a dinamically 
 * sized array.
 * 
 * 2. Read the frequence of ocorrunce of each letter
 * of the defined languages.
 * 
 * 3. Translate the phrases to frequence into structs 
 * as well
 * 
 * 4. Compare the difference between the frequence 
 * structs of each language and the one retrieved by the
 * read phrase, and print results. 
 * 
*/
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
        size_t rawfrequencelettersize;
        
        char *line;
        unsigned int j;
        unsigned total;

        //getting the raw frequence of appereance of each letter
        //then translate into porcentage numbers, with witch to
        //calculate the things we want
        rawfrequencelettersize = sizeof(RawFrequenceLetter) * LETTERS_ALPHABET;
        rawFrequences = (RawFrequenceLetter *) malloc(rawfrequencelettersize);
        readAlphabetInto(rawFrequences, "resources/letters.txt");

        total = 0;
        line = phrases.array[i];
        for (j = 0; j < strlen(line); j++)
        {
            char currentchar = line[j];
            incrementInto(rawFrequences, currentchar);
            total++;
        }

        phraseFrequence = getFrequenceFrom(rawFrequences, total, "Guessing");

        //printing all results
        float englishDiff, germanDiff, portugueseDiff;

        englishDiff = difference(&englishfrequence, &phraseFrequence);
        germanDiff = difference(&germanfrequence, &phraseFrequence);
        portugueseDiff = difference(&portuguesefrequence, &phraseFrequence);

        printf("Phrase: %s \n", line);
        printf("English: %.1f, German: %.1f, Portuguese: %.1f \n \n \n", 
                englishDiff, germanDiff, portugueseDiff);
    }

    return 0;
}