#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int meret;
	printf("Mekkora legyen a meret?\n");
	scanf("%d", &meret);

	double *tomb = malloc(meret * sizeof(double));

	printf("Add meg a szamokat:\n");
	for (int i = 0; i < meret; i++) {
		scanf("%lf", tomb + i);
	}

	printf("Szamok forditott sorrendben:\n");
	for (int i = meret - 1; i >= 0; i--) {
		printf("%g\n", tomb[i]);
	}

	free(tomb);

	return 0;
}
