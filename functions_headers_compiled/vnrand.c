#include <stdio.h>

#define MAXTIER 100

int get_seed()
{
    int s;
    printf("Please enter the starting seed value: ");
    scanf("%d", &s);

    return s;
}


int vnrng(int seed)
{   
    int sq = seed * seed;
    int rnd = sq / 100 % 10000;
    return rnd;
}

int main(int argc, char *argv[])
{
    int s = get_seed();
    for (int i = 0; i < MAXTIER; i++)
    {
        int r = vnrng(s);
        printf("%d\n", r);
        s = r;
    }
}