#include <iostream>
#include "Element.h"
using namespace std;

class Lista{
	public:
		Lista();								//konstruktor listy
		~Lista();								//destruktor listy
		Element *poczatek;						//wskaznik na pierwszy element listy
		Element *koniec;						//wskaznik na ostatni element listy
		void dodajNaPoczatek(int wartosc);      //dodawanie elementu o wskazanej wartosci na poczatek listy
		void dodajNaKoniec(int wartosc);        //dodawanie elementu o wskazanej wartosci na koniec listy
		void dodajPo(int pozycja, int wartosc); //dodawanie elementu o danej wartosci na wskazanej pozycji
		void usunPierwszy();					//usuwanie pierwszego elementu z listy
		void usunOstatni();						//usuwane ostatniego elementu z listy
		void usunWartosc(int wartosc);			//usuwanie elementu o podanej wartosci
		void usunMiejsce(int miejsce);			//??? usuwanie elemetu ze wskazanego miejsca
		void usun(Element *e);					//??? usuwanie wskazanego elementu
		void wyswietl();						//wy�wietlenie listy
		void wyswietlPrzod();					//wy�wietlenie listy od przodu
		void wyswietlTyl();						//wyswietlenie listy od ty�u
		bool wyszukaj(int wartosc);			//wyszukanie elementu o podanej wartosci
		void wczytajZPliku(fstream plik);		//wczytanie wartosci element�w listy z pliku
		void wygeneruj(int liczba);				//generowanie listy o podanej liczbie element�w
};