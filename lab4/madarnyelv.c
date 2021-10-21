// A feladatvegi problemanak megoldasahoz hasznalt megjegyzesek jelolve vannak: (*)
#include <stdio.h>
#include <ctype.h>	// (*) letezo fejlecfajl importalasa a legyegyszerubb megoldas
#include <stdbool.h>

bool Maganhangzo(char c) {
	switch (c) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return true;
			break;
		default:
			return false;
			break;
	}
}

int main(void) {
	char c;
    while (scanf("%c", &c) != EOF) {
        if (Maganhangzo(tolower(c)))	// (*) szubrutinnak atadaskor kisbetusitjuk
            printf("%cv%c", c, tolower(c));	// (*) ha nagybetu, legyen kicsi, ha kicsi, ugyis marad
        else
            printf("%c", c);
    }
	return 0;
}
