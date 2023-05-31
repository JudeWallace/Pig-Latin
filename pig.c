#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * pig - Converts a word to Pig Latin.
 *
 * @word: Pointer to the word to convert.
 *
 * Return: The Pig Latin version of the word, or NULL on failure of
 * memory allocation.
 */
char *pig(char *word)
{
    int len = strlen(word);
    // allocate space for "ay" or "way" and null terminator
    char *pig_latin = (char *)malloc(len + 4);
    // Check memory was allocated correctly
    if (pig_latin == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    if (len > 0 && strchr("aeiouAEIOU", word[0]))
    {
        // begins with a vowel
        sprintf(pig_latin, "%sway", word);
    }
    else if (len > 0 && strchr("yY", word[0]))
    {
        // begins with a y
        sprintf(pig_latin, "%s%cay", &word[1], word[0]);
    }
    else
    {
        // begins with a consonant
        int i = 0;
        while (i < len && !strchr("aeiouyAEIOUY", word[i]))
        {
            i++;
        }
        sprintf(pig_latin, "%s%.*say", &word[i], i, word);
    }
    return pig_latin;
}
