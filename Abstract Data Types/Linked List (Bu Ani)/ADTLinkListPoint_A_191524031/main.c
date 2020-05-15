#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define REP(i, a, b) for (i = (a); i < (b); i++)

int main()
{
	List L1, L2;
	POINT P;
	int N, i;

	CreateList(&L1);
	CreateList(&L2);

	scanf("%d", &N);
	REP(i, 0, N)
	{
		scanPoint(&P);
		InsVLast(&L1, P);
	}
	
	PrintInfo(L1);

	printf("%d\n", countInK(L1, 1));
	printInK(L1, 1);

	copyUndefinedK(L1, &L2);
	PrintInfo(L2);

	DelAll(&L1);
	DelAll(&L2);

	return 0;
}