#ifndef UTKERESO_H
#define UTKERESO_H

#include <stdbool.h>
#include "labirintus.h"
#include "karakter.h"

bool utkereso(Labirintus lab, Karakter karakter) {
	// & karakterek jelölik a bejárt útvonalat (vizuálisabb + nincs végtelen ciklus)
	if (lab[karakter.x][karakter.y] == LAB_FAL || lab[karakter.x][karakter.y] =='&')
		return false;
	if (karakter.x == 0 || karakter.x == LAB_MAGAS ||
		karakter.y == 0 || karakter.y == LAB_SZELES - 1)
		return true;
	Karakter karakterfel, karakterle, karakterbal, karakterjobb;
	karakterfel = karakterle = karakterbal = karakterjobb = karakter;
	karakterfel.x--;
	karakterle.x++;
	karakterbal.y--;
	karakterjobb.y++;
	lab[karakter.x][karakter.y] = '&';

	putchar('\n');
	LabKirajz(lab); // Csak vizualizáció
	putchar('\n');

	// Fájdalmas felsorolás, de azonnali visszatérést eredményez
	if (utkereso(lab, karakterfel))
		return true;
	if (utkereso(lab, karakterjobb))
		return true;
	if (utkereso(lab, karakterle))
		return true;
	if (utkereso(lab, karakterbal))
		return true;
	return false;
}

#endif
