#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mahasiswa.h"

void makeMahasiswa(mahasiswa *m, char name[], int height)
{
    strcpy((*m).name, name);
    m->height = height;
}

mahasiswa createMahasiswa(char name[], int height)
{
    mahasiswa m;

    strcpy(m.name, name);
    m.height = height;

    return m;
}

void printMahasiswa(mahasiswa m)
{
    printf("%s - %d\n", m.name, m.height);
}

const char* getName(mahasiswa *m)
{
    return (*m).name;
}

int getHeight(mahasiswa m)
{
    return m.height;
}

int compareName(mahasiswa a, mahasiswa b)
{
    return strcmp(a.name, b.name);
}

void scanMahasiswa(mahasiswa *m)
{
    char name[20];
    int height;

    scanf("%s", name);
    scanf("%d", &height);

    makeMahasiswa(m, name, height);
}