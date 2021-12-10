#include "debugmalloc.h"
#include "labirintus.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void LabFoglal(Labirintus *lab) {
	// Első körben a pointereknek inicializálunk helyet
	*lab = (char**) malloc(LAB_MAGAS * sizeof(char*));
	// Majd végigiterálva a mutatott sztringeknek
	for (int i = 0; i < LAB_MAGAS; i++)
		(*lab)[i] = (char*) malloc(LAB_SZELES * sizeof(char));
		// Naívan feltesszük, hogy sose lesz NULL pointer
	return; // Visszatérés
}

void LabSzabad(Labirintus lab) {
	// Foglaláshoz hasonlóan, csak fordított sorrendben
	for (int i = 0; i < LAB_MAGAS; i++)
		free(lab[i]);
	// Majd a pointer pointert
	free(lab);

	return; // Visszatérés
}

void LabEpit(Labirintus lab) {
	// Csúnyán ideiglenesen létrehozzuk azt a 2D-s tömb9t, aminek statikus léte
	// ellen egész eddig dolgoztunk, hogy másolhassunk belőle
	char temp[LAB_MAGAS][LAB_SZELES] = { "###### ###",
					     "#$   #   #",
			 		     "#### ### #",
			 		     "#        #",
			 		     "# #### ###",
			 		     "# #    #$#",
			 		     "# ##$# # #",
			 		     "#@ ### # #",
			 		     "#   $#   #",
			 		     "##########"};

	// Végigiterálva a megadott szöveget bemásolva
	for (int i = 0; i < LAB_MAGAS; i++)
		strcpy(lab[i], temp[i]);

	return; // Visszatérés
}

void LabKirajz(Labirintus lab) {
	// Végig iterálva
	for (int i = 0; i < LAB_MAGAS; i++)
		printf("%s\n", lab[i]);

	return; // Visszatérés
}

int SzumKincsek(Labirintus lab) {
	// A változó, amibe összegezni fogunk
	int szum = 0;
	// Végigiterálunk a tömbön
	for (int i = 0; i < LAB_MAGAS; i++)
		for (int j = 0; j < LAB_SZELES - 1; j++)
			if (lab[i][j] == LAB_KINCS)
				szum++; // Egyezés esetén eggyel növelünk

	return szum; // Visszatérés az összeggel
}
