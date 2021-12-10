/* Fordításhoz:
	gcc .\jatek.c .\karakter.c .\labirintus.c -o .\labirintus.exe
/*

/* A labirintus felépítése:
 * ###### ###
 * #$   #   #
 * #### ### #
 * #        #
 * # #### ###
 * # #    #$#
 * # ##$# # #
 * #@ ### # #
 * #   $#   #
 * ##########
 * ahol:
 *	# - fal
 *	$ - kincs
 *	@ - karakter
 */

// Includeok
#include "debugmalloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "labirintus.h"
#include "karakter.h"
#include "utkereso.h"

// Main

int main(int argc, char const *argv[]) {
	Labirintus labirintus;

	LabFoglal(&labirintus);
	LabEpit(labirintus);

	if (utkereso(labirintus, Holvan(labirintus)))
		printf("Ki lehet jutni!");

	// Újraépitjük, mert az útvonalkereső felhasználta
	LabEpit(labirintus);

	int kincsek = SzumKincsek(labirintus);
	int osszegyujtott = 0;

	// Egy flaggel nézzük, hogy elérte e már a labirintus végét az egyén
	Esemeny flag = J_URES;

	do {
		putchar('\n');
		LabKirajz(labirintus);
		// Beolvassuk, melyik irányba szeretne haladni a karakter
		printf("Bemenet: ");
		char input = getchar(); // Annyi a szépséghibája, hogy nyomva tartott
								// enter esetén (stdin pufferből) a legutóbbi
								// karaktert olvassa be folyamatosan.
		// Ennek megfelelően választunk neki irányt
		Iranyok irany;
		switch (input) {
			case 'w': irany = FEL; break;
			case 'a': irany = BALRA; break;
			case 's': irany = LE; break;
			case 'd': irany = JOBBRA; break;
		}

		// Majd az iránynak megfelelően léptetünk, ha tudunk
		flag = Leptetes(labirintus, irany);

		// Megnézzük, mire léptünk
		if (flag == J_FAL)
			printf("\nErre nem mehetsz!\n");
		else if (flag == J_KINCS)
			osszegyujtott++;
	} while (flag != J_KI);

	LabKirajz(labirintus);
	printf(osszegyujtott == kincsek ? "Nyertel!\n" : "Vesztettel!\n");

	LabSzabad(labirintus);

	return 0;
}
