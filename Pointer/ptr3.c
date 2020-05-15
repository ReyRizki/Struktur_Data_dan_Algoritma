/* --------------------------------------------------------- */
/* File Program : PTR3.CPP */
/* Contoh pengubahan isi suatu variabel melalui pointer */
/* Tujuan : Menggunakan type data pointer dan manipulasinya */
/* --------------------------------------------------------- */
#include <stdio.h>
int main()
{
    // deklarasi
    float d, *pd;
    
    // inisialisasi d
    d = 54.5;
    printf("Isi d semula = %g\n", d);

    // mengubah isi d dengan pointer
    pd = &d;
    *pd = *pd + 10;
    printf("Isi d kini = %g\n", d);
    
    return 0;
    /* STUDI KASUS : */
    /* - Eksekusi file program tersebut dan pahami maksud program ini */
    /* - Komentari setiap baris program (maksud tiap pernyataan di tiap baris program ) */
    /* - Tulis hasil pemahaman Anda pada kertas yang disediakan */
}