# C jegyzet

Majd eskü lesz valami normális összesítés, egyelőre az S.O.S. esetekkel foglalkozik.  
Ha valamilyen igényed lenne témakör kiegészítés kapcsán, bármilyen platformon keress meg nyugodtan.

### Előszó

Az biztos, hogy ez sem egy kétnapos projekt. A munka haladtát igyekszem minél tempósabban és nyomonkövethetően végezni, de ígéretet semmire sem merek tenni.  
A folyamat haladására az alábbi nyomonkövetést tudom egyelőre biztosítani:  

- [X] ~~Teljesen megbolondulni~~
- [ ] Láncolt listák, mint adatszerkezetek
- [ ] Beolvasás file-ból, best practices
- [ ] Minden más, amit még magamtól nem találtam ki, de igény van rá

Sok féle kódolási stílus, elnevezési konvenció létezik, egyiket sem merném felsőbbrendűnek kijelenteni.  
Egyetlen dologra viszont még most kitérek: az olyan tagváltozókat, mint pl.: `_Data` feltétlenül kerüljétek.  
Ennek ez egyetlen, de remek oka pedig az, hogy a [C szabvány](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf) §7.1.3 szakasza tárgyilagosan leírja: az `_[Nagybetű]` vagy `__` kezdetű változók a fordító számára fenttartottak, tehát azokkal kénye kedve szerint bánhat. Ha pedig te ilyent teszel a programodba, az onnantól *undefined behavior*.  
Ez jelentheti azt is, hogy az általad tárolt értéket egyszerűen felülírja, de ezt is, hogy éppen megúszod, és ez az egész ki sem látszik.  
Ilyenkor az őszinte pro-tipp az `_` karakter a változó végére helyezése (ha feltétlen ragaszkodsz hozzá): `Data_`.

## Láncolt listák

:skull:

### Adaszerkezet(ek) kialakítása

```c
typedef struct AdatSzerk
{
  /* adatok, pl.: */
  char adat;
} AdatSzerk;

typedef ListaElem
{
  AdatSzerk  adat;
  ListaElem* kovi;
} ListaElem;

void adatBeolvas(ListaElem* eleje) {
  /* kód */
}

int main()
{
  ListaElem* fej;
  adatBeolvas(fej);
}
```

Kis vizualizáció:

```
                       ListaElem             ListaElem             ListaElem
                ┌─►┌───────────────┐  ┌─►┌───────────────┐  ┌─►┌───────────────┐
                │  │               │  │  │               │  │  │               │
                │  │AdatSzerk  adat│  │  │AdatSzerk  adat│  │  │AdatSzerk  adat│
ListaElem* fej──┘  │               │  │  │               │  │  │               │  ┌─►NULL
                   ├───────────────┤  │  ├───────────────┤  │  ├───────────────┤  │
                   │ListaElem* kovi├──┘  │ListaElem* kovi├──┘  │ListaElem* kovi├──┘
                   └───────────────┘     └───────────────┘     └───────────────┘
```

### Segédfüggvények definiálása

### Örökéletű buktató: első adat beolvasása
