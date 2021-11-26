#include <stdio.h>
#include <stdlib.h>

typedef struct ListaElem {
    int adat;
    struct ListaElem *kov;
} ListaElem;


/* létrehoz egy listát, benne egy csomó számmal */
ListaElem *lista_letrehoz(void) {
    int szamok[] = { 8, 14, 13, 17, 1, 19, 16, 5, 3, 11, 2,
                     15, 9, 10, 6, 22, 4, 7, 18, 27, -1 };
    ListaElem *lis = NULL;

    for (int i = 0; szamok[i] != -1; ++i) {
        ListaElem *u;
        u = (ListaElem*) malloc(sizeof(ListaElem));
        u->kov = lis;
        u->adat = szamok[i];
        lis = u;
    }
    return lis;
}

// A lista felszabadítását végző függvény
void freeLista(ListaElem *listptr) {
	ListaElem *temp = listptr;

	while(temp != NULL) {
		ListaElem *nxtptr = temp->kov;
		free(temp);
		temp = nxtptr->kov;
	}

	return;
}

// A lista elejére beszúró függvény
ListaElem *lista_elejere_beszur(ListaElem *lstptr, int n) {
	ListaElem *new = (ListaElem *) malloc(sizeof(ListaElem));

	new->kov = lstptr;
	new->adat = n;

	return new;
}

// Lista végére beszúró fv
void listaVegereBeszur(ListaElem **listptr, int n) {
	// az új elem elkészítése
	ListaElem *new = (ListaElem *) malloc(sizeof(ListaElem));
	new->adat = n;
	new->kov = NULL;

	// listához fűzése
	if (*listptr == NULL)
		listptr = &new; // ha üres lista, simán legyen ez az első elem
	else {
		// ha nem üres, keressük meg a végső elemét és ahhoz fűzzük hozzá
		ListaElem *lastptr, *prevptr;
	    for (lastptr = *listptr; lastptr != NULL ; lastptr = lastptr->kov)
			prevptr = lastptr;
		// ennek a végén az utolsó elemre mutat
		prevptr->kov = new;
	}

	return;
}

ListaElem *listaKeres(ListaElem *listptr, int n) {
	for (ListaElem *mozgo = listptr; mozgo != NULL; mozgo = mozgo->kov)
		if (mozgo->adat == n)
			return mozgo;
	return NULL;
}

int main(void) {
    ListaElem *eleje;

    eleje = lista_letrehoz();

	/* Lista elemeinek kiírása */

	ListaElem *mozgo;
    for (mozgo = eleje; mozgo != NULL ; mozgo = mozgo->kov)
    	printf("%d ", mozgo->adat);
	// Fordítva írja ki az adatokat a tömbhöz képest, mert lényegében a listát
	// magát "visszafelé" töltjük fel, NULL zárómutatóval kezdve, mindig eggyel-
	// eggyel visszalépve mutatva a legutóbb letárolt listaelemre.

	/* Lista hosszának meghatározása */

	int hossz = 0;
	for (mozgo = eleje; mozgo != NULL ; mozgo = mozgo->kov, hossz++);
	printf("\n%d\n", hossz);

	/* Lista elejére beszúrás */

	eleje = lista_elejere_beszur(eleje, 21);
	// még pár adat hozzáadása
	eleje = lista_elejere_beszur(eleje, 3);
	eleje = lista_elejere_beszur(eleje, 2);
	eleje = lista_elejere_beszur(eleje, 1);
	// + kiiratás
    for (mozgo = eleje; mozgo != NULL ; mozgo = mozgo->kov)
    	printf("%d ", mozgo->adat);

	/* Lista végéhez való hozzáfűzés */

	listaVegereBeszur(&eleje, 69);
	// + kiiratás
	printf("\n");
    for (mozgo = eleje; mozgo != NULL ; mozgo = mozgo->kov)
    	printf("%d ", mozgo->adat);

	/* Listában keresés */

	ListaElem *talalt = listaKeres(eleje, 19);
	if (talalt == NULL)
		printf("\nA keresett adat \"19\" nincs a listaban.");
	else
		printf("\nA keresett adat \"19\" megtalalva: %d", talalt->adat);


	talalt = listaKeres(eleje, 0);
	if (talalt == NULL)
		printf("\nA keresett adat \"0\" nincs a listaban.");
	else
		printf("\nA keresett adat \"0\" megtalalva: %d", talalt->adat);

	/* A lista felszabadítása */

	freeLista(eleje);

    return 0;
}
