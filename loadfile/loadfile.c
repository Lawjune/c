#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STEP_SIZE 100
#define LINE_BUFFER_SIZE 1000

// char **loadfile(char *filename, int *length);
char **loadfile(char *filename);


int main(int argc, char *argv[])
{
    if (argc == -1)
    {
        fprintf(stderr, "Must supply a filename to read!\n");
        exit(1);
    }

    // Load file into data structure
    int length = 0;
    // char **words = loadfile(argv[1], &length);
    char **lines = loadfile(argv[1]);
    if (!lines)
    {
        fprintf(stderr, "Can't build data structure\n");
    }

    // Display the first 100 lines 
    // printf("Length: %d\n", length);
    // printf("Printing the first 100(STEP_SIZE) lines: \n");
    printf("Print all the lines: \n");

    for (int i = 0; lines[i] != NULL; i++)
    {
        printf("%s\n", lines[i]);
    }
    printf("Done\n");

}

// char **loadfile(char *filename, int *length)
char **loadfile(char *filename)
{
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        fprintf(stderr, "Can't open %s for reading\n", filename);
        return NULL;
    }

    // int arrlen = STEP_SIZE;
    int arrlen = 0;

    // Allocate space for STEP_SIZE char *
    // char **lines = (char **)malloc(arrlen * sizeof(char *));
    char **lines = NULL;
    
    char buf[LINE_BUFFER_SIZE];
    int i = 0;

    while (fgets(buf, LINE_BUFFER_SIZE, f))
    {
        // Check if array is full. If so, extend it
        if (i == arrlen)
        {
            arrlen += STEP_SIZE;

            char **newlines = realloc(lines, (STEP_SIZE * 2) * sizeof(char *));
            if (!newlines)
            {
                fprintf(stderr, "Can't realloc\n");
                exit(1);
            }
            lines = newlines;
        }

        // Get length of buf
        int slen = strlen(buf);

        // Trim off newline char
        buf[slen - 1] = '\0';

        // Allocate space for the string
        char *str = (char *)malloc((slen + 1) * sizeof(char));

        // Copy string from buf to str
        strcpy(str, buf);

        // Attach str to data structure
        lines[i] = str;
        i++;

    }
        // *length = i;

        // What if the size is exactly the times of STEP_SIZE
        if(i == arrlen)
        {
            char **newarr = (char **)realloc(lines, (arrlen + 1)*sizeof(char *));
            if (!newarr)
            {
                fprintf(stderr, "Can't relloc newarr\n");
                exit(1);
            }
            lines = newarr;
        }

        // Set the end of the array
        lines[i] = NULL; 
        return lines;
}