#include<conio.h>
#include<string>
#include <iostream>
#include <fstream>
#include "Tablica.h"
#include "Lista.h"
#include "stoper.h"
#include "Kopiec.h"
#include "Drzewo.h"

using namespace std;

fstream wczytajPlik(){
	fstream plik;
	string nazwa; //nazwa pliku z ktorego wczytujemy
	do
	{
		cout << "\nPodaj nazwe pliku z ktorego mam pobrac dane(musi konczyc sie na .txt i byc w katalogu programu): ";
		cin >> nazwa;
		plik.open(nazwa);
	} while (!plik.good()); //dopoki nie uda sie wczytac pliku powtarza zabytanie o nazwe pliku
	return plik;
}

void NacisnijKlawiszByKontynuwoac(){
	cout << "\nNacisnij dowolny klawisz by kontynuowac" << endl;
	_getche();
}

void mierzTablica(){
	Tablica tablica;
	int liczbaProb, wielkosc, los, losPozycja;
	stoper dodajP, dodajK, dodajL, usunP, usunK, usunL, wyszukaj;
	cout << "Podaj wielkosc struktury: ";
	cin >> wielkosc;
	cout << "Podaj liczbe testow: ";
	cin >> liczbaProb;
	for (int j = 0; j < liczbaProb; j++)	//powtarzamy tyle razy, ile wynosi podania liczba prób
	{
		tablica.wygeneruj(wielkosc);		//generujemy tablicê o podanej wielkoœæ	

			los = rand();					//losujemy liczbê
			dodajP.start();					//zaczynamy mierzyc czas 
			tablica.dodajNaPoczatek(los);	//dodajemy na pocz¹tek wylosowan¹ liczbê
			dodajP.stop();					//zatrzymujemy stoper
			dodajP.dodajCzas();				//zapisujemy zmierzony czas

			usunP.start();					//zaczynamy mierzyæ czas
			tablica.usunPierwszy();			//usuwamy pierwszy element tablicy
			usunP.stop();					//zatrzymujemy stoper
			usunP.dodajCzas();				//zapisujemy zmierzony czas

			los = rand();					//losujemy liczbê
			dodajK.start();					//zaczynamy mierzyc czas
			tablica.dodajNaKoniec(los);		//dodajemy na koniec wylosowany element
			dodajK.stop();					//zatrzymujemy stoper
			dodajK.dodajCzas();				//zapisujemy zmierzony czas

			usunK.start();					//zaczynamy mierzyc czas
			tablica.usunOstatni();			//usuwamy ostatni element z tablic
			usunK.stop();					//zatrzymujemy stoper
			usunK.dodajCzas();				//zapisujemy zmierzony czas

			los = rand();						//losujemy liczbê
			losPozycja = rand()%tablica.rozmiar;//losujemy pozycjê
			dodajL.start();						//zaczynamy mierzyc czas
			tablica.dodaj(los, losPozycja);		//dodajemy wylosowany element w wylosowane miejsce
			dodajL.stop();						//zatrzymujemy zegar
			dodajL.dodajCzas();					//zapisujemy zmierzony czas

			losPozycja = rand() % tablica.rozmiar;	//losujemy pozycjê
			usunL.start();							//zaczynamy mierzyæ czas
			tablica.usun(losPozycja);				//usuwamy element z wylosowanej pozycji
			usunL.stop();							//zatrzymujemy zegar
			usunL.dodajCzas();						//zapisujemy zmierzony czas

			los = rand()%tablica.rozmiar;			//losujemy liczbê
			los = tablica.wskaznikNaPoczatek[los];  //przypisujemy jej wartoœæ
			wyszukaj.start();						//zaczynamy mierzyc czas
			tablica.wyszukaj(los);					//wyszukujemy w tablicy liczbê
			wyszukaj.stop();						//zatrzymujemy stoper
			wyszukaj.dodajCzas();					//zapisujemy zmierzony czas
	}

	//wyniki wyœwietlamy
	cout << "Time dodajP: " << dodajP.licznik /liczbaProb << endl;
	cout << "Time dodajK: " << dodajK.licznik /liczbaProb << endl;
	cout << "Time dodajL: " << dodajL.licznik /liczbaProb << endl;
	cout << "Time usunP: " << usunP.licznik /liczbaProb << endl;
	cout << "Time usunK: " << usunK.licznik /liczbaProb << endl;
	cout << "Time usunL: " << usunL.licznik /liczbaProb << endl;
	cout << "Time wyszukaj: " << wyszukaj.licznik/liczbaProb << endl;
}

void mierzLista(){
	Lista lista;
	int liczbaProb, wielkosc, los, losPozycja;
	stoper dodajP, dodajK, dodajL, usunP, usunK, usunL, wyszukaj;
	Element *element = new Element;
	cout << "Podaj wielkosc struktury: ";
	cin >> wielkosc;
	cout << "Podaj liczbe testow: ";
	cin >> liczbaProb;
	for (int j = 0; j < liczbaProb; j++)
	{
		lista.wygeneruj(wielkosc);

			los = rand();
			dodajP.start();
			lista.dodajNaPoczatek(los);
			dodajP.stop();
			dodajP.dodajCzas();

			usunP.start();
			lista.usunPierwszy();
			usunP.stop();
			usunP.dodajCzas();

			los = rand();
			dodajK.start();
			lista.dodajNaKoniec(los);
			dodajK.stop();
			dodajK.dodajCzas();

			usunK.start();
			lista.usunOstatni();
			usunK.stop();
			usunK.dodajCzas();

			los = rand();
			losPozycja = rand() % (wielkosc - 10);
			dodajL.start();
			lista.dodajPo(losPozycja, los);
			dodajL.stop();
			dodajL.dodajCzas();

			losPozycja = rand() % (wielkosc - 10);
			element = lista.poczatek;
			for (int k = 5; k < losPozycja; k++) element = element->nastepny;
			losPozycja = element->klucz;

			usunL.start();
			lista.usunWartosc(losPozycja);
			usunL.stop();
			usunL.dodajCzas();

			losPozycja = rand() % (wielkosc - 10);
			element = lista.poczatek;
			for (int k = 5; k < losPozycja; k++) element = element->nastepny;
			los = element->klucz;
			wyszukaj.start();
			lista.wyszukaj(los);
			wyszukaj.stop();
			wyszukaj.dodajCzas();
	}

	//wyniki
	cout << "Time usunP: " << usunP.licznik / liczbaProb << endl;
	cout << "Time usunK: " << usunK.licznik / liczbaProb << endl;
	cout << "Time usunL: " << usunL.licznik / liczbaProb << endl;
	cout << "Time dodajP: " << dodajP.licznik / liczbaProb << endl;
	cout << "Time dodajK: " << dodajK.licznik / liczbaProb << endl;
	cout << "Time dodajL: " << dodajL.licznik / liczbaProb << endl;
	cout << "Time wyszukaj: " << wyszukaj.licznik / liczbaProb << endl;
}

void mierzDrzewo(){
	Drzewo drzewo;
	int liczbaProb, wielkosc, los;
	stoper dodaj, usun, wyszukaj;
	cout << "Podaj wielkosc struktury: ";
	cin >> wielkosc;
	cout << "Podaj liczbe testow: ";
	cin >> liczbaProb;
	for (int j = 0; j < liczbaProb; j++)
	{
		drzewo.wygeneruj(wielkosc);
	
			los = rand()%wielkosc-wielkosc/2;
			dodaj.start();
			drzewo.naprawa(drzewo.dodaj(los));
			dodaj.stop();
			dodaj.dodajCzas();

			drzewo.wygeneruj(wielkosc);
			los = rand() % wielkosc - wielkosc / 2;
			usun.start();
			drzewo.usun(los, true);
			usun.stop();
			usun.dodajCzas();

			los = rand() % wielkosc - wielkosc / 2;
			wyszukaj.start();
			drzewo.wyszukaj(los);
			wyszukaj.stop();
			wyszukaj.dodajCzas();

	}

	//wyniki
	cout << "Time dodaj: " << dodaj.licznik / liczbaProb << endl;
	cout << "Time usun: " << usun.licznik / liczbaProb << endl;
	cout << "Time wyszukaj: " << wyszukaj.licznik / liczbaProb << endl;
}

void mierzKopiec(){
	Kopiec kopiec;
	int liczbaProb, wielkosc, los;
	stoper dodaj, usun, wyszukaj;
	cout << "Podaj wielkosc struktury: ";
	cin >> wielkosc;
	cout << "Podaj liczbe testow: ";
	cin >> liczbaProb;
	for (int j = 0; j < liczbaProb; j++)
	{
		kopiec.wygeneruj(wielkosc);

			los = rand();
			dodaj.start();
			kopiec.dodaj(los, true);
			dodaj.stop();
			dodaj.dodajCzas();

			los = rand() % kopiec.rozmiar;
			los = kopiec.poczatek[los];
			usun.start();
			kopiec.usun(los, true);
			usun.stop();
			usun.dodajCzas();

			los = rand() % kopiec.rozmiar;
			los = kopiec.poczatek[los];
			wyszukaj.start();
			kopiec.wyszukaj(los);
			wyszukaj.stop();
			wyszukaj.dodajCzas();
	}

	//wyniki
	cout << "Time dodaj: " << dodaj.licznik / liczbaProb << endl;
	cout << "Time usun: " << usun.licznik / liczbaProb << endl;
	cout << "Time wyszukaj: " << wyszukaj.licznik / liczbaProb << endl;
}

void wyswietlMenu(string info)
{
	cout << "==============================" << endl;
	cout << info << endl;
	cout << "==============================" << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Usun" << endl;
	cout << "3.Dodaj" << endl;
	cout << "4.Znajdz" << endl;
	cout << "5.Utworz losowo" << endl;
	cout << "6.Wyswietl" << endl;
	cout << "7.Test (pomiary)" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje: ";
}

void menuTablica()
{
	Tablica tablica;
	char option;
	string nazwa_pliku;
	int indeks, wartosc;
	ifstream plik;

	do{
		system("cls");
		wyswietlMenu("        --- TABLICA ---");
		option = _getche();
		cout << endl;
		switch (option){
		case '1': //wczytytwanie  tablicy z pliku

			tablica.wczytajZPliku(wczytajPlik());
			tablica.wyswietl();
			NacisnijKlawiszByKontynuwoac();
			break;

		case '2': //usuwanie elemenu z tablicy
			cout << "Podaj indeks: ";
			cin >> indeks;
			tablica.usun(indeks);
			tablica.wyswietl();
			NacisnijKlawiszByKontynuwoac();
			break;

		case '3': //dodawanie elemetu do tablicy
			cout << "Podaj indeks: ";
			cin >> indeks;
			cout << "Podaj wartosc: ";
			cin >> wartosc;

			tablica.dodaj(wartosc,indeks);
			tablica.wyswietl();
			NacisnijKlawiszByKontynuwoac();
			break;

		case '4': //znajdowanie elemetu w tablicy
			cout << "Podaj wartosc: ";
			cin >> wartosc;
			indeks=tablica.wyszukaj(wartosc);	
			if (indeks == -1) cout << "Podaj wartosc: " << wartosc << " nie wystepuje w tablicy\n";
			else cout << "Podaj wartosc: " << wartosc << " wystepuje w tablicy na miejscu: " << indeks <<"\n";
			NacisnijKlawiszByKontynuwoac();
			break;

		case '5':  //generowanie  tablicy
			cout << "Podaj ilosc elementow tablicy: ";
			cin >> wartosc;
			tablica.wygeneruj(wartosc);
			tablica.wyswietl();
			NacisnijKlawiszByKontynuwoac();
			break;

		case '6':  //wyœwietlanie tablicy
			tablica.wyswietl();
			NacisnijKlawiszByKontynuwoac();
			break;

		case '7': //pomiar czasu
			mierzTablica();
			NacisnijKlawiszByKontynuwoac();
			break;
		}

	} while (option != '0');
}

void menuLista()
{
	Lista lista;
	char option;
	string nazwa_pliku;
	int indeks, wartosc;
	Element *element = new Element;

	do{
		system("cls");
		wyswietlMenu("  --- LISTA DWUKIERUNKOWA ---");

		option = _getche();
		cout << endl;
		switch (option){
		case '1': //wczytytwanie  listy z pliku
			lista.wczytajZPliku(wczytajPlik());
			lista.wyswietl();
			NacisnijKlawiszByKontynuwoac();
			break;

		case '2': //usuwanie elemenu z listy
			cout << "Podaj wartosc: ";
			cin >> wartosc;
			lista.usunWartosc(wartosc);
			lista.wyswietl();
			NacisnijKlawiszByKontynuwoac();
			break;

		case '3': //dodawanie elemetu do listy
			cout << "Podaj wartosc nowego elementu: ";
			cin >> wartosc;
			cout << "Podaj pozycje, na ktora w liscie chcesz wstawic nowy element: ";
			cin >> indeks;
			lista.dodajPo(indeks,wartosc);
			lista.wyswietl();			
			NacisnijKlawiszByKontynuwoac();
			break;

		case '4': //znajdowanie elemetu w liscie
			cout << "Podaj wartosc: ";
			cin >> wartosc;
			if (lista.wyszukaj(wartosc)) cout << "Znaleziono element\n";
			else cout << "Nie znaleziono elementu\n";
			lista.wyswietl();
			NacisnijKlawiszByKontynuwoac();
			break;

		case '5':  //generowanie  listy
			cout << "Podaj ilosc elementow listy: ";
			cin >> wartosc;
			lista.wygeneruj(wartosc);
			lista.wyswietl();
			NacisnijKlawiszByKontynuwoac();
			break;

		case '6':  //wyœwietlanie listy
			lista.wyswietl();
			NacisnijKlawiszByKontynuwoac();
			break;

		case '7': //mierzenie czasu
			mierzLista();
			NacisnijKlawiszByKontynuwoac();
			break;
		}

	} while (option != '0');
}

void menuKopiec()
{
	Kopiec kopiec;
	char option;
	string nazwa_pliku;
	int wartosc;


	do{
		system("cls");
		wyswietlMenu("        --- KOPIEC ---");
		option = _getche();
		cout << endl;
		switch (option){
		case '1': //wczytytwanie kopca z pliku
			kopiec.wczytaj(wczytajPlik());
			kopiec.wyswietl();
			NacisnijKlawiszByKontynuwoac();
			break;
		case '2': //usuwanie elemenu z kopca
			cout << "Podaj wartosc:";
			cin >> wartosc;
			kopiec.usun(wartosc);
			kopiec.wyswietl();
			NacisnijKlawiszByKontynuwoac();
			break;

		case '3': //dodawanie elemetu do kopca
			cout << "Podaj wartosc:";
			cin >> wartosc;
			kopiec.dodaj(wartosc);
			kopiec.wyswietl();
			NacisnijKlawiszByKontynuwoac();
			break;

		case '4': //tznajdowanie elemetu w kopcu
			cout << "Podaj wartosc:";
			cin >> wartosc;
			if (kopiec.wyszukaj(wartosc)) cout << "Podany element wystepuje w drzewie\n";
			else cout << "Podany element nie wystepuje w drzewie\n";
			kopiec.wyswietl();
			NacisnijKlawiszByKontynuwoac();
			break;

		case '5':  //generowanie kopca
			cout << "Podaj ilosc elementow kopca:";
			cin >> wartosc;
			kopiec.wygeneruj(wartosc);
			kopiec.wyswietl();
			NacisnijKlawiszByKontynuwoac();
			break;

		case '6':  //wyœwietlanie kopca
			kopiec.wyswietlTablice();
			kopiec.wyswietl();
			NacisnijKlawiszByKontynuwoac();
			break;

		case '7': //pomiar czasu
			mierzKopiec();
			NacisnijKlawiszByKontynuwoac();
			break;
			
		}
	} while (option != '0');
}

void menuDrzewo(){
	char option;
	int wartosc;
	Drzewo drzewo;
	ifstream plik;
	Wezel *wezel;

	do{
		system("cls");
		wyswietlMenu("--- DRZEWO CZERWONO-CZARNE ---");
		option = _getche();
		cout << endl;
		
		switch (option){
		case '1': //wczytytwanie drzewa z pliku
			drzewo.wczytaj(wczytajPlik());
			drzewo.wyswietl();
			NacisnijKlawiszByKontynuwoac();

			break;

		case '2': //usuwanie elemenu z drzewa
			cout << "Podaj wartosc:";
			cin >> wartosc;
			drzewo.usun(wartosc);
			drzewo.wyswietl();
			NacisnijKlawiszByKontynuwoac();
			break;

		case '3': //dodawanie elemetu do drzewa
			cout << "Podaj wartosc:";
			cin >> wartosc;
			wezel = new Wezel;
			wezel=drzewo.dodaj(wartosc);
			drzewo.wyswietl();
			cout << endl;
			drzewo.naprawa(wezel);
			drzewo.wyswietl();	
			NacisnijKlawiszByKontynuwoac();
			break;

		case '4': //znajdowanie elemetu w drzewie
			cout << "Podaj wartosc:";
			cin >> wartosc;
			wezel = new Wezel;
			wezel=drzewo.wyszukaj(wartosc);
			if (wezel != &drzewo.straznik) 	cout << "Podany element wystepuje w drzewie\n";
			else cout << "Podany element nie wystepuje w drzewie\n";
			drzewo.wyswietl();
			NacisnijKlawiszByKontynuwoac();
			break;

		case '5':  //generowanie  drzewa
			cout << "Podaj ilosc elementow drzewa:";
			cin >> wartosc;
			drzewo.wygenerujLosowo(wartosc);
			drzewo.wyswietl();
			NacisnijKlawiszByKontynuwoac();
			break;

		case '6':  //wyœwietlanie drzewa
			drzewo.wyswietl();
			NacisnijKlawiszByKontynuwoac();
			break;

		case '7': //pomiar czasu
			mierzDrzewo();
			NacisnijKlawiszByKontynuwoac();
			break;
		}
		
	} while (option != '0');
}
int main()
{
	KOLOR_NORMALNY;
	char option;
	do{
		system("cls");
		cout << "====================" << endl;
		cout << "==== MENU GLOWNE ===" << endl;
		cout << "====================" << endl;
		cout << "1.Tablica" << endl;
		cout << "2.Lista dwukierunkowa" << endl;
		cout << "3.Kopiec" << endl;
		cout << "4.Drzewo czerwono-czarne" <<endl;
		cout << "0.Wyjscie" << endl;
		cout << "Podaj opcje: ";		
		option = _getche();
		cout << endl;

		switch (option){
		case '1':
			menuTablica();
			break;
		case '2':
			menuLista();
			break;
		case '3':
			menuKopiec();
			break;
		case '4':
			menuDrzewo();
			break;
		case '0':
			break;
		};
	}
	while (option != '0');
	
}