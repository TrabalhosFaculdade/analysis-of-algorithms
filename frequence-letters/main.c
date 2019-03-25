#include <stdio.h>
#include <string.h>

#include "dinamically-sized-array.h"
#include "phrases-file-reading.h"

int main()
{
    Array phrases;
    readFileInto(&phrases, "phrases.txt");

    Frequence englishfrequence;
    Frequence portuguesefrequence;
    Frequence germanfrequence;

    readFrequencesInto(&englishfrequence,
                       "frequences/english.txt",
                       "frequences/letters.txt", "English");

    readFrequencesInto(&portuguesefrequence,
                       "frequences/portuguese.txt",
                       "frequences/letters.txt", "Portuguese");

    readFrequencesInto(&germanfrequence,
                       "frequences/german.txt",
                       "frequences/letters.txt", "German");

    //after reading all frequences from files, 
    //get the frequence out of a phrases in a array
    //TODO solve problem: iterating over a phrase and over the array of phrases.

    return 0;
}
