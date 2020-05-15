/* ----------------------------------------------------- */
/* File Program : PTR6.CPP */
/* Deskripsi : pointer yang menunjuk ke array */
/* ---------------------------------------------------- */
#include <stdio.h>

#define REP(i, a, b) for (i = (a); i < (b); i++)
int main()
{
    /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
    static int tgl_lahir[] = {18, 6, 1989};
    int *ptgl;
    ptgl = tgl_lahir;
    printf("Nilai yang ditunjuk oleh ptgl = %d\n", *ptgl);
    printf("Nilai dari tgl_lahir[0] = %d\n", tgl_lahir[0]);

    int i;
    REP(i, 0, 3)
        printf("%d ", *ptgl++);
    printf("\n");
    
    return 0;
}
/* STUDI KASUS : */
/* Eksekusi dan pahami maksud program ini (tulis tujuan program ini) */
/* Modifikasi program tersebut agar bisa menampilkan seluruh elemen array tgl_lahir !*/