# Ebben a jegyzékben azok a buktatók és tanulságok, tapasztalatok lesznek felsorolva, amiket a projektek során szereztem.

Fontos megemlíteni, hogy:
  1. én Atom-mal és MinGW-vel dolgozom, így a projektek csak a forrásfájlból és a hozzájuk szükséges környezeti kiegészítőkből (képek, ttf-ek, _kiszervezett_ szubrutinok fejlécfájljai (_igen, ez egy nyelvtanilag helyes szó_), _stb._) állnak;
  2. komolyabb fordításhoz Makefile-t használok, ebben több változó (pl.: elérési útvonalak) a saját könyvtárkiépítésemnek megfelelően van beállítva, így nem fog mindenkinek azonosan működni;
  3. bizonyos eljárásokban (akár függvények tekintetében, akár használt forrásokban) "_saját módszer_" szerint járok el, így a tantárgyi követelménnyel nem garantált a 100%-os egyezés.

További megjegyzés: az egész jegyzék WIP, így érdemes lesz a későbbiekben még visszanézni.

## Buktatók és Tanulságok
  - Commentelni igen is érdemes. Időigényes és néha nyögvenyelős, de megfelelő leírást adni mindennek, aminek csak lehet, nagyban megtérül a későbbiekben. Vicceskedni lehet, de nem érdemes teljesen elpoénkodni, mert azzal semmivel sem vagyunk előrébb.
  - Elérési útvonalak megadásánál érdemes megválasztani, hogy abszolút vagy relatív módon érjük el a fájlokat. Minkettő lehet épkézláb megoldás, csak tartsuk észben a velejárókat.
  - Ha az ember segédkönyvtárakat használ, érdemes szem előtt tartani, hogy a fordító maga 32 vagy 64 bites (jellemzően az előző). Ennek megfelelően, míg egy 64 bites fordító fel is tudná dolgozni a 32 bites könyvtárat, fordítva már semmiképpen se fog menni. Nem érdmes kísérteni a sorsot, így inkább a fordítónak megfelelőt használjhuk.
