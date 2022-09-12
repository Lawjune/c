#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "md5.h"

#define WORD_BUFFER_SIZE 20

int main(int argc, char * argv[])
{

    if (argc < 2)
    {
        fprintf(stderr, "Usage:  %s hash_to_crack.\n", argv[0]);
        exit(1);
    }

    char *target_hash = argv[1];

    FILE *w = fopen("words.txt", "r");

    if (!w)
    {
        fprintf(stderr, "Can't open five_letter_words.txt for reading: ");
        perror(NULL);
        fclose(w);
        exit(2);
    }

    char word[20];
    while (fgets(word, WORD_BUFFER_SIZE, w) != NULL)
    {
        
        // Trim newline
        char *new_line = strchr(word, '\n');
        if (new_line) *new_line = '\0';

        // Hash the word
        char *hash = md5(word, strlen(word));

        // Does it match the target hash?
        if (strcmp(hash, target_hash) == 0)
        {
            printf("Found %s %s\n", target_hash, word);
            free(hash);
            fclose(w);
            exit(0);
        }

        fclose(w);
        free(hash);
    }

    fprintf(stderr, "Could not crack the hash.\n");
    exit(3);

    return 0;
}