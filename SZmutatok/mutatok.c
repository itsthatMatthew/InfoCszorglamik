#include <stdio.h>  // bemeneti-kimeneti kommunikációhoz
#include <math.h>   // matematikai függvények (pl.: sin/cos) hívásához

#ifdef _WIN32
#include <windows.h>  // windowson történő helyes bemeneti és kimeneti kódlap beállításokhoz
#endif

int main() {
#ifdef _WIN32
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
#endif

    // BEMENETI RÉSZ


    double ora, perc, masodperc; // bár a bekért értékek egész számok lesznek, a mutatók kitérése
                                 // indokolja az előre készülést

    printf("Kérlek, add meg az órát, percet és másdopercet (szóközökkel elválasztva)\n");
    scanf("%lf %lf %lf", &ora, &perc, &masodperc);

    /* Mivel szeretnénk, hogy a mutatók "valósághűek" legyenek, tehát másodpercnek/percnek megfelelően
     * egy keveset elmozduljanak a pontos percre/órára történő mutatásból, ezt ki kell számolnunk, hogy
     * "valójában" mennyi az idő, azaz a mutatók egész percen/órán mennyivel mutatnak túl */

    perc += masodperc / 60;  // perc "elállítása"
    ora += perc / 60;        // óra  "elállítása"


    // KIMENETI RÉSZ


    // A kimeneti fájl vertikális és horizontális mérete pixelekben (szélessége és magassága)
    int kimenetiMeret = 1024;
    // Mivel sok elem fog a középpontra hivatkozni, azt a kimeneti méret alapján definiálhatjuk is
    int kp = kimenetiMeret / 2;

    char oraKorvonal[8] = "#FF0000",  // hex-kód
         oraKitolto[8]  = "#FFFFFF";  // hex-kód
    int vonalSzelesseg  = 48;         // pixelben

    // Kimeneti fájl megnyitása:
    FILE* kimenet;
    kimenet = fopen("ora.svg", "w");
    // Sikeresség ellenőrzése
    if (kimenet != NULL) {
        // SVG fájl fejléce:
        fprintf(kimenet, "<?xml version=\"1.0\" standalone=\"no\"?>\n"
            "<svg width=\"%d\" height=\"%d\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n",
                                                                        kimenetiMeret, kimenetiMeret);

        // Óra "hátlapja" (erre fogunk sok mindent felrajzolni):
        fprintf(kimenet, "\t<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"%s\"/>\n",
                                       kp, kp, kp - vonalSzelesseg, oraKitolto);

        // Beosztások (PI értékét acos(-1) számolja ki nekünk):
        for (int i = 0; i < 60; i++)
            switch (i)
            {
            case 0  * 5: // "óra" * 5 perc (a fordítóprogram úgyis egyből értéket számol neki)
            case 3  * 5:
            case 6  * 5:
            case 9  * 5:
                fprintf(kimenet, "\t<line x1=\"%d\" x2=\"%lf\" y1=\"%d\" y2=\"%lf\" stroke=\"black\" stroke-width=\"%d\"/>\n",
                kp, kp * (1 + sin(i * acos(-1) / 30) * (kp - vonalSzelesseg) / kp), kp, kp * (1 - cos(i * acos(-1) / 30) * (kp - vonalSzelesseg) / kp), vonalSzelesseg / 3 * 2);
                break;
            case 1  * 5:
            case 2  * 5:
            case 4  * 5:
            case 5  * 5:
            case 7  * 5:
            case 8  * 5:
            case 10 * 5:
            case 11 * 5:
                fprintf(kimenet, "\t<line x1=\"%d\" x2=\"%lf\" y1=\"%d\" y2=\"%lf\" stroke=\"black\" stroke-width=\"%d\"/>\n",
                kp, kp * (1 + sin(i * acos(-1) / 30) * (kp - vonalSzelesseg) / kp), kp, kp * (1 - cos(i * acos(-1) / 30) * (kp - vonalSzelesseg) / kp), vonalSzelesseg / 3);
                break;
            default:
                fprintf(kimenet, "\t<line x1=\"%d\" x2=\"%lf\" y1=\"%d\" y2=\"%lf\" stroke=\"black\" stroke-width=\"%d\"/>\n",
                kp, kp * (1 + sin(i * acos(-1) / 30) * (kp - vonalSzelesseg) / kp), kp, kp * (1 - cos(i * acos(-1) / 30) * (kp - vonalSzelesseg) / kp), vonalSzelesseg / 8);
                break;
            }

        // Beosztások belsejét "elfedjük" (ott, ahol majd a mutatók lesznek):
        fprintf(kimenet, "\t<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"%s\"/>",
                       kp, kp, (kp - vonalSzelesseg) * (kp - vonalSzelesseg) / kp, oraKitolto);

        // Óratest kirajzolása:
        fprintf(kimenet, "\t<circle cx=\"%d\" cy=\"%d\" r=\"%d\" stroke=\"%s\" fill=\"transparent\" stroke-width=\"%d\"/>\n",
                                                               kp, kp, kp - vonalSzelesseg, oraKorvonal, vonalSzelesseg);

        // Mutatók kirajzolása:
          // másodpercmutató
        fprintf(kimenet, "\t<line x1=\"%d\" x2=\"%lf\" y1=\"%d\" y2=\"%lf\" stroke=\"black\" stroke-width=\"%d\"/>\n",
        kp, kp * (1 + sin(masodperc * acos(-1) / 30) * 0.8), kp, kp * (1 - cos(masodperc * acos(-1) / 30) * 0.8), vonalSzelesseg / 4);

          // kismutató (perc)
        fprintf(kimenet, "\t<line x1=\"%d\" x2=\"%lf\" y1=\"%d\" y2=\"%lf\" stroke=\"black\" stroke-width=\"%d\"/>\n",
        kp, kp * (1 + sin(perc * acos(-1) / 30) * 0.7), kp, kp * (1 - cos(perc * acos(-1) / 30) * 0.7), vonalSzelesseg / 3);

          // nagymutató (óra)
        fprintf(kimenet, "\t<line x1=\"%d\" x2=\"%lf\" y1=\"%d\" y2=\"%lf\" stroke=\"black\" stroke-width=\"%d\"/>\n",
        kp, kp * (1 + sin(ora * acos(-1) / 6) * 0.6), kp, kp * (1 - cos(ora * acos(-1) / 6) * 0.6), vonalSzelesseg / 2);

        // Egy utolsó design-elem, egy, a nagymutató szélténél egy kicsit nagyobb keresztmetcetű kör, hogy a középponti illesztéseket lefedje
        fprintf(kimenet, "\t<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"black\"/>\n",
                                                     kp, kp, vonalSzelesseg / 2);

        // Kimeneti fájl lezárása:
        fprintf(kimenet, "</svg>");
        fclose(kimenet);
        printf("Az \"ora.svg\" fájl sikeresen létrehozva.\nNyomj egy Entert a programból való kilépéshez.");
        getchar();  // Egy utolsó bemenetet megvárunk a felhasználótól
    }
    else
        perror("Az \"ora.svg\" fájl létrehozása sikertelen volt.");
        
    return 0;
}
