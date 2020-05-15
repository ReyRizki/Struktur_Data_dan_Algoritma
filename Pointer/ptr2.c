/* --------------------------------------------------------- */
/* File Program : PTR2.CPP */
/* Contoh pemakaian pointer yang salah */
/* Tujuan : mengetahui panjang dan posisi variabel di memory */
/* --------------------------------------------------------- */
#include <stdio.h>

int main()
{
    // deklarasi
    float *pu;
    float nu;
    int u = 1234;
    
    // assignment
    pu = &u;
    nu = *pu;
    
    // output
    printf("u = %d\n", u);
    printf("nu = %f\n", nu);
    
    return 0;
    /* STUDI KASUS : */
    /* - Eksekusi file program tersebut dan pahami maksud program ini */
    /* - Komentari setiap baris program (maksud tiap pernyataan di tiap baris program ) */
    /* - Tulis hasil pemahaman Anda pada kertas yang disediakan */
}