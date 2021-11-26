#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debugmalloc.h"

typedef struct MegalloLista {
	char nev[50 + 1];
	struct MegalloLista *kov;
} MegalloLista;

MegalloLista *Beolvas(char *fajlnev) {
	FILE *fptr;
	fptr = fopen(fajlnev, "rt");

	if (fptr == NULL) {
		printf("Hiba: %s fajlt nem lehet megnyitni.\n", fajlnev);
		return NULL;
	}

	MegalloLista *ret  = NULL;

	while (!feof(fptr)) {
		MegalloLista *uj;
		uj = (MegalloLista *) malloc(sizeof(MegalloLista));
		uj->kov = ret;
		/* Beolvasást trükkösen kell megcsinálna, hogy sorról sorra történjen */
		/* Vagy így: */
		//fscanf(fptr, "%[^\n] ", &uj->nev); // formázott beolvasással
		/* Vagy így: */
		fgets(uj->nev, 50 + 1, fptr); // teljes sort olvasunk, de
		uj->nev[strcspn(uj->nev, "\n")] = 0; // sorvégi \n-t eltávolítjuk
		ret = uj;								// (string.h szükséges)
	}

	fclose(fptr);
	return ret;
}

void FreeLista(MegalloLista *kov) {
	MegalloLista *lemarado = NULL;
	while (kov !=NULL) {
		lemarado = kov;
		kov = kov->kov;
		free(lemarado);
	}
	return;
}

char *Atszallas(MegalloLista *v1, MegalloLista *v2) {
	// Végigiterálás, v1 összesére leteszteljük v2 összesét.
	// Lassú de egyszerű és biztos megoldsá.
	for (MegalloLista *mozgok = v1; mozgok !=NULL; mozgok = mozgok->kov)
		for (MegalloLista *mozgob = v2; mozgob !=NULL; mozgob = mozgob->kov)
			if (strcmp(mozgok->nev, mozgob->nev) == 0)
				return mozgok->nev;

	return NULL;
}

int main(int argc, char const *argv[]) {
	MegalloLista *M2 = Beolvas("m2.txt");
	MegalloLista *M3 = Beolvas("m3.txt");

	char *kmegallo = Atszallas(M2, M3);

	if (kmegallo != NULL)
		printf("A kovetkezo megalloban lehet atszallni: %s.\n", kmegallo);
	else
		printf("Nincs atszallasi lehetoseg.\n");

	FreeLista(M2);
	FreeLista(M3);

	return 0;
}
