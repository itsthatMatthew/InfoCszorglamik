#ifndef KARAKTER_H
#define KARAKTER_H

#include "labirintus.h"
#include <stdbool.h>

// A választható irányok haladás szempontjából
typedef enum { FEL, JOBBRA, LE, BALRA } Iranyok;

// Játék során bekövetkezhető események
typedef enum { J_FAL, J_KI, J_KINCS, J_URES } Esemeny;

// Karakter
// Struktúrában tároljuk a koordinátáit.
typedef struct { int x, y; } Karakter;
// A labirintusból meghatározza a játékos koordinátáit
Karakter Holvan(Labirintus);
// Léptetést ellenörző függvény
bool MehetArra(Labirintus, Iranyok);
// Tényleges léptetés
Esemeny Leptetes(Labirintus, Iranyok);

#endif
