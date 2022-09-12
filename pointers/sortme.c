#include <stdio.h>
#include <string.h> // memcpy
#include <stdlib.h> // malloc

struct person
{
    char *name;
    int age;
};

void bsort_int(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        for(int j = 0; j < len-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void bsort_str(char **s, int len)
{
    for (int i = 0; i < len; i++)
    {
        for(int j = 0; j < len-1; j++)
        {
            if(strcmp(s[j], s[j+1]) > 0)
            {
                char* temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

void bsort(void **a, int len, int element_size)
{
    void *temp = malloc(element_size);

    for (int i = 0; i < len; i++)
    {
        for(int j = 0; j < len-1; j++)
        {
            if(strcmp(*(char **)(&a[j]), *(char **)(&a[j+1])) > 0)
            {
                memcpy(temp, &a[j], element_size);
                memcpy(&a[j], &a[j+1], element_size);
                memcpy(&a[j+1], temp, element_size);
            }
        }
    }

    free(temp);
}


int compare(const void *a, const void *b)
{
    // return strcmp(*(char **)a, *(char **)b);
    // return (*(int *)a) - (*(int *)b);
    struct person *aa = (struct person *)a;
    struct person *bb = (struct person *)b;

    return (aa->age) - (bb->age);
 }



int main(int argc, char **argv)
{
    // int arr[] = {8, 4, 0, -3, 1, 8, 2, 6, 3};
    // char *arr[] = {"banana", "apple", "grape", "orange", "peach", "kiwi", "guava", "melon"};
    struct person arr[] = {
        {"Bob", 18},
        {"Amy", 30},
        {"Pam", 26},
        {"Fred", 15}
    };
    int len = sizeof(arr)/sizeof(arr[0]);
    // bsort_int(arr, len);
    // bsort_str(arr, len);
    // bsort((void *)arr, len, sizeof(arr[0]));
    qsort(arr, len, sizeof(arr[0]), compare);

    // Bubble sort the array

    // Bubble sort the array

    // for (int i = 0; i < 9; i++)
    // {
    //     for(int j = 0; j < 9-1; j++)
    //     {
    //         if (arr[j] > arr[j+1])
    //         {
    //             int temp = arr[j];
    //             arr[j] = arr[j+1];
    //             arr[j+1] = temp;
    //         }
    //     }
    // }

    for (int i = 0; i < len; i++)
    {
        // printf("%d\n", arr[i]);
        // printf("%s\n", arr[i]);
        printf("%s %d\n", arr[i].name, arr[i].age);
    }
}