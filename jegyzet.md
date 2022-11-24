# C jegyzet

Majd eskü lesz valami normális összesítés, egyelőre az S.O.S. esetekkel foglalkozik.  
Ha valamilyen igényed lenne témakör kiegészítés kapcsán, bármilyen platformon keress meg nyugodtan.

## Láncolt listák

:skull:

```c
typedef struct AdatSzerk {
  /* adatok */
} AdatSzerk;

typedef ListaElem {
  AdatSzerk  adat;
  ListaElem* kovi;
} ListaElem;
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
