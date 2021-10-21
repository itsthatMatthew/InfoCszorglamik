#include <stdio.h>

void sztringet_kiir_1(char *szoveg) {
    if (szoveg[0] == '\0')
        return;
    putchar(szoveg[0]);
    printf("%s", szoveg + 1);     /* Ha nem lezáró karakter az első betű, kiírja azt, majd a sztring többi részét */
}


void sztringet_kiir_2(char *szoveg) {
    if (szoveg[0] == '\0')
        return;
    putchar(szoveg[0]);
    sztringet_kiir_2(szoveg + 1); /* Ha nem lezáró karakter az első betű, kiírja azt, majd megteszi ugyanezt az eljárást a következő betűvel kezdve. */
}


int main(void) {
    sztringet_kiir_1("alma");
    sztringet_kiir_2("alma");

    return 0;
}
