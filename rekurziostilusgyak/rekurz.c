#include <stdio.h>
#include <stdlib.h>

/* A függvény beolvas egy teljes sort (enterig vagy fájl vége jelig) a szabványos
 * bemenetről, és visszaadja egy dinamikusan foglalt sztringben. A sztring
 * nullával van lezárva, az entert nem tartalmazza. A hívó felelőssége
 * a free()-t meghívni a kapott pointerre. */
char* sort_beolvas(void);

// A tetszőleges saját segédfüggvényem ( mostmár :D )
char* rekurzString(int meret);

int main(void) {
	char * sor = sort_beolvas(); // Függvény meghívása

	printf("beolvasott: \"%s\"", sor); // Mutatott érték kiírása

	free(sor); // Foglalt memória felszabadítása

	return 0;
}

char* sort_beolvas(void) {
	return rekurzString(1);
}

char* rekurzString(int meret) {
	char c;
	char * ptr;
	int index = meret - 1;

	if (scanf("%c", &c) == EOF || c == '\n') {
		ptr = malloc(meret * sizeof(char)); // egyetlen egy malloc hívás
		ptr[index] = 0;
		return ptr;
	}
	else {
		ptr = rekurzString(++meret);
	}

	ptr[index] = c;

	return ptr;
}
