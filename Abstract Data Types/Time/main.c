#include <stdio.h>
#include <stdlib.h>
#include "Time.h"

int main()
{
    TIME a, b;
    int N;

    ReadTIME(&a);
    ReadTIME(&b);

    // PrintTIME(a);
    // N = TimeToDetik(a);
    // printf("%ld\n", TimeToDetik(a));

    // PrintTIME(DetikToTIME(N));
    // printf("%d\n", 3600*23+59*60+59*60);

    printf("%ld\n", Durasi(a, b));
}