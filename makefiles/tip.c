#include <stdio.h>
#include "get_double.h"

int main(int argc, char **argv)
{
    double price, tip;
    // printf("Enter price meal: ");
    // scanf("%lf", &price);
    price = get_double("Enter price meal: ", 0, 1000);

    // printf("Enter tip amount (percent): ");
    // scanf("%lf", &tip);
    tip = get_double("Enter tip amount (percent): ", 0, 100);

    double tip_amt = price * tip / 100.0;
    double total = price + tip_amt;
    printf("Tip amount: %lf\n", tip_amt);
    printf("Total amount: %lf\n", total);

    return 0;
}