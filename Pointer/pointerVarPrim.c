#include <stdio.h>

int main()
{
    int y, x = 87;
    int *px; // deklarasi

    px = &x; // pointer menunjuk ke variabel x
    y = *px; // y diisi oleh yang ditunjuk oleh pointer
    printf("Alamat x = %p\n", &x);
    printf("Isi px = %p\n", px);
    printf("Isi x = %d\n", x);
    printf("Nilai yang ditunjuk oleh px = %d\n", *px);
    printf("Nilai y = %d\n", y);
}