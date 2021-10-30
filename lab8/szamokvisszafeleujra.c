#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int meret = 1;
	int futhat = 1;
	double *tomb = malloc(sizeof(double));

	printf("Add meg a szamokat:\n");
	while (futhat) {
		scanf("%lf", tomb + meret - 1);
		if (tomb[meret - 1] == -1) {
			tomb = realloc(tomb, (--meret) * sizeof(double));
			futhat ^= 1;
		}
		else
			tomb = realloc(tomb, (++meret) * sizeof(double));
	}

	printf("Szamok forditott sorrendben:\n");
	for (int i = meret - 1; i >= 0; i--) {
		printf("%g\n", tomb[i]);
	}

	free(tomb);

	return 0;
}
