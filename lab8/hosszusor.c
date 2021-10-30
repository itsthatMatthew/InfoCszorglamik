#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int meret = 0;
	char * sor = malloc(sizeof(char));
	*sor = 0; // Legelső karakter '\0'

	while(scanf("%c", sor + meret) != EOF){
		if (sor[meret] == '\n')
			break;	// erre nicns jobb ötletem. hogy cask sorvégig olvasson
		realloc(sor, (++meret + 1) * sizeof(char));
	}

	realloc(sor, meret * sizeof(char));
	sor[meret] = 0;

	printf("%s", sor);

	free(sor);

	return 0;
}
