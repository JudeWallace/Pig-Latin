#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "pig.h"

/**
 * main - Takes a line of english from the command line and converts the entered
 * text into piglatin. The program stops when no chars are entered when prompted to
 * enter a phrase to convert
 */
int main()
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    printf("Enter a line of English (press Enter without typing anything to exit):\n");
    while ((nread = getline(&line, &len, stdin)) != -1)
    {
        // Remove trailing newline character
        if (line[nread - 1] == '\n')
        {
            line[nread - 1] = '\0';
        }

        // Exit if the user pressed Enter without typing anything
        if (nread == 1)
        {
            break;
        }

        // Break the line into words and translate each one
        char *word = strtok(line, " ");
        while (word != NULL)
        {
            // convert each word in the sentence into piglatin
            char *translated = pig(word);
            printf("%s ", translated);
            free(translated);
            word = strtok(NULL, " ");
        }
        printf("\n\nEnter a line of English (press Enter without typing anything to exit):\n");
    }

    free(line);
    return 0;
}
