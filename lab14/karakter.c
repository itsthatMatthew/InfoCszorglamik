#include "debugmalloc.h"
#include "karakter.h"

Karakter Holvan(Labirintus lab) {
	// Végigiterálva, amíg meg nincs
	for (int i = 0; i < LAB_MAGAS; i++)
		for (int j = 0; j < LAB_SZELES - 1; j++)
			if (lab[i][j] == LAB_KARAKTER) {
				Karakter vissza = {i, j}; // Fontos: koordináták "felcserélve"!
				return vissza; // Visszatérés, ha benne van
			}

	// Ha nem lenne benne (nagy baj)
	Karakter problema = {-1, -1};
	return problema; // Vicc, mert ezt igazából sosem kezeljük a programban,
					 // de lehetne.
}

// Egy lépést kiszámító segédfüggvény
Karakter Lep(Labirintus lab, Iranyok irany) {
	// Előszőr képezzük a karaktert
	Karakter karakter = Holvan(lab);
	// Majd értékeit az iránynak megfelelően változtatjuk
	switch (irany) {
		case LE:
		case FEL:
			irany == FEL ? karakter.x-- : karakter.x++;
			break;
		case BALRA:
		case JOBBRA:
			irany == BALRA ? karakter.y-- : karakter.y++;
			break;
	}

	return karakter; // Végül visszatérünk az új koordinátákkal
}

bool MehetArra(Labirintus lab, Iranyok irany) {
	Karakter karakter = Lep(lab, irany);
	// Majd ellenőrizzük, hogy léphet e oda, és ezzel térjünk vissza
	return lab[karakter.x][karakter.y] != LAB_FAL; // Léphet, ha nem fal
}

Esemeny Leptetes(Labirintus lab, Iranyok irany) {
	// Megnézzük, hogy az adott irányba léptethető-e
	if (!MehetArra(lab, irany))
		return J_FAL; // Ha fal, ezzel térünk vissza egyből a függvény elején

	// Ha nem falba léptünk, nézzük meg, hogy az adott helyen mi található
	// A visszatérési értéknek változót foglalunk
	Esemeny esemeny = J_URES;

	// Karaktert léptetjük
	Karakter karaktereredeti = Holvan(lab);
	Karakter karakteruj = Lep(lab, irany);

	// Ezek utánn megnézzük, hogy milyen mezőre lépett
	// Ha kint van a játéktérről
	if (karakteruj.x == 0 || karakteruj.x == LAB_MAGAS ||
		karakteruj.y == 0 || karakteruj.y == LAB_SZELES - 1)
		esemeny = J_KI;
	// Ha kincsbe lépett
	if (lab[karakteruj.x][karakteruj.y] == LAB_KINCS)
		esemeny = J_KINCS;

	// Mindezek után pedig megváltoztatjuk a tömböt
	lab[karaktereredeti.x][karaktereredeti.y] = LAB_URES;
	lab[karakteruj.x][karakteruj.y] = LAB_KARAKTER;

	return esemeny; // Visszatérés a bekövetkezett eseménnyel
}
