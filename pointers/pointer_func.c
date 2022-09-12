#include <stdio.h>

int foo(int x)
{
    printf("foo function => %d\n", x);
    return x + 5;
}

int main(int argc, char *argv[])
{
    int (*bar)(int x) = foo;
    int z = bar(3);
    printf("bar function return => %d\n", z);
}