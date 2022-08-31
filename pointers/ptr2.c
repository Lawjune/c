#include <stdio.h>

#define FILE_BUFFER_SIZE 1000

void f(int *x)
{
    *x = 90;
}

void read_file(char *fname, char *str, int *len)
{
    // Open fname for reading

    // Read te file into string

    // Set the length of str by assigning to len
    *len = 934;
}

int main()
{
    // int a = 10, b = 100;
    // int *c;
    // c = &a;

    // int a, b;
    // scanf("%d%d", &a, &b);
    // printf("%d%d\n", a, b);

    // f(&a);
    // printf("%d\n", a);

    char f[FILE_BUFFER_SIZE];
    int len_of_f;

    read_file("input.txt", f, &len_of_f);

    for (int i = 0; i < len_of_f; i++){
        // Do something to each char pf f
        
    }
}