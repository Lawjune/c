#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 1000000
#define SINGLE_STRING_BUFFER_SIZE 100

// Global variable
int ssearch_count = 0;
int scompare_count = 0;

char* *make_array(int length);
void sort_array(char **array, int size);
void save_array(char **array, int size);
char *linear_search(char *t, char **a, int size);

// Return 0 if *a == *b
// Return neg if *a == 0
// Return neg if *a > *b
// Return post if *a > *b;
int str_compare(const void * a, const void * b);
int str_search(const void * t, const void * e);

int main(int argc, char *argv[])
{
    char **arr = make_array(LENGTH);
    // sort_array(arr, LENGTH);
    qsort(arr, LENGTH, sizeof(char *), str_compare);
    save_array(arr, LENGTH);
    printf("Sort comparisons: %d\n", scompare_count);

    char target[100];
    printf("What to find? ");
    scanf("%s", target);

    char **found = (char **) bsearch(&target, 
                                   arr, 
                                   LENGTH, 
                                   sizeof(char *), 
                                   str_search);
    // char *found = linear_search(target, arr, LENGTH);

    printf("Search comparisons: %d\n", ssearch_count);
    if(found)
    {
        printf("Found: %s\n", *found);
    }
    else
    {
        printf("Not found: %s\n", target);
    }
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

int func_compare(const void * a, const void * b)
{
    float *aa = (float*)a;
    float *bb = (float*)b;

    if (*aa == *bb) return 0;
    else if (*aa < *bb) return -1;
    else return 1;
}

int str_compare(const void * a, const void * b)
{
    scompare_count++;
    // char **aa = (char**)a;
    // char **bb = (char**)b;
    
    // return strcmp(*aa, *bb);
    return strcmp(*(char **)a, *(char **)b);
}

int str_search(const void * t, const void * e)
{
    ssearch_count++;
    
    char *tt = (char *)t;       // t as a character pointer
    char **ee = (char **)e;     // e as a pointer to character pointer

    return strcmp(tt, *ee);
}

char *linear_search(char *t, char **a, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(a[i], t) ==0) return a[i];
    }

    return NULL;
}