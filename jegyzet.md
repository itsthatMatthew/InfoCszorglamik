# C jegyzet

Majd eskü lesz valami normális összesítés, egyelőre az S.O.S. esetekkel foglalkozik.  
Ha valamilyen igényed lenne témakör kiegészítés kapcsán, bármilyen platformon keress meg nyugodtan.

### Előszó

Az biztos, hogy ez sem egy kétnapos projekt. A munka haladtát igyekszem minél tempósabban és nyomonkövethetően végezni, de ígéretet semmire sem merek tenni.  
A folyamat haladására az alábbi nyomonkövetést tudom egyelőre biztosítani:  

#### Tracker:

- [X] ~~Teljesen megbolondulni~~
- [ ] Láncolt listák, mint adatszerkezetek
- [ ] Beolvasás file-ból, best practices
- [ ] Minden más, amit még magamtól nem találtam ki, de igény van rá

Sok féle kódolási stílus, elnevezési konvenció létezik, egyiket sem merném felsőbbrendűnek kijelenteni.  
Egyetlen dologra viszont még most kitérek: az olyan tagváltozókat, mint pl.: `_Data` feltétlenül kerüljétek. Ennek ez egyetlen, de remek oka pedig az, hogy a [C szabvány](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf) §7.1.3 szakasza tárgyilagosan leírja: az `_[Nagybetű]` vagy `__` kezdetű változók a fordító számára fenttartottak, tehát azokkal kénye kedve szerint bánhat. Ha pedig te ilyent teszel a programodba, az onnantól *undefined behavior*.  
Ez jelentheti azt is, hogy az általad tárolt értéket egyszerűen felülírja, de ezt is, hogy éppen megúszod, és ez az egész ki sem látszik.  
Ilyenkor az őszinte pro-tipp az `_` karakter a változó végére helyezése (ha feltétlen ragaszkodsz hozzá): `Data_`.  

A másik, igencsak fontos és említésre méltó elv viszont maga a "*clean code*", hogy a kód legyen beszédes, érhető és egyértelmű.  
Erre több technika és taktika is létezik, de már a szubrutinokba kiszervezések, az *evil bit hack* megoldások kerülése, és az egyértelmű elnevezések használata is elegendő a tárgy követelményei között.  

Ehhez valamennyire zárójeles megjegyzés Bjarne Stroustrup-nak, a C++ programozási nyelv kidolgozójának egyik - számomra kedvenc - szófordulata:  
Nem attól jó programozó valaki, hogy komplex kódot tud írni.  
> Látod ezt a kódot? Ez bonyolult! Én értem! Én okos vagyok!  
> Te nem érted! Én okosabb vagyok nálad!

#### Tartalomjegyzék:

- [Láncolt listák](#láncolt-listák)

A továbbiakban pedig kellemes és sikerekben gazdag olvasást kívánok.

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
