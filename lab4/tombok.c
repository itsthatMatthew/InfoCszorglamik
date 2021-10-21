#include <stdio.h>
#include <stdlib.h>

int NegativakKiindexelese(double eredetiTomb[], int indexTomb[]) {
	int index = 0;
	for (int i = 0; i < 10; i++)
		if (eredetiTomb[i] < 0)
			indexTomb[index++] = i;
	indexTomb[index] = -1;	// tomb zarokaraktere
	return index;
}

int main(void) {
	double tomb[10] = {3.14, -12.1, 22.2, -21.67, 69.42, 420.01, -42.1, 99.9, 100.1, -1.5};

	// Alapveto kiiratas:
	printf("Osszesen 10 szam van.\n");
	for (int i = 0; i < 10; i++)
		printf("[%d]=%g ", i, tomb[i]);

	int negativIndexek[11];	// Legfeljebb csak annyi negativ lehet, ahany elemes a tomb + 1 zaro

	int negativdb = NegativakKiindexelese(tomb, negativIndexek);

	printf("\n\nEbbol %d szam negativ.\n", negativdb);
	int index = 0;
	while (negativIndexek[index] != -1) {	// zarokarakterig beolvasas
		printf("[%d]=%g ", negativIndexek[index], tomb[negativIndexek[index]]);
		index++;
	}

	return 0;
}
