#include <stdio.h>

void fv(int x)
{
    x = 70;
}

void fp(int *x){
    *x = 70;
}


int main(int argc, char *argv[])
{
    int a = 10;
    int b = 50;

    // Name is c
    // Type is int *
    // Pointer to an integer
    // Address of an integer
    int *c;

    c = &a;

    a++;
    printf("After a++, c = %d\n", *c);

    (*c)++;
    printf("Then (*c)++, a = %d\n", a);

    *c = 5;
    printf("Then *c = 5, a = %d\n", a);

    fv(a); // Copy the value of a 
    printf("Then fv(a), a = %d\n", a);

    fp(&a); // Copy the address of a 
    printf("Then fp(a), a = %d\n", a);
    
    return 0;
}