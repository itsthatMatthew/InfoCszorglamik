# C jegyzet

Majd eskü lesz valami normális összesítés, egyelőre az S.O.S. esetekkel foglalkozik.  
Ha valamilyen igényed lenne témakör kiegészítés kapcsán, bármilyen platformon keress meg nyugodtan.

## Tartalomjegyzék:

- [Megfontolandók](#megfontolandók)
- [Láncolt listák](#láncolt-listák)

## Előszó

A jegyzet fő célja az, hogy a tipikus hibákat, buktatókat kiemelve a gyakori kérdésekre válaszoljon. Prog1-ből irgalmatlan tempót kell diktálni, főleg a félév vége felé, pláne, ha az ember itt programoz életében először. Ideális esetben azok, akik egy adott témában el vannak veszve, ebben a doksiban megtalálhatják kérdéseikre a választ, egyszerűen és érthetően elmagyarázva, segítve adott intuíciók kialakítását.

Az biztos, hogy ez sem egy kétnapos projekt. A munka haladtát igyekszem minél tempósabban és nyomon követhetően végezni, de ígéretet semmire sem merek tenni.  
A folyamat haladására az alábbi nyomon követést tudom egyelőre biztosítani:  

### Tracker:

- [X] ~~Teljesen megbolondulni~~
- [ ] Láncolt listák, mint adatszerkezetek
- [ ] Pointerek, úgy általánosságban
- [ ] Függvények, átadás referencia szerint*
- [ ] Sztringek kezelése
- [ ] Beolvasás file-ból, best practices
- [ ] Minden más, amit még magamtól nem találtam ki, de igény van rá

A továbbiakban pedig kellemes és sikerekben gazdag olvasást kívánok.  

# Megfontolandók

Az alábbi szakasz az általam felfedezni vélt olyan tipikus hibákat tartalmazza, amik nem foglalhatóak bele egyik anyagrész tartalmába sem.

Sok féle kódolási stílus, elnevezési konvenció létezik, egyiket sem merném felsőbbrendűnek kijelenteni.  

Egyetlen dologra viszont még most kitérek: az olyan tagváltozókat, mint pl.: `_Data` feltétlenül kerüljétek. Ennek ez egyetlen, de remek oka pedig az, hogy a [C szabvány](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf) §7.1.3 szakasza tárgyilagosan leírja: az `_[Nagybetű]` vagy `__` kezdetű változók a fordító számára fenttartottak, tehát azokkal kénye kedve szerint bánhat. Ha pedig te ilyent teszel a programodba, az onnantól *undefined behavior*. Ez jelentheti azt is, hogy az általad tárolt értéket egyszerűen felülírja, de ezt is, hogy éppen megúszod, és ez az egész ki sem látszik.  
Ilyenkor az őszinte pro-tipp az `_` karakter a változó végére helyezése (ha feltétlen ragaszkodsz hozzá): `Data_`.  

A másik, igencsak fontos és említésre méltó elv viszont maga a "*clean code*", hogy a kód legyen beszédes, érhető és egyértelmű. Erre több technika és taktika is létezik, de már a szubrutinokba kiszervezések, az *evil bit hack* megoldások kerülése, és az egyértelmű elnevezések használata is elegendő a tárgy követelményei között.  

Ehhez valamennyire zárójeles megjegyzés Bjarne Stroustrup-nak, a C++ programozási nyelv kidolgozójának egyik - számomra kedvenc - szófordulata:  

> Ha létezik olyan előadási stílus, amit nem szeretek, az a következő:  
> "Látod ezt a kódot? Ez nagyon bonyolult! Te nem érted! De én értem! Szóval okosabb vagyok nálad!"  

Szumma szummárum, ez levezethető magára a kódírásra is: nem az a cél, hogy minél menőbb, egy soros függvényeket tudjunk írni, pláne, ha a fordító amúgy is elvégzi az optimalizálást helyettünk.

# Láncolt listák

A láncolt listák, mint adattárolási szerkezetek, azt az egyszerű problémát hivatottak megoldani, hogy tetszőlegesen nagy mennyiségű adatot tárolhassunk le úgy, hogy maguk az elemek nincsenek hatással egymásra. Erre potenciális jelölt lehetne egy dinamikus tömb is, de a hibájuk egyértelmű: ha a méretének limitjét eléri, és újra kell foglalni a memóriát, ezen a meglehetősen lassú műveleten túl még minden adatot is át kell másolnunk.  

És az ördög itt rejlik: dinamikus tömbben szinte minden eseményre (új elem felvétele, törlése, stb.) legalább az adatokat (ha nem is az összeset) át kell másolnunk memórián belül. Ezzel szemben egy láncolt listában, ha egy adat megváltozik, törlődik vagy egyszerűen csak újat veszünk fel, pár pointert átállítunk, és meg is oldottuk a problémát.  

Természetesen a szép mesén túl a gyakorlati megvalósítás már bőven tartogat buktatókat, így nézzünk is erre egy felépített példát!

## Adaszerkezet(ek) kialakítása

Az ötlet egyszerű, és szerkezetileg valóban kevés kóddal leírható. A listát lista elemekből állítjuk össze, így ezek lesznek a fő szervezési egységek. Ezek a lista elemek magukban tartalmaznak egy tetszőleges adatot, valamint egy pointerrel mutatnak a soron következő lista elemre. A listában utolsó elem pedig egy `NULL` értékre mutat, ez sokmindenben a segítségünkre lesz.

#### Kis vizualizáció:

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

Ez alapján egy lista elemünknek csak ebből a két adattagból kell álnia. (Persze bizonyos lista típusoknál opcionálisan egynél több mutatót, esetleg több adat eltárolása esetén plusz adatszerkezeteket tartalmazhatnak.)  

Maga a fej (vagy gyökér, head, ami tetszik) lesz az a változó, ami az első listaelemre mutat. Ez fontos, hiszen így a fej maga nem egy listaelem, ez az igen jelentős különbség a [listába való beszúrásnál](#láncolt-listába-beolvasás-az-og-halálfejes-hiba-skull_and_crossbones) még előjön!

Definiáljunk egy tetszőleges adatszerkezetet, amit a listával tudunk kezelni: tartalmazzon egy karaktert, egy egész számot, egy lebegőpontos számot, valamint egy sztringet! Ez utóbbit karakter tömbként definiáljuk `char*` helyett. Ha tetszőlegesen hosszú karaktersorozatot akarnánk letárolni, ahhoz a sztring memóriakezelését is nekünk kéne végeznünk. Ezzel viszont egyszerűen kiválthatjuk ezt a problémát.

#### A példa adatszerkezet:

```c
typedef struct AdatSzerk
{
  // adatok, pl.:
  char karakter;
  int egesz;
  float lebegopontos;
  char sztring[20 + 1]; // itt tetszőlegesen választhattunk volna char* -ot is,
                        // de akkor a sztring memóriakezelése is a mi felelősségünk!
} AdatSzerk;
```

Mindezek tudatában a lista elemeinek ezt az adatszerkezetet kell tartalmazniuk, továbbá a már említett következő elemre mutató pointert.

#### A lista elemeinek szerkezete:

```c
typedef ListaElem
{
  AdatSzerk  adat; // maga az adatszerkezet, amit tárolni akarunk a lista elemekben
  ListaElem* kovi; // a következő lista elemre mutató pointer
} ListaElem;
```

Sokaknál látom, hogy az adatot magát is pointerrel gondolják letárolni. Ugyan ez esetenként indokolt és célszerű is lehet (pl.: fésűs listák), a +1 rétegnyi indirekció memóriakezelése újfent a mi feladatunká válik. Ezért erősen azt ajánlom, hogy amíg lehet, csak szimplán mint adattag vegyük fel a lista eleméhez, mert nagyban megkönnyíti a munkánkat, felesleges komplexitás nélkül.

Ha mindezekkel megvagyunk, a lista szerkezeti része elkészült, de a neheze még hátra van: a listában természetesen adatokat szeretnénk tárolni, új elemeket felvenni bele, ehhez pedig szükségszerű függvényeket, a listához tartozó segédfüggvényeket kialakítanunk. A továbbiakban erre nézünk példákat.

## Segédfüggvények definiálása

## Láncolt listába beolvasás: az OG halálfejes hiba :skull_and_crossbones:

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

## Egyéb lista típusok
