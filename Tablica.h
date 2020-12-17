#include <iostream>
#include <fstream>
using namespace std;

class Tablica{
	public: 
		int *wskaznikNaPoczatek;               // wskaznik na pierwszy element tablicy
		int rozmiar;                           // rozmiar tablicy
		Tablica();                             //konstruktor tablicy
		~Tablica();                            //destruktor tablicy
		void dodajNaPoczatek(int argument);    // funkcja dodaje element o wskazanej wartosci na poczatek tablicy
		void dodajNaKoniec(int argument);      // funkcja dodaje element o wskazanej wartosci na koniec tablicy
		void dodaj(int argument, int pozycja); //dodanie elementu o podanej wartoœci w podane miejsce
		void usunPierwszy();                   // funkcja usuwa element z poczatku tablicy
		void usunOstatni();					   // funkcja usuwa element z koñca tablicy
		void usun(int pozycja);				   // usuniecie elementu z podanej pozycji
		void wyswietl();					   // funkcja wyswietla zawartoœæ tablicy
		int wyszukaj(int argument);            //wyszukanie elementu o podanej wartoœci
		void wczytajZPliku(fstream plik);      // funkcja wczytuje wartosci tablicu z pliku o podanej nazwie
		void wygeneruj(int liczba);            // wygenerowanie tablicy o podanej liczbie elementów
};