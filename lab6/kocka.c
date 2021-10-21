#include <stdio.h>

void FT(double a, double * f, double * t) {
	*f = 6 * a * a;
	*t = a * a * a;
}
 int main(void) {

	double oldal = 2.7, felulet, terfogat;

	FT(oldal, &felulet, &terfogat);

	printf("oldahossz = %g; felulet = %g; terfogat = %g", oldal, felulet, terfogat); 

 	return 0;
 }
