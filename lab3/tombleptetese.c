#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// Tömb deklaráció:
	char nev[10] = "Pitagorasz";

	// Kiiratás:
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			printf("%c ", nev[abs((j + i) % 10)]);
		printf("\n");
	}
}
