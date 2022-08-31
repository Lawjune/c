#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define children 4

void factor(int n)
{
    for (int i = 2; i <= n/2; i++) 
    {
        if (n % i == 0) printf("%d ", i);
    }
}

int main(int argc, char *argv[])
{
    // int n;
    // // printf("Enter a number: ");
    // // scanf("%d", &n);
    // sscanf(argv[1], "%d", &n);

    int size;
    scanf("%d", &size);

    int *arr;
    arr = (int *)malloc(sizeof(int) * size);

    for (int j = 0; j < size; j++)
    {
        scanf("%d", &arr[j]);
    }
    
    int child_num = 0;
    pid_t child[children];
    int parent = 0;

    for (child_num = 0; child_num < children; child_num++)
    {
        child[child_num] = fork();
        if (child[child_num] == 0) 
        {
            parent = 0;
            break;
        }
        parent = 1;
    }

    // if (child[0] && child[1] && child[2] && child[3])
    if (parent)
    {
        printf("I'm the parent.\n");
        int status;
        pid_t child = wait(&status);
        for (int c = 1; c < children; c++)
            child = wait(&status);
        // pid_t child = wait(&status);
        // child = wait(&status);
        // child = wait(&status);
        // child = wait(&status);
    }

    else if (!parent)
    {
        int lines = size / children;
        int start = lines * child_num;
        for (int i = start; i < start + lines; i++)
        {
            printf("I'm the child %d => ", child_num); 
            printf("%d: ", arr[i]);
            factor(arr[i]);
            printf("\n");
        }
        exit(0);        
    }

    // Step 2
    // else if (child[0] == 0 && child_num == 0 )
    // {
    //     int lines = size / children;
    //     int start = children * child_num;
    //     for (int i = start; i < start + lines; i++)
    //     {
    //         printf("I'm the child %d => ", child_num); 
    //         printf("%d: ", arr[i]);
    //         factor(arr[i]);
    //         printf("\n");
    //     }
    //     exit(0);
    // }
    // else if (child[1] == 0 && child_num == 1 )
    // {
    //     int lines = size / children;
    //     int start = children * child_num;
    //     for (int i = start; i < start + lines; i++)
    //     {
    //         printf("I'm the child %d => ", child_num);  
    //         printf("%d: ", arr[i]);
    //         factor(arr[i]);
    //         printf("\n");
    //     }
    //     exit(0);
    // }
    // else if (child[2] == 0 && child_num == 2 )
    // {
    //     int lines = size / children;
    //     int start = children * child_num;
    //     for (int i = start; i < start + lines; i++)
    //     {
    //         printf("I'm the child %d => ", child_num); 
    //         printf("%d: ", arr[i]);
    //         factor(arr[i]);
    //         printf("\n");
    //     }
    //     exit(0);
    // }
    // else if (child[3] == 0 && child_num == 3 )
    // {
    //     int lines = size / children;
    //     int start = children * child_num;
    //     for (int i = start; i < start + lines; i++)
    //     {
    //         printf("I'm the child %d => ", child_num); 
    //         printf("%d: ", arr[i]);
    //         factor(arr[i]);
    //         printf("\n");
    //     }
    //     exit(0);
    // }

    
    // Step 1
    // for (int i = 0; i < size; i++)
    // {
    //     printf("%d: ", arr[i]);
    //     factor(arr[i]);
    //     printf("\n");
    // }
    
    return 0;
}