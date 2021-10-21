#include <stdio.h>

int fib(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}

int DebugFib(int n) {
	printf("%d. sorozatelem szamitasa...\n", n);
	int temp = 0;
	if (n == 0) {
		printf("%d. szamitasbol visszateres\t0\tertekkel\n", n);
		return 0;
	} else if (n == 1) {
		printf("%d. szamitasbol visszateres\t1\tertekkel\n", n);
		return 1;
	} else {
		temp = DebugFib(n - 1) + DebugFib(n - 2);
		printf("%d. szamitasbol visszateres\t%d\tertekkel\n", n, temp);
		return temp;
	}
}

int main(void) {

	printf("n = 40\tfib(40) = %d\n", fib(40));

	DebugFib(5);

	return 0;
}
