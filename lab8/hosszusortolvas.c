#include <stdio.h>
#include <stdlib.h>

// A függvény allokált memóriacímmel tér vissza,
// ennek felszabadítása a felhasználó felelőssége!
char * hosszu_sort_olvas(void) {
	int meret = 0;
	char * sor = malloc(sizeof(char));
	*sor = 0; // Legelső karakter '\0'

	while(scanf("%c", sor + meret) != EOF){
		if (sor[meret] == '\n')
			break;
		realloc(sor, (++meret + 1) * sizeof(char));
	}

	realloc(sor, meret * sizeof(char));
	sor[meret] = 0;

	return sor;
}

int main(void) {
	char * szoveg;

	szoveg = hosszu_sort_olvas();

	printf("%s", szoveg);

	free(szoveg);

	return 0;
}
