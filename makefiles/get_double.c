#include <stdio.h>

double get_double(char *prompt, double min, double max) 
{
    double input;

    do 
    {
        printf("%s", prompt);
        scanf("%lf", &input);
        if (input < min) printf("Must be at least %lf", min);
        if (input > max) printf("Must be at most %lf", max);
    }
    while (input < min || input > max);

    return input;
}
