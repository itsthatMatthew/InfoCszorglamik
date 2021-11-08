#include <stdio.h>
#include <stdlib.h>

// Az alábbi függvény visszatér egy char mutatóval, ami a bemeneti char mutató
// tartalmának másolatára mutat, így lényegileg ezzel a függvénnyel char tömböt
// lehet másolni. A függvény memóriát foglal, így a visszatérő mutatóval a
// memória felszabadítása a hívó felelőssége.
char * masolat(char * );

// Ez a függvény sztringet fűz sztringhez, így a paramételistát két char mutató
// alkotja. Az első bementhez fűzi hozzá a másodikat, de helyigényről a függvény
// maga gondoskodik. VIGYÁZAT: az első bemenetnek dinamikusan foglalt tömbnek
// kell lennie!
char * hozzafuz(char * , char * );

// Az alábbi függvény a paraméterlistán kapott char tömbből a kezdőindextől a
// végindexig "vágja" ki a sztringet, de a végindex már a lezáró 0-t jelöli, így
// a visszatérő char tömb intervalluma lényegében balról zárt, jobbról nyitott.
// A visszatérő mutató memóriájának felszabadítása a hívó felelőssége.
char * reszsztring(char * , int , int );

// Ez a függvény a két index közötti szövegrészt vágja ki, de a végindexedik
// elem már újra a visszatérő sztring része. A foglalt memória felszabadítása a
// hívó felelőssége!
char * sztringkivag(char * , int , int );

// A függvény egy char tömb mutatójával tér vissza, mely a bemeneti char tömb
// indexedik helyére beszúrja a beszúrás char tömböt, de a bemenet vége lesz a
// visszatérési tömb vége is. A foglalt memória felszabadítása a hívó
// felelőssége.
char * beszur(char * , int , char * );

int main(void) {
	// meghívjuk a függvényt egy sztringgel
	char * str = masolat("alma");
	// kiírjuk a mutató tartalmát
	printf("%s\n", str);
	// hozzátoldás az új függvénnyel
	str = hozzafuz(str, "fa");
	printf("%s\n", str);
	// felszabadítjuk a mutatott memóriaterületet
	free(str);
	// részsztring előállítása "hello, vilag"-ból
	char * resz = reszsztring("hello, vilag", 3, 9);
	printf("%s\n", resz);
	// kivágás előállítása
	resz = sztringkivag("hello, vilag", 4, 8);
	printf("%s\n", resz);
	// beszúrás előállítása
	resz = beszur("hello!", 5, ", vilag");
	printf("%s\n", resz);
	// felszabadítjuk a mutatott memóriaterületet
	free(resz);
	// visszatérünk a programból
	return 0;
}


char * masolat(char * bemenet) {
	// számoljuk össze a foglaladnó memória méretér
	int meret = 0;
	// amíg nem lezáró karakter, növelje
	while (bemenet[meret++] != 0);
	// foglaljuk le a megfelelő méretű memóriát
	char * visszater = (char *) malloc(meret * sizeof(char));
	// másoljuk bele a bemenetet
	for (int index = 0; index < meret; index++)
		visszater[index] = bemenet[index];
	// majd zárjuk le a visszatérő sztringet
	visszater[meret] = 0;
	// és térjünk is vissza vele
	return visszater;
}

char * hozzafuz(char * to, char * toldalek) {
	// a toldalék hosszának számítása
	int toldhossz = 0;
	// amíg nem a lezáró 0, növelje
	while(toldalek[toldhossz++] != 0);
	// a tő hosszáník számítása
	int tohossz = 0;
	// amíg nem lezáró, növelje
	while(to[tohossz++] != 0);
	// a tő foglalt memóriájának megnövelése (-1 a tő lezáró 0 miatt)
	to = (char *) realloc(to, (tohossz - 1 + toldhossz) * sizeof(char));
	// a toldalék tőhöz másolása
	for (int index = tohossz - 1; index <= tohossz - 1 + toldhossz; index++)
		to[index] = toldalek[index - tohossz + 1];
	// visszatérés a mutatóval
	return to;
}

char * reszsztring(char * bemenet, int kezdindex, int vegindex) {
	// lefoglaljuk a memóriát a készülő kivágásnak
	char * kimenet = (char *) malloc((vegindex - kezdindex + 1) * sizeof(char));
	// bemásoljuk az intervallumbeli karaktereket
	for (int index = kezdindex; index < vegindex; index++)
		kimenet[index - kezdindex] = bemenet[index];
	// lezárjuk a sztringet
	kimenet[vegindex - kezdindex] = 0;
	// majd visszatérünk vele
	return kimenet;
}

char * sztringkivag(char * bemenet, int kezdindex, int vegindex) {
	// a bemeneti sztring hosszának számítása
	int meret = 0;
	while (bemenet[meret++] != 0);
	// memória foglalása
	char * kimenet = (char *) malloc((meret - vegindex + kezdindex + 1) * sizeof(char));
	// a bemenet első felének bemásolása
	for (int index = 0; index < kezdindex; index++)
		kimenet[index] = bemenet[index];
	// a bemenet második felének bemásolása
	for (int index = vegindex; index < meret; index++)
		kimenet[index - kezdindex] = bemenet[index];
	// kimenet lezárása
	kimenet[meret - kezdindex] = 0;
	// visszatérés a kimenettel
	return kimenet;
}

char * beszur(char * bemenet, int index, char * beszur) {
	// két bemeneti char tömb hosszának megállapítása
	int meret = 0, bemeret = 0;
	while (bemenet[meret++] != 0);
	while (beszur[bemeret++] != 0);
	// kimenet méretezése
	char * kimenet = (char *) malloc((meret + bemeret - 1) * sizeof(char));
	// bemenet első fele
	for (int i = 0; i < index; i++)
		kimenet[i] = bemenet[i];
	// beszurás
	for (int i = 0; i < bemeret - 1; i++)
		kimenet[index + i] = beszur[i];
	// bemenet második fele
	for (int i = index; i < meret - 1; i++)
		kimenet[bemeret - 1 + i] = bemenet[i];
	// kiement lezárása
	kimenet[meret + bemeret - 2] = 0;
	// visszatérés
	return kimenet;
}
