#include <stdio.h>
#include <math.h>
#include "get_double.h"

int main(int argc, char **argv)
{

    double x = get_double("Enter the x value: ", -100, 100);
    double y = get_double("Enter the y value: ", -100, 100);
    double d = sqrt(pow(x, 2.0) + pow(y, 2.));

    printf("Distance is %lf miles\n", d);

    return 0;
}