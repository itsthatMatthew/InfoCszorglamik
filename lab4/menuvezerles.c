#include <stdio.h>

void Alapertek(int *n) {
	*n = 1;
}

void Noveles(int *n) {
	(*n)++;	// nem a pointert, hanem a mutatott valtozo erteket akarjuk novelni
}

void Elojelvaltas(int *n) {
	*n *= -1;
}

void Szorzas(int *n) {
	*n *= 2;
}

int main(void) {
	int a = 1, parancs;
	do {
		printf("\na = %d\n\n", a);

		printf("0. Alapertek visszaallitasa (a = 1)\n"
		   "1. Hozzaad 1-et\n"
		   "2. Megforditja az elojelet\n"
		   "3. Szorozza 2-vel\n"
		   "9. Kilepes\n");

		scanf("%d", &parancs);	// vakon bizunk benne, hogy a felhasznalo szamot ad meg

		switch (parancs) {
			case 0:
				Alapertek(&a);
				break;
			case 1:
				Noveles(&a);
				break;
			case 2:
				Elojelvaltas(&a);
				break;
			case 3:
				Szorzas(&a);
				break;
			default:
				break;
		}
	} while(parancs != 9);

	return 0;
}
