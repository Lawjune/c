/*
*
* Calculate the diag of TV by given width and height.
* 16:9 => h = 9w/16
**/

#include <stdio.h>
#include "diag.h"

// Function prototypes
// double trig_diag(double w);
// double pythag_diag(double w);

int main(int argc, char *argv[]) 
{
    double width;
    
    printf("Width of TV: ");
    scanf("%lf", &width);

    // Pythagorean formula
    // double height = (double)(9 * width) / 16;
    // printf("Height of TV: %lf\n", height);
    // double diag = sqrt(width * width + height * height);
    double diag = pythag_diag(width);

    // Trigonometry
    // double theta = atan(9.0/16.0);
    // double diag = width / cos(theta);
    // double diag = trig_diag(width);

    printf("You need to get a TV that is %lf inches\n", diag);

    return 0;
}

