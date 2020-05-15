#include <stdio.h>

int main()
{
    int x = 6;

    int p = x;
    int q = p;

    p = 10;
    printf("x : %d p : %d, q : %d \n", x, p, q);

    int x1 = 6;
    int *ptrp = &x1;
    int q1 = *ptrp;
    //ubah nilai x
    *ptrp = 10;

    printf("x : %d p : %d, q : %d\n", x1, *ptrp, q1);
}