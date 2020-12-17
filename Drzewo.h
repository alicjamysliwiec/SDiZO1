#include <iostream>
#include <fstream>
#include "Wezel.h"
#include<Windows.h>

#define KOLOR_NORMALNY SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY  | FOREGROUND_GREEN)
#define KOLOR_CZARNY SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY)
#define KOLOR_CZERWONY SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_INTENSITY)

using namespace std;

class Drzewo{
  public:
    Wezel straznik;       // Wêze³ stra¿nika
    Wezel *korzen;        // Korzeñ drzewa czerwono-czarnego
	string gora;          //elementy poprawiajace widok drzewa (laczace potomka z rodzicem, gorna czesc)
	string dol;           //elementy poprawiajace widok drzewa (laczace potomka z rodzicem, dolna czesc)
	string prosto;        //elementy poprawiajace widok drzewa (laczace potomka z rodzicem, pionowa czesc)




    Drzewo();                   // Konstruktor klasy
    ~Drzewo();                  // Destruktor klasy
	void usun(Wezel *wezel);    // Usuwa wêze³ i wszystkich jego potomkow
    Wezel *wyszukaj(int klucz); // Wyszukuje wêze³ o zadanym kluczu 

	void rotacjaL(Wezel *Obracany); // Rotacja w lewo wzglêdem wêz³a
	void rotacjaP(Wezel *Obracany); // Rotacja w prawo wzglêdem wêz³a

	Wezel* dodaj(int klucz);   // Wstawia wêze³ o zadanym kluczu
	void naprawa(Wezel *X);    //naprawia po dodaniu wezla

	/* funkcja rekurencyjna wyswietlajaca podany wezel i wszystkich jego potomkow
	*p - wskaznik na wezel ktory aktualnie wypisujemy
	glowny - ciag ktory bedziemy wypisywac
	info - zawiera informacje ktory potomek teraz czy prawy (gorny-g) czy lewy(dolny-d)
	*/
	void wyswietl(Wezel * p, string glowny = "", char info = NULL);

	void wyswietl();                   //funkcja wyswietlajaca drzewo
    void usun(int n, bool test=false); // funkcja usuwajaca wêze³ o wartosci n jesli test bedzie true to nie wyswietli drzewa przed naprawa
	void wczytaj(fstream plik);        //funkcja wczytujaca drzewo z pliku
	void wygeneruj(int liczba);        //funkcja generujaca drzewo o zadanej liczbie argumentow
	void wygenerujLosowo(int liczba);  //funkcja do wyœwietlania losowo
	};
