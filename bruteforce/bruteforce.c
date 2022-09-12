#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "md5.h"


int main(int argc, char * argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Must supply a hash to crack.\n");
        exit(1);
    }

    char *target_hash = argv[1];

    char word[WORD_BUFFER_SIZE] = "-----";

    for (word[0] = 'a'; word[0] <= 'z'; ++word[0]) {

        for (word[1] = 'a'; word[1] <= 'z'; ++word[1])
            for (word[2] = 'a'; word[2] <= 'z'; ++word[2])
                for (word[3] = 'a'; word[3] <= 'z'; ++word[3])
                    for (word[4] = 'a'; word[4] <= 'z'; ++word[4])
                    {

    // for (char c0 = 'a'; c0 <= 'z'; c0++) {

    //     for (char c1 = 'a'; c1 <= 'z'; c1++)
    //         for (char c2 = 'a'; c2 <= 'z'; c2++)
    //             for (char c3 = 'a'; c3 <= 'z'; c3++)
    //                 for (char c4 = 'a'; c4 <= 'z'; c4++)
    //                 {
                        // word[0] = c0; 
                        // word[1] = c1;
                        // word[2] = c2;
                        // word[3] = c3;
                        // word[4] = c4;
                        // char word[WORD_BUFFER_SIZE] = {c0, c1, c2, c3, c4, '\0'};

                        // printf("%s\n", word);

                        char *hash = md5(word, strlen(word));
                        if (strcmp(hash, target_hash) == 0)
                        {
                            free(hash);
                            printf("Found it! %s\n", word);
                            exit(0);
                        }
                        free(hash);
                        // printf("%s\n", word);
                    }

        // printf("%s\n", word);
    }

    return 0;
}