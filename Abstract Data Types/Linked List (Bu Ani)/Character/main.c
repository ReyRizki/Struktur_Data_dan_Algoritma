#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{	/* Kamus */
	List L;
	address P;

	/* Algoritma */
	/* CREATE LIST & MENGISI ELEMEN LIST */
	CreateList(&L);
	
	InsVFirst(&L, 'u');
	PrintInfo(L);

	InsVLast(&L, 'c');
	PrintInfo(L);

	InsVLast(&L, 'y');
	PrintInfo(L);

	InsVLast(&L, 'n');
	PrintInfo(L);

	InsVLast(&L, 'g');
	PrintInfo(L);

	InsVFirst(&L, 'k');
	PrintInfo(L);

	InsVLast(&L, 'h');
	PrintInfo(L);

	DelP(&L, 'c');
	PrintInfo(L);

	InsertVAfter(&L, 'c', 'i');
	PrintInfo(L);

	DelLast(&L, &P);
	PrintInfo(L);

	DelFirst(&L, &P);
	PrintInfo(L);

	return 0;
}