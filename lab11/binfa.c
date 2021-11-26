#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h" // memóriaszivárgás keresésére

typedef struct BiFa {
    int ertek;
    struct BiFa *bal, *jobb;
} BiFa;

BiFa *beszur(BiFa *gyoker, int ertek) {
    if (gyoker == NULL) {
        BiFa *uj = (BiFa*) malloc(sizeof(BiFa));
        uj->ertek = ertek;
        uj->bal = uj->jobb = NULL;
        return uj;
    }
    if (ertek < gyoker->ertek) {        /* balra szur */
        gyoker->bal = beszur(gyoker->bal, ertek);
    }
    else if (ertek > gyoker->ertek) {   /* jobbra szur */
        gyoker->jobb = beszur(gyoker->jobb, ertek);
    }
    else {
        /* mar benne van */
    }
    return gyoker;
}

void inorderKiir(BiFa *gyoker);

void freeTree(BiFa *gyoker);

int countCells(BiFa *gyoker);

int sumCells(BiFa *gyoker);

BiFa *findValinTree(int n, BiFa *gyoker);

void negateTree(BiFa *gyoker);

BiFa *findNegated(int n, BiFa *gyoker);

void flipTree(BiFa *gyoker);

int main(void) {
    int minta[] = {15, 96, 34, 12, 14, 56, 21, 11, 10, 9, 78, 43, 0};
    BiFa *gyoker = NULL;
    for (int i = 0; minta[i] > 0; i++)
        gyoker = beszur(gyoker, minta[i]);

    /* Ide tedd be a kipróbálandó függvények hívásait! */

	inorderKiir(gyoker);

	printf("\nElemeinek szama: %d\n", countCells(gyoker));
	printf("Elemek ertekenek osszege: %d\n", sumCells(gyoker));

	int vals[] = {12, 15, 99, -3};

	for (int i = 0; i < 4; i++) {
		BiFa *ret = findValinTree(vals[i], gyoker);
		ret == NULL ? printf("%d nem talalhato meg a faban\n", vals[i]) : printf("%d megtalalva a faban faban (elem cime: 0x%0x)\n", vals[i], ret);
	}

	negateTree(gyoker);

	inorderKiir(gyoker);

	printf("\nNegalas utan eredeti kereses:\n");

	int val = -12;

	BiFa *negret = findValinTree(val, gyoker);
	negret == NULL ? printf("%d nem talalhato meg a faban\n", val) : printf("%d megtalalva a faban faban (elem cime: 0x%0x)\n", val, negret);

	printf("Negalas utan uj kereses:\n");

	negret = findNegated(val, gyoker);
	negret == NULL ? printf("%d nem talalhato meg a faban\n", val) : printf("%d megtalalva a faban faban (elem cime: 0x%0x)\n", val, negret);

	printf("Fa tukrozese utan eredeti kiiratas:\n");
	flipTree(gyoker);
	inorderKiir(gyoker);
	printf("\n");

	freeTree(gyoker);

    return 0;
}

// inorder bejarassal
void inorderKiir(BiFa *gyoker) {
	if (gyoker == NULL)
		return;

	inorderKiir(gyoker->bal);
	printf("%d ", gyoker->ertek);
	inorderKiir(gyoker->jobb);
	return;
}

// preorder bejarassal
void freeTree(BiFa *gyoker) {
	if (gyoker == NULL)
		return;

	freeTree(gyoker->bal);
	freeTree(gyoker->jobb);
	free(gyoker);
	return;
}

// preored
int countCells(BiFa *gyoker) {
	if (gyoker == NULL)
		return 0;

	int n = 0;
	n += countCells(gyoker->bal);
	n += countCells(gyoker->jobb);
	return n + 1;
}

// preorder
int sumCells(BiFa *gyoker) {
	if (gyoker == NULL)
		return 0;

	int n = 0;
	n += sumCells(gyoker->bal);
	n += sumCells(gyoker->jobb);
	return gyoker->ertek + n;
}

// ha NULL, nincs, ha megegyezik, az, egyébként elágazunk
BiFa *findValinTree(int n, BiFa *gyoker) {
	if (gyoker == NULL) {
		return NULL;
	}else if (n == gyoker->ertek) {
		return gyoker;
	} else if (n < gyoker->ertek) {
		findValinTree(n, gyoker->bal);
	} else {
		findValinTree(n, gyoker->jobb);
	}
}

// szimpla inorder bejárással
void negateTree(BiFa *gyoker) {
	if (gyoker == NULL)
		return;

	negateTree(gyoker->bal);
	gyoker->ertek *= -1;
	negateTree(gyoker->jobb);
	return;
}

// relációs jelet fel kell cserélni!
BiFa *findNegated(int n, BiFa *gyoker) {
	if (gyoker == NULL) {
		return NULL;
	}else if (n == gyoker->ertek) {
		return gyoker;
	} else if (n > gyoker->ertek) {
		findValinTree(n, gyoker->bal);
	} else {
		findValinTree(n, gyoker->jobb);
	}
}

// preorder
void flipTree(BiFa *gyoker) {
	if (gyoker == NULL)
		return;

	flipTree(gyoker->bal);
	flipTree(gyoker->jobb);
	BiFa *temp = gyoker->bal;
	gyoker->bal = gyoker->jobb;
	gyoker->jobb = temp;
	return;
}
