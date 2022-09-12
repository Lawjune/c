#include <stdio.h>

int foo(int a, int b)
{
    int c;
    c = a + 2*b;
    return c;
}

int main(int argc, char * argv[])
{
    int x = 100;
    int y = 20;
    int z;
    z = foo(x, y + 10);

    printf("%d\n", z);

    return 0;
}