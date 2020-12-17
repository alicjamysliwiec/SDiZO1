#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include "Tablica.h"

using namespace std;

//konstruktor tablicy
Tablica::Tablica() {
	Tablica::wskaznikNaPoczatek = NULL; //Pierwszy element tablicy domy�lnie ustawiamy na warto�� NULL
	Tablica::rozmiar = 0;				//Rozmiar tablicy domy�lnie na 0
}

//destruktor tablicy
Tablica::~Tablica(){
	if(wskaznikNaPoczatek != NULL){
		delete[]wskaznikNaPoczatek; 
	}
}

//dodawania elementu na pocz�tek tablicy
void Tablica::dodajNaPoczatek(int argument){
	int *nowyWskaznik = new int[rozmiar + 1];		//tworzymy now� tablic�
	nowyWskaznik[0] = argument;						//ustawiamy wstawiany element jako pierwszy
	for(int i=0 ; i<rozmiar ; i++){
		nowyWskaznik[i+1] = wskaznikNaPoczatek[i];	//przesuwamy wszystkie pozosta�e o jedn� pozycj�
	}
	delete[]wskaznikNaPoczatek;						//usuwamy wcze�niejszy wska�nik
	wskaznikNaPoczatek = nowyWskaznik;				//ustawiamy nowy
	rozmiar++;										//zwi�kszamy rozmiar tablicy
}

//dodwanie elementu na koniec tablicy
void Tablica::dodajNaKoniec(int argument){
	int *nowyWskaznik = new int[rozmiar + 1];		//tworzymy now� tablic�
	for(int i=0 ; i<rozmiar ; i++){
		nowyWskaznik[i] = wskaznikNaPoczatek[i];	//przepisujemy wszystkie elementy
	}
	nowyWskaznik[rozmiar] = argument;				//ustawiamy nasz element jako ostatni
	delete[]wskaznikNaPoczatek;						//usuwamy dotychczasowy wska�nik
	wskaznikNaPoczatek = nowyWskaznik;				//ustawiamy nowy
	rozmiar++;										//zwiekszamy rozmiar tablicy
}

//dodwanie elementu na wskazanej pozycji
void Tablica::dodaj(int argument, int pozycja){
	if(pozycja < 0 || pozycja > rozmiar) cout<<"W tablicy nie istnieje podana pozycja\n";
	else{
	   	int *nowyWskaznik = new int[rozmiar + 1];		//tworzymy now� tablic�
	   	nowyWskaznik[pozycja] = argument;				//ustawiamy nasz element we wskazanej pozycji
		   	for(int i=0 ; i<pozycja ; i++){
			nowyWskaznik[i] = wskaznikNaPoczatek[i];	//przepisujemy tablice do momentu wstawienia elementu
		}
		for(int i=pozycja ; i < rozmiar ; i++){	
			nowyWskaznik[i+1] = wskaznikNaPoczatek[i];	//przesuwamy elementy tablicy po wstawieniu nowego
		}
		delete[]wskaznikNaPoczatek;						//usuwamy dotychczasowy wska�nik
		wskaznikNaPoczatek = nowyWskaznik;				//ustawiamy nowy
		rozmiar++;										//zwi�kszamy rozmiar tablicy
	}
}

//usuwanie pierwszego elementu z tablicy
void Tablica::usunPierwszy(){
	if(rozmiar == 0) cout<<"Tablica jest pusta\n";
	else{
		int *nowyWskaznik = new int[rozmiar - 1];		//tworzymy now� tablic�
		for(int i=0 ; i<rozmiar ; i++){
		   	nowyWskaznik[i] = wskaznikNaPoczatek[i+1];	//przesuwamy wszystkie elementy
	   	}
	   	delete[]wskaznikNaPoczatek;						//usuwamy dotychczasowy wska�nik
		wskaznikNaPoczatek = nowyWskaznik;				//ustawiamy nowy
		rozmiar--;										//zmniejszamy rozmiar tablicy
	}
}

//usuwanie ostatniego elementu z tablicy
void Tablica::usunOstatni(){
	if(rozmiar == 0) cout<<"Tablica jest pusta\n";
	else{
		int *nowyWskaznik = new int[rozmiar - 1];			//tworzymy now� tablic�
		for(int i=1 ; i<rozmiar ; i++){
		   	nowyWskaznik[i-1] = wskaznikNaPoczatek[i-1];	//przesuwamy wszystkie elementy
	   	}
	   	delete[]wskaznikNaPoczatek;							//usuwamy dotychczasowy wska�nik
		wskaznikNaPoczatek = nowyWskaznik;					//ustawiamy nowy
		rozmiar--;											//zmniejszamy rozmiar tablicy
	}
}

//usuwanie elementu z wyznaczonej pozycji
void Tablica::usun(int pozycja){
	if(rozmiar == 0) cout<<"Tablica jest pusta\n";
	else if(pozycja < 0 || pozycja > rozmiar) cout<< "W tablicy nie istnieje podana pozycja\n";
	else{
		int *nowyWskaznik = new int[rozmiar - 1];		//tworzymy now� tablic�
		for(int i=0 ; i<pozycja ; i++){
		   	nowyWskaznik[i] = wskaznikNaPoczatek[i];	//przepisujemy wszystkie elementy do momentu usuni�cia
	   	}
	   	for(int i = pozycja ; i<rozmiar ; i++){
			nowyWskaznik[i] = wskaznikNaPoczatek[i+1];	//przesuwamy reszt� element�w po usuni�ciu
		}
	   	delete[]wskaznikNaPoczatek;						//usuwamy dotychczasowy wska�nik
		wskaznikNaPoczatek = nowyWskaznik;				//ustawiamy nowy
		rozmiar--;										//zmniejszamy rozmiar tablicy
	}
}

//wyszukiwanie elementu w tablicy
int Tablica::wyszukaj(int argument){
	for(int i = 0; i<rozmiar ; i++){			//przechodzimy po wszystkich elementach tablicy
		if(wskaznikNaPoczatek[i] == argument){
			return i;							//jak znajdziemy podany element, zwracamy jego warto��
		}
	}
	return -1;
}


//wy�wietlanie tablicy
void Tablica::wyswietl(){
	cout<<"Stan tablicy: \n";
	if(rozmiar == 0) cout<<"Tablica jest pusta\n";
	else{
		for(int i = 0; i<rozmiar ; i++){
			cout<<"[" << wskaznikNaPoczatek[i] << "] "; // przechodzimy po wszystkich elementach i je wy�wietlamy
		}
	}
}

//wczytywanie z pliku
void Tablica::wczytajZPliku(fstream plik){
	delete[]wskaznikNaPoczatek;				//usuwamy wskaznik na poczatek
	plik >> rozmiar;						//wczytujemy rozmiar tablicy
	int *nowyWskaznik = new int[rozmiar];	//tworzymy now� tablic�
	wskaznikNaPoczatek = nowyWskaznik;		//tworzymy nowy wska�nik na pocz�tek
	for (int i = 0; i < rozmiar; i++)
	{
		plik >> wskaznikNaPoczatek[i];		//wczytujemy koleje liczby do tablicy
	}
	cout << "Wczytalem tablice z pliku\n";

}

//generowanie tablicy
void Tablica::wygeneruj(int liczba){
	delete[]wskaznikNaPoczatek;				//usuwamy wska�nik na pocz�tek
	rozmiar = liczba;						//ustalamy rozmiar
	int *nowyWskaznik = new int[rozmiar];	//tworzymy now� tablic�
	wskaznikNaPoczatek = nowyWskaznik;		//tworzymy nowy wska�nik
	for (int i = 0; i < rozmiar;i++)		//przechodzimy po wszystkich pozycjach tablicy
	{
		wskaznikNaPoczatek[i]= rand();		//losujemy liczby do tablicy
	}
}

