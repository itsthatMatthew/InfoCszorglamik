#include <stdio.h>

int main(void) {
	int n = 1;
	int szorzat = 1;

	while(n <= 8) {
		szorzat *= n;
		n++;
	}

	printf("%d", szorzat);

	return 0;
}

// "Nyomkövetés: faktoriális új verzióban" feladat megoldása:	n=3-ra		szorzat=6720
// "Nyomkövetés: Euklidész algoritmusa" feladat megoldása:		a=347-re	b=44
