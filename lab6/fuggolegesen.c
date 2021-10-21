#include <stdio.h>

int main(void) {
	char nev[600];	/* mivel nem tudjuk mi lesz a név, kellően nagy tömböt inicializálunk neki,
	* ennyi karakterbe feltehetőleg minden (latin karakterekkel leírható) név belefér.
	* (A jegyzett leghoszabb név összesen 747, ennek leghoszabb része 598 karakteres, forrás:
	* https://www.guinnessworldrecords.com/world-records/67285-longest-personal-name
	* Természetesen ekkora tömb alap esetben teljes értelmetlenség lenne, de valós példa
	* mutatja, hogy jelen esetben ez igen is gyakorlatias megoldás. */

	scanf("%s", &nev);	// csak egy nevet enged (semmi utónév stb.), mert szóköznél is lezár

	int i = 0;
	while (nev[i] != 0) {
		printf("%c\n", nev[i++]);
	}

	return 0;
}
