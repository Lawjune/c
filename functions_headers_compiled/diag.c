#include "diag.h"

double trig_diag(double w)
{
        // Trigonometry
    double theta = atan(9.0/16.0);
    double diag = w / cos(theta);

    return diag;
}   

double pythag_diag(double w)
{
    double height = (double)(9 * w) / 16;

    // printf("Height of TV: %lf\n", height);

    double diag = sqrt(w * w + height * height);

    return diag;
}