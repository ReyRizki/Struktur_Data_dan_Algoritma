/*
Nama Program : Mysteri.cpp
Deskripsi    : Belajar pointer untuk integer dan double
Programmer   : Rey Rizki
Tanggal      : 21 Feb 2020
Versi        : 1

*/

#include <stdio.h>

int main()
{
    int *intPtr;
    double *dubPtr;

    //deklarasi var integer dan double
    int int1, int2, int3, int4, int5;
    double dub1, dub2, dub3, dub4, dub5;

    /*Inisialisasi nilai variabel*/
    int1 = 54;
    int2 = 10;
    int3 = 96;
    int4 = 21;
    int5 = 88;
    dub1 = 64.32;
    dub2 = 143.3;
    dub3 = 79.12;
    dub4 = 76.78;
    dub5 = 52.5;

    intPtr = &int1;
    dubPtr = &dub1;

    // //Output 1
    // printf("Output 1 :  Variabel bertipe integer dan double \n\n");
    // printf("Tipe integer :  \n");
    // printf("int1 = %d, int2 = %d, int3 = %d, int4 = %d, int5 = %d\n\n", int1, int2, int3, int4, int5);

    printf("Tipe double :  \n");
    printf("dub1 = %g, dub2 = %g, dub3 = %g, dub4 = %g, dub5 = %g", dub1, dub2, dub3, dub4, dub5);

    // //Menampilkan alamat (dan pointer) dalam hexa
    // printf("\n\nOutput 2 : Alamat dan variabel pointer bertipe integer : \n");
    // printf("Alamat memori int1, int2, dan int3 : %p, %p, %p\n", &int1, &int2, &int3);

    // // printf("\n\nMenampilkan data integer menggunakan pointer (+decrement) : *(intPtr) *(--intPtr) *(--intPtr)\n\n");

    // printf("--> *intPtr = %d", *intPtr);
    // printf("\n--> *(--intPtr) = %d", *(--intPtr));
    // printf("\n--> *(--intPtr) = %d", *(--intPtr));

    // intPtr = &int1;
    // printf("\n\n Menampilkan data integer menggunakan pointer (+increment) : *(intPtr) *(++intPtr) *(++intPtr)\n");
    // printf("--> *intPtr = %d", *intPtr);
    // printf("\n--> *(++intPtr) = %d", *(++intPtr));
    // printf("\n--> *(++intPtr) = %d\n", *(++intPtr));

    // //Pertanyaan : alamat &int4 dan &int5 ?
    // printf("\nAlamat memori int4 dan int5: %p, %p\n", &int4, &int5);

    //Output 3 : Alamat dan variabel pointer bertipe double

    printf("\nOUTPUT 3 : Alamat dan Variabel Pointer bertipe double ");
    printf("\nAlamat Memori : dub1 = %p, dub2 = %p, dub3 = %p , dub4 = %p , dub5 = %p", &dub1, &dub2, &dub3, &dub4, &dub5);

    dubPtr = &dub5;
    printf("\n%p %g\n", dubPtr, *dubPtr);
    int i;
    for (i = 4; i >= 0; i--)
        printf("%g ", *dubPtr--);
    
    printf("\n");

    dubPtr = &dub5;
    printf("%g, %g, %g\n", *dubPtr, *(--dubPtr), *(--dubPtr));
    // printf("\n\nMenampilkan data double menggunakan pointer (+decrement) : *(dubPtr), *(--dubPtr), *(--dubPtr)");
    // printf("\n*(dubPtr) = %g, *(--dubPtr) = %g, *(--dubPtr) = %g\n", *(dubPtr), *(--dubPtr), *(--dubPtr));

    // printf("\n\nMenampilkan data double menggunakan pointer (+increment) : *(dubPtr), *(++dubPtr), *(++dubPtr)");
    // printf("\n*(dubPtr) = %g, *(++dubPtr) = %g, *(++dubPtr) = %g", *(dubPtr), *(++dubPtr), *(++dubPtr));

    // printf("\n\nMenampilkan data double menggunakan pointer (+decrement) : *(dubPtr), *(--dubPtr), *(--dubPtr)");
    // printf("\n*(dubPtr) = %g, *(--dubPtr) = %g, *(--dubPtr) = %g\n", *(dubPtr), *(--dubPtr), *(--dubPtr));

    return 0;
}