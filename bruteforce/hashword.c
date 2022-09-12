#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "md5.h"

#define BUFFER_SIZE 100

int main(int argc, char * argv[])
{
    char plain[BUFFER_SIZE];
    printf("Enter a string to hash: ");
    fgets(plain, BUFFER_SIZE, stdin);

    char *new_line = strchr(plain, '\n');
    if (new_line) *new_line = '\0';

    char *hash = md5(plain, strlen(plain));

    printf("Hash: %s\n", hash);
    free(hash);
}