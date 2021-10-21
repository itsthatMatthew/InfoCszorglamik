#include <stdio.h>
#include <math.h>

double kob(double n) {
	return n * n * n;
}

double abszolut(double n) {
	return n < 0 ? -n : n;
}

int main(void) {
	printf("    a\t\t   a^3\t\t   |a|\t\t sin(a)\n");
	for (double i = -1; i <= 1; i+=0.1)
		printf("%7.4lf\t\t%7.4lf\t\t%7.4lf\t\t%7.4lf\n", i, kob(i), abszolut(i), sin(i));

	return 0;
}
