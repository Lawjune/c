#include <stdio.h>
#include <stdlib.h>     // srandom(), random()
#include <limits.h>     // INT_MIN
#include <time.h>       // time

#define SIZE 10

void print_array(const int arr[], const int length);
// void print_array_addresses(int arr[], const int length);
void input_array(int arr[], const int length);
void double_array(int arr[], const int length);
int max_int(int arr[], const int length);
int sum_array(int arr[], const int length);
float average(int arr[], const int length);
void rotate_array(int arr[], const int length);
void reverse_array(int arr[], const int length);
void fill_array_random(int arr[], const int length);

int main(int argc, char *argv[])
{
    int nums[SIZE];
    srandom(time(NULL));
    fill_array_random(nums, SIZE);

    print_array(nums, SIZE);

    int largest = max_int(nums, SIZE);
    printf("Largest is %d\n", largest);

    int sum = sum_array(nums, SIZE);
    printf("Sum is %d\n", sum);

    float ave = average(nums, SIZE);
    printf("Average is %f\n", ave);

    rotate_array(nums, SIZE);
    printf("Rotate!\n");
    print_array(nums, SIZE);

    reverse_array(nums, SIZE);
    printf("Reverse!\n");
    print_array(nums, SIZE);
}

void print_array(const int arr[], const int length)
{
    printf("Here are the numbers:");
    for (int i = 0; i < length; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

// void print_array_addresses(int arr[], const int length)
// {
//     printf("Here are the array element addresses:");
//     for (int i = 0; i < length; i++)
//     {
//         printf(" %x", (arr  + (i * sizeof(int))));
//     }
//     printf("\n");
// }


void input_array(int arr[], const int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("Enter number: %d\n", (i + 1));
        scanf("%d", &arr[i]);
    }
}

void double_array(int arr[], const int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = arr[i] * 2;
    }
}

int max_int(int arr[], const int length)
{
    int largest_so_far = INT_MIN;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] > largest_so_far)
            largest_so_far = arr[i];
    }
    return largest_so_far;
}

int sum_array(int arr[], const int length)
{
    int acc = 0;    //Accumulator

    for (int i = 0; i < length; i++)
    {
        acc = acc + arr[i];
    }

    return acc;
}

float average(int arr[], const int length)
{
    return (float)sum_array(arr, length) / length;
}

void rotate_array(int arr[], const int length)
{
    int first = arr[0];

    for (int i = 0; i < (length - 1); i++)
    {
        arr[i] = arr[i+1];
    }
    arr[length-1] = first;
}

void reverse_array(int arr[], const int length)
{
    for (int i = 0; i < length/2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[length - i - 1];
        arr[length - i - 1] = temp;
    }
}

void fill_array_random(int arr[], const int length)
{
    for (int i = 0; i < length; i++) arr[i] = random() % 100;
}