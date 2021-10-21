#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#endif

int main(void) {
#ifdef _WIN32
	SetConsoleCP(1250);
	SetConsoleOutputCP(1250);
#endif

	int tomb[10] = {3, 12, 22, 21, 69, 420, 42, 99, 100, 1};

	// Alapvető kiiratás:
	printf("A tömb:");
	for (int i = 0; i < 10; i++)
		printf(" %d", tomb[i]);

	// Indexelő kiiratás:
	printf("\n\nA tömb:");
	for (int i = 0; i < 10; i++) {
		printf(" [%d]=%d", i, tomb[i]);
	}

	// Legkisebb kiválasztó programrész:
	int legkisebb = tomb[0];	// Kezdő érték, ahonna el tud indulni
	for (int i = 1; i < 10; i++)	// 0. elemet már nem kell feldolgozni
		if (tomb[i] < legkisebb)
			legkisebb = tomb[i];
	printf("\nLegkisebb szám: %d", legkisebb);

	// Indexelő kiiratás újból (átláthatóság kedvéért):
	printf("\n\nA tömb:");
	for (int i = 0; i < 10; i++) {
		printf(" [%d]=%d", i, tomb[i]);
	}

	// Legkisebb kiválasztó programrész index megőrzésével:
	legkisebb = tomb[0];	// Kezdő értéket ugyan úgy megadjuk
	int minhely = 0;			// Jelenleg tudjuk is, hogy a 0. helyen van
	for (int i = 1; i < 10; i++)
		if (tomb[i] < legkisebb) {
			legkisebb = tomb[i];
			minhely = i;
		}
	printf("\nLegkisebb szám: %d\nLegkisebb szám indexe: %d", legkisebb, minhely);

	// Kiiratás legkisebb megjelölésével:
	printf("\n\nJelölve:");
	for (int i = 0; i < 10; i++) {
		printf(" %d", tomb[i]);
		if (i == minhely)
			printf("[MIN]");
	}

	return 0;
}
