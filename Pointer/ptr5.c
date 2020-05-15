/* ----------------------------------------------------------------------------------------------------------- */
/* File Program : PTR5.CPP */
/* Deskripsi : pointer ke type dasar, mendeklarasikan & alokasi variabel dinamik */
/* TUGAS : Tuliskan hasil eksekusi setiap statement program dan hasil pemahaman anda ! */
/* ----------------------------------------------------------------------------------------------------------- */
#include <stdlib.h>
#include <stdio.h>

int main()
{
    /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
    int i = 5, j;
    char c = 'X';
    int *Ptri = (int *)malloc(4);
    int *Ptrj = (int *)malloc(sizeof(int));
    float *fx = (float *)malloc(sizeof(float));
    int A[5];
    float f = 7.23;

    /* program */
    *Ptri = 8;
    *Ptrj = 0;
    *fx = 3;
    
    printf("Alamat i = %p \n", &i);
    printf("Nilai i = %d \n", i);
    printf("Ukuran int = %ld byte\n\n", sizeof(int));
    printf("Alamat j = %p \n", &j);
    printf("Nilai j = %d \n", j);
    printf("Alamat c = %p \n", &c);
    printf("Nilai c = %c \n", c);
    printf("Ukuran char = %ld byte\n\n", sizeof(char));
    printf("Alamat Ptri = %p \n", &Ptri);
    printf("Isi var Ptri = %p \n", Ptri);
    printf("Nilai yang ditunjuk oleh Ptri = %d \n", *Ptri);
    printf("Ukuran pointer int = %ld byte\n\n", sizeof(int *));
    printf("Alamat Ptrj = %p \n", &Ptrj);
    printf("Isi var Ptrj = %p \n", Ptrj);
    printf("Nilai yang ditunjuk oleh Ptrj = %d \n", *Ptrj);
    
    Ptrj = Ptri;
    printf("Isi var Ptrj sekarang = %p \n", Ptrj);
    printf("Nilai yang ditunjuk oleh Ptrj sekarang = %d \n", *Ptrj);
    printf("Alamat A = %p \n", &A);
    printf("Isi var A = %x \n", A[0]);
    printf("Ukuran array A = %ld byte\n\n", sizeof(A));
    printf("Alamat f = %p \n", &f);
    printf("Nilai f = %f \n", f);
    printf("Ukuran float = %ld byte\n\n", sizeof(float));
    return 0;
}