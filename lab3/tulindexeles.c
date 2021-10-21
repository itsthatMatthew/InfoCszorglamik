#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int tomb[10];

    for (int i = 0; i < 10; i += 1)
        tomb[i] = i * 10;

    int i = 0;
    while (true) {
        printf("%d. elem: %d\n", i, tomb[i]);
        i += 1;
    }

    return 0;
}

// while(true) következménye egészen egyszerűen az lesz, hogy a ciklus "örökké" fog futni.
// Azonban ez IED-ben nagyon gyorsan hibakódot fog dobni, hiszen ezzel olyan memóriaterületről
// olvasnánk, amihez nincs hozzáfárési jogosultságunk (ez a magyarázat a túlindexeléskor kapott
// értelmetlen értékekre is: olyan memóriaterületről olvasunk, ahova mi nem raktunk semmit, tehát
// az esetlegesen korábban -más programokból- ott maradt értékeket írja ki a program).
