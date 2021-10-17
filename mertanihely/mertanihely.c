#include <math.h>		// fabs() - a (compiler) beépített abs() fv-nek int a visszatérési értéke, de mi float (double) értékekkel dolgozunk
#include <stdbool.h>	// boolean érték használatához
#include <SDL.h>		// az SDl fejlécfájl maga
#include <SDL_ttf.h>	// végül (egy teljes hét után) sikerült működésre bírni, nem is találtam más módot szöveg megjelenítésére
						// (emlékeztető: a 64 bites könyvtár nem 32 bites, így a 32 bites compiler nagyon nem szereti)

// Mivel a program sok síkbeli ponttal dolgozik, átláthatóság és saját dolgunk megkönnyítése érdekében ezeket struktúrával lekezeljük
typedef struct Koord {
	double x, y;
} Koord;

// Két pont (x-y koordinátapárral megadva) távolságát számolja ki - nem két Koord-dal dolgozunk, mert legtöbbször a képernyőn való végigiterálás i-j értékei alkotják az egyik párt
double Tav(double ax, double ay, double bx, double by) {
	return sqrt(pow(ax - bx, 2) + pow(ay - by, 2));
}

// Igazságértékkel tér vissza annak megfelelően, hogy egy kiértékelt távolság a feladatban írtaknak megfelelő-e a várt érték és epszilon segítségével
bool NEps(double n, double A, double eps) {
	return fabs(n - A) < eps;
}

int main(int argc, char *argv[]) {
	const double eps = 1;
	const int WW = 640, WH = 480;

	// Ablak teljeskörű létrehozása hibakezeléssel:

	// SDL könyvtár inicializálása
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_Log("Sikertelen SDL inicializalas: %s", SDL_GetError());
		exit(1);
	}

	// 640x480 képpontos ablak megnyitása
	SDL_Window *window = SDL_CreateWindow("Szorgalmi feladat: Azon pontok mértani helye...",
											SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
											WW, WH, 0);
	if(window == NULL) {
		SDL_Log("Sikertelen Ablak letrehozas: %s", SDL_GetError());
		exit(1);
	}

	// renderer létrehozása
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	if(renderer == NULL) {
		SDL_Log("Sikertelen Renderer letrehozas: %s", SDL_GetError());
		exit(1);
	}
	SDL_RenderClear(renderer);

	// Kör
	// P: O(320;240) r~=200
	Koord O = {320, 240};
	double r = 200;
	double d = 0;
	SDL_SetRenderDrawColor(renderer, 0xFF, 0, 0, 0xFF);

	// ablak bejárása ágyazott ciklussal (többi helyen is így teszünk)
	for (int i = 0; i < WW; i++) {
		for (int j = 0; j < WH; j++) {
			// távolság számítása (többi helyen is így teszünk)
			d = Tav(i, j, O.x, O.y);
			if (NEps(d, r, eps))
				SDL_RenderDrawPoint(renderer, i, j);
		}
	}

	// Elipszis
	// Z: F1(240;200) F2(400;280) t~=250
	Koord ZF1 = {240, 200}, ZF2 = {400, 280};
	double Zt = 250;
	d = 0;
	SDL_SetRenderDrawColor(renderer, 0, 0xFF, 0, 0xFF);

	for (int i = 0; i < WW; i++) {
		for (int j = 0; j < WH; j++) {
			d = Tav(i, j, ZF1.x, ZF1.y) + Tav(i, j, ZF2.x, ZF2.y);
			if (NEps(d, Zt, eps))
				SDL_RenderDrawPoint(renderer, i, j);
		}
	}

	// Hiperbola
	// K: F1(240;240) F2(400;280) |d|~=100
	Koord KF1 = {240, 240}, KF2 = {400, 280};
	double Kt = 100;
	d = 0;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0xFF, 0xFF);

	for (int i = 0; i < WW; i++) {
		for (int j = 0; j < WH; j++) {
			d = fabs(Tav(i, j, KF1.x, KF1.y) - Tav(i, j, KF2.x, KF2.y));
			if (NEps(d, Kt, eps))
				SDL_RenderDrawPoint(renderer, i, j);
		}
	}

	// Parabola
	// F: P(320;240) e: x=400
	Koord P = {320, 240};
	double x = 400;
	d = 0;
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	for (int i = 0; i < WW; i++) {
		for (int j = 0; j < WH; j++) {
			d = fabs(Tav(i, j, P.x, P.y) - fabs(i - x));
			if (d < eps)
				SDL_RenderDrawPoint(renderer, i, j);
		}
	}

	// szöveg megjelenítése
	if (TTF_Init() == -1) {
		SDL_Log("Sikertelen TTF inicializalas: %s", TTF_GetError());
		exit(1);
	}

	int szovegmeret = 64;
	TTF_Font *font = TTF_OpenFont("OpenSans-Regular.ttf", szovegmeret);

	if (font == NULL) {	// ha nem találná a megfelelő fontot
		SDL_Log("*font NULL pointer");
		exit(1);
	}

	SDL_Color piros = {0xFF, 0x00, 0x00};

	SDL_Surface *korszoveg = TTF_RenderText_Solid(font, "Kor", piros);

	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, korszoveg);

	SDL_Rect korszoveg_rect;
	korszoveg_rect.x = WW / 2;
	korszoveg_rect.y = WH / 2;
	korszoveg_rect.w = szovegmeret * 3;
	korszoveg_rect.h = szovegmeret * 1;

	SDL_RenderCopy(renderer, texture, NULL, &korszoveg_rect);

	// én a többi szöveg megjelenítésére egyszerűen nem vagyok hajlandó mindezek után

	// tényleges megjelenítés
	SDL_RenderPresent(renderer);

	// várakozás kilépésre
	SDL_Event ev;
    while (SDL_WaitEvent(&ev) && ev.type != SDL_QUIT) {};

	// Lényegileg garbage collection
	SDL_FreeSurface(korszoveg);
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);

	TTF_Quit();
	SDL_Quit();

	return 0;
}
