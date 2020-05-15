/* --------------------------------------------------------- */
/* File Program : ptr1.c */
/* Contoh pemakaian pointer */
/* Tujuan : mengetahui panjang dan posisi variabel di memory */
/* --------------------------------------------------------- */
#include <stdio.h>
int main()
{
    int x, y; // deklarasi
    int *px;  // deklarasi

    x = 87;  // assignment biasa
    // px = &x; // assignment pointer
    y = *px; // assignment dengan isi memory

    printf("Alamat x = %p\n", &x);                     // print alamat x
    printf("Isi px = %d\n", x);                        // print isi px
    printf("Nilai yang ditunjuk oleh px = %d\n", *px); // print isi yang ditunjuk oleh px
    printf("Nilai y = %d\n", y);                       // print nilai y
    printf("Alamat y = %p\n", &y);

    return 0;
    /* STUDI KASUS : */
    /* - Eksekusi file program tersebut dan pahami maksud program ini */
    /* - Komentari setiap baris program (maksud tiap pernyataan di tiap baris program ) */
    /* - Tambahkan pernyataan untuk menampilkan Alamat varabel y, eksekusi, dan perhatikan hasilnya */
    /* - Bila pernyataan px = &x; diganti dengan y = *px; ,apa yang terjadi? */
    /* - Tulis hasil pemahaman Anda pada kertas yang disediakan */
}