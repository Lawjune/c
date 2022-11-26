#include <stdio.h>
#include <string.h>

#define NAME_LEN 10

int string_length(const char * str);
int count_uppercase(const char * str);

int main(int argc, char *argv[])
{
    char greet[] = "Hello world!";

    printf("%s\n", greet);

    // for (int i = 0; i < 20; i++) printf("%d, ", greet[i]);

    char name[NAME_LEN];
    printf("Enter your name: ");
    // scanf("%10s", name);              // No ampersand!
    fgets(name, NAME_LEN, stdin);        // fgets will get an "Enter" key -> '/n
    printf("Hello, %s!\n", name);

    int length = string_length(name);
    printf("Length is: %d\n", length);

    int uppers = count_uppercase(name);
    printf("Uppercase letters is: %d\n", uppers);
}

int string_length(const char * str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

int count_uppercase(const char * str)
{
    int i = 0;
    int count = 0;
    while (str[i] != '\0')
    {
        // 'A' == 65 == 0x41 == 0b01000001
        if (str[i] >= 'A' && str[i] <= 'Z') count++;
        i++;
    }

    return count;
}