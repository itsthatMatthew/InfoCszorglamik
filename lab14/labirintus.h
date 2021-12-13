#ifndef LABIRINTUS_H
#define LABIRINTUS_H

// A labirintus méretéből adódó konstansok
#define LAB_MAGAS  10
#define LAB_SZELES 11 // +1 \0 miatt
// Labirinuts elemei
#define LAB_FAL '#'
#define LAB_KINCS '$'
#define LAB_KARAKTER '@'
#define LAB_URES ' '

// Labirintus
// 2D-s tömb, aminek dinamikusan foglalunk memóriát: pointerekre mutató pointer.
// Saját dolgunk megkönnyítése érdekében típusdefinícióval elfedjük.
typedef char** Labirintus;
// Feltölti a labirintust a szükséges sztringekkel
void LabFoglal(Labirintus*); // Mivel magának a pointer-pointernek az értékét
			     // akarjuk megváltoztatni, kénytelenek vagyunk
			     // az erre mutató pointert bekérni, így
			     // függvényhíváskor majd címet kell képeznünk.
// Felszabadítja a labirintust
void LabSzabad(Labirintus);
// A labirintus feltöltése a labor anyagában megadottal
void LabEpit(Labirintus);
// A labirintust megjelenítő függvény
void LabKirajz(Labirintus);
// Kincsek számának meghatározása
int SzumKincsek(Labirintus);

#endif /* LABIRINTUS_H */
