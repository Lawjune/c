#include <stdio.h>

// Length of a string
// Same as strlen
// int length(char s[])
int old_length(char *s)
{
    int count = 0;
    // while(s[count] != '\0')
    // while(*(s + count) != '\0')
    // while(*(s + count) != 0)
    while(*(s + count))
        count++;
    return count;
}

int length(char *s)
{
    char *start = s;
    while(*s)
        s++;
    return s - start;
}

// Trim off trailling whitespace
void trim(char *s)
{
    // int c = length(s);
    // s = s + c;

    while(*s) s++; // Get to the end of the string
    // Then scan back to first non-space

    while (*s == ' ' || 
           *s  == '\0' || 
           *s == '\n') 
           s--;
    // Replace space with null character
    *(s + 1) = 0;
}

// Compare two strings
// Return 0 if equal
// Return <0 if comes before t
// Return >0 if comes after t
// Same as strcmp
int compare(char *s, char *t)
{
    while ((*s - *t == 0) && *s != 0 &  *t != 0)
    {
        s++;
        t++;
    }
    return (*s - *t);
}

int main(int argc, char *argv[])
{
    char str[100];
    char cmp_str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    printf("Length is %d\n", length(str));
    trim(str);
    printf(">%s<\n", str);

    printf("Enter a comparing string: ");
    fgets(cmp_str, 100, stdin);
    trim(cmp_str);

    printf("%d\n", compare(str, cmp_str));

    return 0;
}