#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // touppercase

#define READ_BUFFER_SIZE 1000

int main(int argc, char * argv[])
{

    int to_screen = 0;
    FILE *out = stdout;

    if (argc == 2)
    {
        to_screen = 1;
    }

    else if(argc != 3)
    {
        fprintf(stderr, "Must supply a source and destination file!\n");
        exit(1);
    }
    
    FILE *in = fopen(argv[1], "r");
    if(!in)
    {
        fprintf(stderr, "Can't open %s for reading: ", argv[1]);
        perror(NULL);
        exit(1);
    }

    if (!to_screen)
    {
        out = fopen(argv[2], "w");
        if(!out)
        {
            fprintf(stderr, "Can't open %s for writting: ", argv[2]);
            perror(NULL);
            exit(1);
        }
    }

    char line[READ_BUFFER_SIZE];
    while (fgets(line, READ_BUFFER_SIZE, in) != NULL)
    {
        char *s = line;
        while (*s != '\0')
        {
            // Convert to uppercase
            *s = toupper(*s);
            // if (*s >= 'a' && *s <= 'z')
            // {
            //     *s -= 32;
            // }

            // Increment s
            s++;
        }
        // if (to_screen)
        //     printf("%s", line);
        // else
        //     fprintf(out, "%s", line);
        fprintf(out, "%s", line);
    }

    fclose(in);
    // if (!to_screen) fclose(out);
    fclose(out);

    return 0;
}