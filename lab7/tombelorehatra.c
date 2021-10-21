#include <stdio.h>

void AX(int *tomb, int meret) {
	printf("ax) iterativ elore %d meretre\n", meret);
	for (int i = 0; i < meret; i++) {
		printf("%d\n", tomb[i]);
	}
}

void AY(int *tomb, int meret) {
	printf("ay) iterativ hatra %d meretre\n", meret);
	for (int i = meret - 1; i != 0; i--) {
		printf("%d\n", tomb[i]);
	}
}

void BX(int *tomb, int meret, int kiir) {
	if (kiir == 0)
		printf("bx) rekurziv elore %d meretre\n", meret);
	if (kiir != meret) {
		printf("%d\n", tomb[kiir]);
		kiir++;
		BX(tomb, meret, kiir);
	}
	return;
}

void BY(int *tomb, int meret, int kiir) {
	if (kiir == meret - 1)
		printf("by) rekurziv hatra %d meretre\n", meret);
	if (kiir >= 0) {
		printf("%d\n", tomb[kiir]);
		kiir--;
		BY(tomb, meret, kiir);
	}
	return;
}

int main(void) {
	int ottomb[5] = {0, 1, 2, 3, 4}, tiztomb[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	AX(ottomb, 5);
	AY(ottomb, 5);
	BX(ottomb, 5, 0);
	BY(ottomb, 5, 4);

	AX(tiztomb, 10);
	AY(tiztomb, 10);
	BX(tiztomb, 10, 0);
	BY(tiztomb, 10, 9);

	return 0;
}
