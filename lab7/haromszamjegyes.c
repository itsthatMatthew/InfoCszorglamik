#include <stdio.h>

void SZCS(int n) {
	if (n < 1000) {
		printf("\n%d", n);
		return;
	}
	int vege = n - 1000 * (n / 1000);	// Pl.: n = 123465
	SZCS(n / 1000);				// n / 1000 = 123
	printf(" %.3d", vege);			// 1000 * ( n / 1000 ) = 123000
	return;					// n - 1000 * ( n / 1000 ) = 123456 - 123000 = 456
}

int main(void) {

	SZCS(16077216);
	SZCS(999);
	SZCS(1000);
	SZCS(12);
	SZCS(0);
	SZCS(1000222);

	return 0;
}
