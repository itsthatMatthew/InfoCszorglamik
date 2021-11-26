#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"

typedef struct Szoba {
	int szobaszam;
	char vendeg[50 + 1];
	struct Szoba *kov;
} Szoba;

Szoba *Beolvas(char *fajlnev) {
	FILE *fptr;
	fptr = fopen(fajlnev, "rt");

	if (fptr == NULL) {
		printf("Hiba: %s fajlt nem lehet megnyitni.\n", fajlnev);
		return NULL;
	}

	Szoba *ret  = NULL;

	while (!feof(fptr)) {
		Szoba *uj;
		uj = (Szoba *) malloc(sizeof(Szoba));
		uj->kov = ret;
		fscanf(fptr, "%d %[^\n] ", &uj->szobaszam, &uj->vendeg);
		ret = uj;
	}

	fclose(fptr);
	return ret;
}

void FreeLista(Szoba *kov) {
	Szoba *lemarado = NULL;
	while (kov !=NULL) {
		lemarado = kov;
		kov = kov->kov;
		free(lemarado);
	}
	return;
}

void SzintEloszlas(Szoba *szobak, int szintek[8]) {
	for (Szoba *mozgo = szobak; mozgo !=NULL; mozgo = mozgo->kov) {
		szintek[mozgo->szobaszam / 100] ++;
	}
	return;
}

int Legzsufoltabb(int szintek[8]) {
	int index = 0;
	int tempmenny = szintek[0];

	for (int i = 0; i < 8; i++)
		if (tempmenny < szintek[i]) {
			tempmenny = szintek[i];
			index = i;
		}

	return index;
}

int main(int argc, char const *argv[]) {
	Szoba *szobak = Beolvas("foglalasok.txt");

	int szintek[8] = {0};
	SzintEloszlas(szobak, szintek);

	printf("A legzsufoltabb szint: %d.\n", Legzsufoltabb(szintek));

	FreeLista(szobak);

	return 0;
}
