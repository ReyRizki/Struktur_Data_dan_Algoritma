#include <stdio.h>
int main()
{
    int *ptr;
    int x = 2;            // deklarasi
    ptr = &x;             // pointer menunjuk ke variabel x
    printf("%d\n", *ptr); // print yang ditunjuk oleh pointer
    return 0;
}