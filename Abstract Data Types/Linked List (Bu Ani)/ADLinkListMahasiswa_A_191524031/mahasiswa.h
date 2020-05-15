#ifndef MAHASISWA_H_
#define MAHASISWA_H_

typedef struct
{
    char name[20];
    int height;
} mahasiswa;

void makeMahasiswa(mahasiswa *m, char name[], int height);

mahasiswa createMahasiswa(char name[], int height);

void printMahasiswa(mahasiswa m);

const char* getName(mahasiswa *m);

int getHeight(mahasiswa m);

int compareName(mahasiswa a, mahasiswa b);

void scanMahasiswa(mahasiswa *m);

#endif