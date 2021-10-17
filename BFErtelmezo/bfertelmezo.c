#include <stdio.h>

int main(void) {
	char memoria[32768] = { 0 }, programkod[] = "+++++++[>+++++++++++<-]>.>+++++++++[>+++++++++++<-]>--.>++++++++++[>+++++++++++<-]>++++++.>++++++++++[>++++++++++<-]>+.>++++[>++++++++<-]>.>+++++++++[>++++++++++<-]>.>+++++++++[>+++++++++++<-]>--.>++++++++++[>+++++++++++<-]>--.>+++++++++[>+++++++++++<-]>--.>++++++++++[>+++++++++++<-]>.";
	int programIndex = 0, memoriaIndex = 0, ciklusagy = 0;
	while (programkod[programIndex] != 0 && memoriaIndex < 32768 && memoriaIndex >= 0) {
		ciklusagy = 1;
		switch (programkod[programIndex]) {
		case '>': memoriaIndex++; break;
		case '<': memoriaIndex--; break;
		case '+': memoria[memoriaIndex]++; break;
		case '-': memoria[memoriaIndex]--; break;
		case '.': printf("%c", memoria[memoriaIndex]); break;
		case ',': if (scanf("%c", &memoria[memoriaIndex]) == EOF) memoria[memoriaIndex]  = -1; break;
		case '[':
			if (memoria[memoriaIndex] == 0) {
				do {
					programIndex++;
					if (programkod[programIndex] == ']')
						ciklusagy--;
					else if (programkod[programIndex] == '[')
						ciklusagy++;
				} while (ciklusagy != 0 && programkod[programIndex] != 0);
			}
			break;
		case ']':
			do {
				programIndex--;
				if (programkod[programIndex] == ']')
					ciklusagy++;
				else if (programkod[programIndex] == '[')
					ciklusagy--;
			} while (ciklusagy != 0 && programIndex >= 0);
			programIndex--;
			break;
		}
		programIndex++;
	}
	return 0;
}
