#include <stdio.h>

int TkeresIdx(int * tomb, int meret, int x) {
	for (int i = 0; i < meret; i++)
		if (tomb[i] == x)
			return i;

	return -1;
}

int * TkeresPtr(int * tomb, int meret, int x) {
	for (int i = 0; i < meret; i++)
		if (tomb[i] == x)
			return &tomb[i];

	return NULL;
}

int * PkeresPtr(int * tomb, int meret, int x) {
	int * meretp = tomb + meret;
	for (; tomb < meretp; tomb++)
		if (*tomb == x)
			return tomb;

	return NULL;
}

int main(void) {
	int tomb[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int keresett = 5;
	int meret = sizeof(tomb) / sizeof(int);

	int index;
	index = TkeresIdx(tomb, meret, keresett);

	int *ptr;
	ptr = TkeresPtr(tomb, meret, keresett);

	int *ptrp;
	ptrp = PkeresPtr(tomb, meret, keresett);

	printf( index == -1 ? "nincs talalat" : "%d", index );
	printf("\n");
	printf( ptr == NULL ? "nincs talalat" : "%d", ptr - tomb );
	printf("\n");
	printf( ptrp == NULL ? "nincs talalat" : "%d", ptrp - tomb );

	return 0;
}
