#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mahasiswa.h"

#define REP(i, a, b) for (i = (a); i < (b); i++)

int main()
{
	List L1, L2;
	mahasiswa m;
	int N, i;

	CreateList(&L1);
	CreateList(&L2);

	scanf("%d", &N);
	REP(i, 0, N)
	{
		scanMahasiswa(&m);
		insertMahasiswa(&L1, m);
	}

	PrintInfo(L1);

	printf("%d\n", NbElmt(L1));

	copy170(L1, &L2);
	PrintInfo(L2);

	makeUniqueList(&L2);
	PrintInfo(L2);

	// makeMahasiswa(&m, "Rey", 100);
	// makeMahasiswa(&n, "Frank", 1000);

	// printf("%d\n", compareName(n, m));

	// printf("%s\n", getName(&m));
	// printf("%d\n", getHeight(m));
	
	// scanMahasiswa(&m);
	// printMahasiswa(m);

}