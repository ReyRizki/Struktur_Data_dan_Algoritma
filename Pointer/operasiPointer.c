#include <stdio.h>

int main()
{
    int *ptr;
    int x = 2;           // deklarasi
    ptr = &x;            // pointer menunjuk ke x
    printf("%p\n", ptr); // alamat yang ditunjuk pointer
    ptr++;               // operasi pada pointer
    printf("%p\n", ptr); // alamat yang ditunjuk pointer
    return 0;
}