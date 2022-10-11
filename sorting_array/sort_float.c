#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 1000000

float *make_array(int length);
void save_array(float *array, int size);
void sort_array(float *array, int size);
int float_compare(const void * a, const void * b);
float *linear_search(float t, float *a, int size);

int main(int argc, char *argv[])
{
    float *arr = make_array(LENGTH);
    float target;
    // sort_array(arr, LENGTH);
    qsort(arr, LENGTH, sizeof(float), float_compare);
    save_array(arr, LENGTH);

    printf("What to find? ");
    scanf("%f", &target);
    arr[LENGTH-1] = target;

    // float *found = linear_search(target, arr, LENGTH);
    float *found = (float *)bsearch(&target, 
                                    arr, 
                                    LENGTH, 
                                    sizeof(float), 
                                    float_compare);
    if (found)
    {
        printf("Found: %f\n", *found);
    }
    else
    {
        printf("Not found: %f\n", target);
    }

    free(arr);
}

int float_compare(const void * a, const void * b)
{
    // float *aa = (float*)a;
    // float *bb = (float*)b;

    // if (*aa == *bb) return 0;
    // else if (*aa < *bb) return -1;
    // else return 1;

    if (*(float *)a == *(float *)b) return 0;
    else if (*(float *)a < *(float *)b) return -1;
    else return 1;
}

float *make_array(int length)
{
    // Seed random number generator
    srandom(time(NULL));

    // Allocate array
    float *array = (float *) malloc(length * sizeof(float));

    // Fill array with random numbers
    for (int i = 0; i < length; i++)
    {
        array[i] = (float)(int)(random() / 10000.0);
    }

    return array;
}

void save_array(float *array, int size)
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
        fprintf(out, "%f\n", array[i]);
    }

    fclose(out);
}

void sort_array(float *array, int size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        for (int j = 0; j < (size - 1); j++)
        {
            if (array[j] > array[j+1])
            {
                float temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

float *linear_search(float t, float *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] == t)
        {
            return &a[i];
        }
    }

    return NULL;
}