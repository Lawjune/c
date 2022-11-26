#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEADS 0
#define TAILS 1

#define GAMES 10000

int main(int argc, char * argv[])
{
    srandom(time(NULL));

    int heads = 0;

    for (int i = 0; i < GAMES; i++)
    {
        int coin = random() % 2;

        // Computer flip?
        if (random() % 2) coin = random() % 2;

        // Human flip?
        if (random() % 2) coin = random() % 2;

        // Computer flip?
        if (random() % 2) coin = random() % 2;

        if (coin == HEADS) heads++;
    }

    printf("Heads %d out of %d games\n", heads, GAMES);

    return 0;
}