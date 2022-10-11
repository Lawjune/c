#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 10000
#define SINGLE_STRING_BUFFER_SIZE 100

char* *make_array(int length);
void sort_array(char **array, int size);
void save_array(char **array, int size);

int main(int argc, char *argv[])
{
    char **arr = make_array(LENGTH);
    sort_array(arr, LENGTH);
    save_array(arr, LENGTH);
}

char* *make_array(int length)
{

    // Allocate array of pointers to string
    char **array = (char**) malloc(length * sizeof(char*));

    // Open the rockyou file
    FILE *in = fopen("rockyou1m.txt", "r");
    if (!in)
    {
        fprintf(stderr, "Can't open rockyou1m.txt for reading: ");
        perror(NULL);
        exit(1);
    }

    // Fill array with strings
    for (int i = 0; i < length; i++)
    {
        // Trime the new lines
        char line[SINGLE_STRING_BUFFER_SIZE];
        fgets(line, SINGLE_STRING_BUFFER_SIZE, in);

        char *newline = strchr(line, '\n');
        if (newline) *newline = '\0';

        // Allocate space for the string
        char *str = (char *)malloc(strlen(newline) + 1);

        // Copy line into the new string
        strcpy(str, line);

        // Attach to array of strings
        array[i] = str;
    }

    fclose(in);

    return array;
}

void save_array(char **array, int size)
{
    FILE *out = fopen("out.txt", "w");
    if (!out)
    {
        fprintf(stderr, "Can't open out.txt for writting: ");
        perror(NULL);
        exit(1);
    }

    for (int i = 0; i < size; i++)
    {
        fprintf(out, "%s\n", array[i]);
    }

    fclose(out);
}

void sort_array(char **array, int size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        for (int j = 0; j < (size - 1); j++)
        {
            if (strcmp(array[j], array[j+1]) > 0)
            {
                char* temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}