#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Kopiec{
public:
	int *poczatek; //wskaznik na poczatek kopca
	int rozmiar;   //rozmiar kopca
	string gora;   //elementy poprawiajace widok kopca (laczace potomka z rodzicem)
	string dol;    //elementy poprawiajace widok kopca (laczace potomka z rodzicem)
	string prosto; //elementy poprawiajace widok kopca (laczace potomka z rodzicem)

	/* funkcja rekurencyjna wyswietlajaca kopiec
	glowny - ciag ktory bedziemy wypisywac - domyslnie ""
	info - zawiera informacje ktory potomek teraz czy prawy (gorny-g) czy lewy(dolny-d) -domyslnie NIC bo korzen nie jest niczyim potomkiem
	n - numer aktualnego wezla w drzewie ktore chcemy wypisac domyslnie 0, bo korzen ma index 0
	*/
	void wyswietl(string glowny = "", char info = NULL, int n = 0); //info zawiera informacje ktorego potomka teraz wyswietla, n-indeks w tablicy
	void wyswietlTablice();                                         //??? funkcja wyswietla kopiec
	void wczytaj(fstream plik);                                     //wczytuje kopiec z pliku
	void naprawOdDolu();                                            //naprawia kopiec od dolu
	void naprawOdGory(int i=0);                                     //naprawia kopiec od gory (domyslnie od korzenia)
	void zamien(int *a, int*b);                                     //funkcja pomocnicza, zamieniajaca miejscami dwie wartosci
	void dodaj(int liczba, bool test=false);                        //dodaje liczbe na koniec kopca, jesli zmienna test=false wtedy wyswietlmy wyglada kopca przed naprawa
	void usun(int liczba, bool test=false);                         //usuwa liczbe o wskazanej wartosci, jesli zmienna test=false wtedy wyswietlmy wyglada kopca przed naprawa
	bool wyszukaj(int liczba);                                      //sprawdza czy dana liczba jest w kopcu
	void wygeneruj(int liczba);                                     //generuje kopiec o podanej liczbie elementow


	Kopiec();  //konstruktor kopca
	~Kopiec(); //destruktor kopca

};
