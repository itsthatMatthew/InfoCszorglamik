#include <stdio.h>

typedef struct Datum {
    int ev, ho, nap;
} Datum;

typedef struct Versenyzo {
    char nev[31];
    Datum szuletes;
    int helyezes;
} Versenyzo;

void datum_kiir(Datum d);

void versenyzo_kiir(Versenyzo v);

int main() {
    Versenyzo versenyzok[5] = {
        { "Am Erika", {1984, 5, 6}, 1 },
        { "Break Elek", {1982, 9, 30}, 3 },
        { "Dil Emma", {1988, 8, 25}, 2 },
        { "Kasza Blanka", {1979, 6, 10}, 5 },
        { "Reset Elek", {1992, 4, 5}, 4 },
    };

    /* 0-s versenyző neve - printf %s */
	printf("A 0-s versenyzo neve: %s\n", versenyzok[0].nev);
    /* 2-es versenyző helyezése */
	printf("\nA 2-es versenyzo helyezese: %d\n", versenyzok[2].helyezes);
    /* 4-es versenyző születési dátumát (írd meg a datum_kiir függvényt!) */
	printf("\nA 4-es versenyzo szuletesi datuma: ");
	datum_kiir(versenyzok[4].szuletes);
    /* 1-es versenyző nevének kezdőbetűjét (ne feledd, a sztring karaktertömb) */
	printf("\n\nAz 1-es versenyzo nevenek kezdobetuje: %c\n", versenyzok[1].nev[0]);
    /* az 1-es versenyző dobogós-e? igen/nem, akár ?: operátorral, de egy printf-fel */
	versenyzok[1].helyezes < 4 ? printf("\nAz 1-es versenyzo dobogos.\n") :
	printf("\nAz 1-es versenyzo nem dobogos.\n");
    /* az 4-es versenyző gyorsabb-e, mint a 3-as versenyző? */
	versenyzok[4].helyezes < versenyzok[3].helyezes ?
	printf("\nA 4-es versenyzo gyorsabb, mint a 3-as.\n") :
	printf("\nA 4-es versenyzo nem gyorsabb, mint a 3-as.\n");
    /* az 1-es versenyző ugyanabban az évben született-e, mint a 2-es? */
	versenyzok[1].szuletes.ev == versenyzok[2].szuletes.ev ?
	printf("\nIgen, az 1-es versenyzo ugyan abban az evben szuletett, mint a 2-es.\n") :
	printf("\nNem, az 1-es versenyzo nem ugyan abban az evben szuletett, mint a 2-es.\n");
    /* egészítsd ki a versenyzo_kiir() függvényt,
     * aztán írd ki az 1-es versenyző összes adatát */
	printf("\nAz 1-es versenyzo adatai:\n");
	versenyzo_kiir(versenyzok[1]);
    /* végül listázd ki az összes versenyzőt sorszámozva, összes adatukkal. */
	for (int i = 0; i < 5; i++) {
		printf("\n%d. versenyzo adatai:\n", i);
		versenyzo_kiir(versenyzok[i]);
	}

    return 0;
}

void datum_kiir(Datum d) {
    /* dátum kiírása */
	// Dátum formátum: éééé.hh.nn
	printf("%04d.%02d.%02d", d.ev, d.ho, d.nap);
}

void versenyzo_kiir(Versenyzo v) {
    /* a versenyző összes adatának kiírása */
	printf("Neve:\t\t\t%s\n", v.nev);
	printf("Szuletesi datum:\t");
	datum_kiir(v.szuletes);
	printf("\nHelyezese:\t\t%d.\n", v.helyezes);
}
