# C jegyzet

Majd eskü lesz valami normális összesítés, egyelőre az S.O.S. esetekkel foglalkozik.  
Ha valamilyen igényed lenne témakör kiegészítés kapcsán, bármilyen platformon keress meg nyugodtan.

## Tartalomjegyzék:

- [Láncolt listák](#láncolt-listák)

## Előszó

Az biztos, hogy ez sem egy kétnapos projekt. A munka haladtát igyekszem minél tempósabban és nyomon követhetően végezni, de ígéretet semmire sem merek tenni.  
A folyamat haladására az alábbi nyomon követést tudom egyelőre biztosítani:  

### Tracker:

- [X] ~~Teljesen megbolondulni~~
- [ ] Láncolt listák, mint adatszerkezetek
- [ ] Beolvasás file-ból, best practices
- [ ] Minden más, amit még magamtól nem találtam ki, de igény van rá

### Megfontolandók

Sok féle kódolási stílus, elnevezési konvenció létezik, egyiket sem merném felsőbbrendűnek kijelenteni.  
Egyetlen dologra viszont még most kitérek: az olyan tagváltozókat, mint pl.: `_Data` feltétlenül kerüljétek. Ennek ez egyetlen, de remek oka pedig az, hogy a [C szabvány](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf) §7.1.3 szakasza tárgyilagosan leírja: az `_[Nagybetű]` vagy `__` kezdetű változók a fordító számára fenttartottak, tehát azokkal kénye kedve szerint bánhat. Ha pedig te ilyent teszel a programodba, az onnantól *undefined behavior*. Ez jelentheti azt is, hogy az általad tárolt értéket egyszerűen felülírja, de ezt is, hogy éppen megúszod, és ez az egész ki sem látszik.  
Ilyenkor az őszinte pro-tipp az `_` karakter a változó végére helyezése (ha feltétlen ragaszkodsz hozzá): `Data_`.  

A másik, igencsak fontos és említésre méltó elv viszont maga a "*clean code*", hogy a kód legyen beszédes, érhető és egyértelmű.  
Erre több technika és taktika is létezik, de már a szubrutinokba kiszervezések, az *evil bit hack* megoldások kerülése, és az egyértelmű elnevezések használata is elegendő a tárgy követelményei között.  

Ehhez valamennyire zárójeles megjegyzés Bjarne Stroustrup-nak, a C++ programozási nyelv kidolgozójának egyik - számomra kedvenc - szófordulata:  

> Ha létezik olyan előadási stílus, amit nem szeretek, az a következő:  
> "Látod ezt a kódot? Ez nagyon bonyolult! Te nem érted! De én értem! Szóval okosabb vagyok nálad!"  

Szumma szummárum, ez levezethető magára a kódírásra is: nem az a cél, hogy minél menőbb, egy soros függvényeket tudjunk írni, pláne, ha a fordító amúgy is elvégzi az optimalizálást helyettünk.

A továbbiakban pedig kellemes és sikerekben gazdag olvasást kívánok.

# Láncolt listák

A láncolt listák, mint adattárolási szerkezetek, azt az egyszerű problémát hivatottak megoldani, hogy tetszőlegesen nagy mennyiségű adatot tárolhassunk le úgy, hogy maguk az elemek nincsenek hatással egymásra. Erre potenciális jelölt lehetne egy dinamikus tömb is, de a hibájuk egyértelmű: ha a méretének limitjét eléri, és újra kell foglalni a memóriát, ezen a meglehetősen lassú műveleten túl még minden adatot is át kell másolnunk.  

És az ördög itt rejlik: dinamikus tömbben szinte minden eseményre (új elem felvétele, törlése, stb.) legalább az adatokat (ha nem is az összeset) át kell másolnunk memórián belül. Ezzel szemben egy láncolt listában, ha egy adat megváltozik, törlődik vagy egyszerűen csak újat veszünk fel, pár pointert átállítunk, és meg is oldottuk a problémát.  

Természetesen a szép mesén túl a gyakorlati megvalósítás már bőven tartogat buktatókat, így nézzünk is erre egy felépített példát!

## Adaszerkezet(ek) kialakítása

:skull:

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

```c
typedef struct AdatSzerk
{
  // adatok, pl.:
  char karakter;
  int egesz;
  float lebego_pontos;
  char sztring[20 + 1]; // itt tetszőlegesen választhattunk volna char* -ot is,
                        // de akkor a sztring memóriakezelése is a mi felelősségünk!
} AdatSzerk;
```

```c
typedef ListaElem
{
  AdatSzerk  adat; // maga az adatszerkezet, amit tárolni akarunk a lista elemekben
  ListaElem* kovi; // a következő lista elemre mutató pointer
} ListaElem;
```

### Láncolt listába beolvasás: az OG halálfejes hiba :skull_and_crossbones:

```c
void adatBeolvas(ListaElem* eleje) {
  // beolvasást végző kód
}

int main()
{
  ListaElem* fej;   // a lista fejére mutató pointer - tehát ő maga nem lista elem,
                    // hanem csak az első elemre mutat!
  adatBeolvas(fej); // a tipikus buktató: ez nem fogja magát a fej változót felülírni,
                    // így az elvégzett művelet értelmetlen! (+ még memóriát is szivárogtat)
}
```

## Segédfüggvények definiálása

## Örökéletű buktató: első adat beolvasása
