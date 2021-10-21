#include <stdio.h>

void SZRV(int n, int szr) {
	if (n < szr) {
		printf("%d", n);
		return;
	}
	int vege = n % szr;
	SZRV(n / szr, szr);
	printf("%d", vege);
	return;
}

int main(void) {

	SZRV(123, 8);

	return 0;
}
