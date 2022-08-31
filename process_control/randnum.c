#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const int max = 24;

int main(int argc, char *argv[])
{
    
    srandom(getpid());
    printf("%d\n", max);
    for (int i = 1; i < max; i++)
    {
        long int r = random();
        printf("%ld\n", r);
    }
}
