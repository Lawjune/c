#include <stdio.h>

const float R2 = 0.7071067812; // square of 2

struct qubit
{
    float zero;
    float one;
};

typedef struct qubit qubit;

void print_qubit(qubit *q)
{
    printf("(%f, %f)\n", q->zero, q->one);
}

void X(qubit *q)
{

    qubit temp;
    temp.zero = 0*(q->zero) + 1*(q->one);
    temp.one = 1*(q->zero) + 0*(q->one);
    q->zero = temp.zero;
    q->one = temp.one;
}

void H(qubit *q)
{
    qubit temp;
    temp.zero = R2*(q->zero) + R2*(q->one);;
    temp.one = R2*(q->zero) - R2*(q->one);
    q->zero = temp.zero;
    q->one = temp.one;
}

int main(int argc, char *argv[])
{
    printf("Game of classic toggling.\n");
    qubit q = { 1, 0 };
    printf("Initial qubit: ");
    print_qubit(&q);

    printf("Human toggled: ");
    X(&q);
    print_qubit(&q);

    printf("Human toggled: ");
    X(&q);
    print_qubit(&q);

    printf("Human toggled: ");
    X(&q);
    print_qubit(&q);

    printf("\n");

    printf("Game with quantum computer.\n");
    qubit q1 = { 1, 0 };

    printf("Initial qubit: ");
    print_qubit(&q1);

    printf("Quantum computer toggled: ");
    H(&q1);
    print_qubit(&q1);

    printf("Human toggled: ");
    X(&q1);
    print_qubit(&q1);

    printf("Quantum computer toggled again: ");
    H(&q1);
    print_qubit(&q1);
}