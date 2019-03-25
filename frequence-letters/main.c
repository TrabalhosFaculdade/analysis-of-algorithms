#include <stdio.h>
#include <string.h>

#include "dinamically-sized-array.h"
#include "phrases-file-reading.h"

int main()
{
    Array a;
    readFileInto(&a, "phrases.txt");

    FrequenceLanguage l;
    readFrequencesInto(&l,"frequences/english.txt", "frequences/letters.txt", "English");
    
    //reads all files on /frequences and places in a struct FrequenceLanguage


    //just testing
    printArray(&a);
    return 0;
}
