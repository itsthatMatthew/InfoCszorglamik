#include <stdio.h>

/* Bár ez alapvetően rossz programozói szokás, fontos megjegyeznünk, hogy melyik tömböt mire
* használjuk fel: míg a forrástömbnek a tömb tulajdonságán van a hangsúly, azaz hogy char
* sorozatból sztringként szerepel, amit bejárunk, addig a céltömbnek a mutató tulajdonságát
* használjuk ki, hogy abba mellékhatásként karaktereket mentsünk vissza. */
void trim(char forras[], char * cel) {
	int kezdIndex = 0, vegzIndex;

	/* Kényelmes lenne az inkrementálást/dekrementálást mindig a ciklusfejben elvégezni
	* Úgy mint:
	*	while (forras[kezdIndex++] == ' ');
	* De ebben az esetben sokszor "túllőnénk" az indexet, hiszen az inkrementálás/dekrementálás
	* midnig lefutna, akkor is, ha a kifejezés már hamis lenne, így ez csak több korrigálást
	* igényelne, mint amennyi stilisztikai hasznot hozna. */

	// fussunk az elejéről ameddig nem szóköz
	while (forras[kezdIndex] == ' ') { kezdIndex++; }	// innen tudjuk, hogy meddig tartanak az elején szóközök
	vegzIndex = kezdIndex;

	/* EZ az a rész, ami miatt nem kell, hogy tudjuk a tömb méretét: */
	// most járjuk be teljesen, azaz a legvégéig:
	while (forras[vegzIndex] != 0) { vegzIndex++; }	// innen megkapjuk a tömb méretét
	vegzIndex--;	// eggyel túllövünk rajta, hiszen a lezáró karakteren állunk meg

	// járjuk be a tömböt most visszafelé
	while (forras[vegzIndex] == ' ') { vegzIndex--; }	// innen megkapjuk a mögötti első szóköz indexét

	// átmásoljuk karakterenként a kezdeti szóközök végétől a végsők elejéig
	for (int i = 0; i <= vegzIndex - kezdIndex; i++)
		cel[i] = forras[kezdIndex + i];
	cel[vegzIndex - kezdIndex + 1] = 0;
}

int main(void) {
	char tomb[] = "  hello, mizu?   ";	// char tömb inicializálásánál a méret automatikus

	char celtomb[50];	// céltömbnek viszont már nekünk kell deklarálásnál méretet adni

	trim(tomb, celtomb);

	printf("eredeti:  |%s|\ntrimmelt: |%s|", tomb, celtomb);

	return 0;
}
