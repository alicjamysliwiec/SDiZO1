#include "Kopiec.h"
using namespace std;


//konstruktor klasy kopiec
Kopiec::Kopiec(){
	poczatek = new int[100001]; //alokacja w pamieci na kopiec
	rozmiar = 0;                //poczatkowy rozmiar kopca
	gora = 201;                 //elementy ramki
	gora += 205;                //elementy ramki
	gora += 205;                //elementy ramki
	dol = 200;                  //elementy ramki
	dol += 205;                 //elementy ramki
	dol += 205;                 //elementy ramki
	prosto = 186;               //elementy ramki
	prosto += ' ';
	prosto += ' ';
}

//destruktor kopca
Kopiec::~Kopiec(){
	if (poczatek != NULL){
		delete[]poczatek;  
	}
}

//funkcja pomocnicza zamieniajaca dwa argumenty wartosciami
void Kopiec::zamien(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

//naprawa kopca od dolu
void Kopiec::naprawOdDolu()
{
	int i = rozmiar - 1;            // ostatni element kopca
	int k = (i - 1) / 2;            //rodzic wezla ostatniego elementu w kopcu
	while (poczatek[i]>poczatek[k]) //dopoki nie ma zgodnosci w kopcu
	{
		zamien((poczatek + i), (poczatek + k)); //zamienia rodzica z synem
		i = k;                                  //teraz zajmuje sie rodzicem
		k = (i - 1) / 2;                        //rodzic wezla w kopcu
	}
}

//naprawa kopca od dolu
void Kopiec::naprawOdGory(int i)
{
	int k;
	k = (2 * i) + 1;     //lewy potomek usuwanego
	while (k <= rozmiar) //sprawdzamy czy ma prawego potomka jezeli nie ma 
	{

		if (k + 1 > rozmiar || poczatek[k] >= poczatek[k + 1]); //sprawdzamy czy ma lewego potomka i czy jest wiekszy od prawego
		else k++; 			                                    //jezeli jest wiekszy to sie nim zajmujemy jezeli nie to dalej prawym synem
		if (poczatek[i] < poczatek[k])                          //jezeli syn wiekszy od rodzica to zamiana
		{
			zamien((poczatek + i), (poczatek + k));
			i = k;
			k = (2 * i) + 1;
		}
		else return;  //jezeli nie to kopiec jest naprawiony, wiec koniec
	}
}

//dodanie liczby do kopca
void Kopiec::dodaj(int liczba, bool test)
{
	poczatek[rozmiar] = liczba; //dodanie liczby na koniec kopca
	rozmiar++;                 //zwiekszenie rozmiaru

	if (!test) wyswietl();
	naprawOdDolu(); //naprawa kopca
}

//wczytywanie z pliku
void Kopiec::wczytaj(fstream plik)
{
	for (int i = 0; i < rozmiar; i++)
	{
		poczatek[i] = NULL;

	}
	rozmiar = 0;
	int liczba, b;
	plik >> liczba;                  //wczytanie rozmiaru kopca
	for (int i = 0; i < liczba; i++) //dodawanie do kopca
	{
		plik >> b;     //wczytanie liczby
		dodaj(b,true); //dodanie do kopca
	}
	cout << "\nKopiec zostal poprawnie wczytany.\n";
}

//usuwanie podanej liczby z kopca;
void Kopiec::usun(int n, bool test)
{
	if (rozmiar > 0)
	{
		int i = 0; //indeks szukanej liczby
		//wyszukiwanie
		for (i = 0; i < rozmiar;i++)
			if (n == poczatek[i]) break;

		if (n != poczatek[i]) { cout << "Blad! Nie ma takiej liczby w kopcu.\n"; return; }

		rozmiar--;                                 //zmniejszenie rozmiaru
		zamien((poczatek+i), (poczatek + rozmiar));//zamiana usunietej liczby z ostatnia liczba w kopcu
		poczatek[rozmiar] = NULL;

		if (!test) wyswietl();
		//naprawa kopca
		naprawOdGory(i);
	}
	else cout << "Rozmiar jest 0! Nie da sie usunac" << endl;

}
//wyswietlanie kopca
void Kopiec::wyswietl(string glowny, char info, int n)
{
	string tmp;

	if (n < rozmiar)
	{
		//wyswietlanie prawego potmka
		tmp = glowny;
		if (info == 'g') tmp[tmp.length() - 3] = ' '; //zastapienie elementu laczacego spacja
		wyswietl(tmp + prosto, 'g', 2 * n + 2);       //przechodzimy do prawego potomka

		tmp = tmp.substr(0, glowny.length() - 3);//skraca o 3 linie by sie poprawnie wyswietlo

		cout << tmp;
		if (info == 'g') cout << gora;     //jezeli prawy potomek to elementy do wyswietlania prawego
		else if (info == 'd') cout << dol; //jezeli lewy potomek to elementy do wyswietlania lewego
		cout << *(poczatek + n) << endl;

		//wyswietlanie lewego potomka
		tmp = glowny;
		if (info == 'd') tmp[tmp.length() - 3] = ' '; //zastapienie elementu laczacego spacja
		wyswietl(tmp + prosto, 'd', 2 * n + 1);       //przechodzimy do lewego potomka
	}
}
//wyszukiwanie liczby
bool Kopiec::wyszukaj(int liczba)
{
	for (int i = 0; i < rozmiar; i++)               //przeszukuje caly kopiec
	{
		if (poczatek[i] == liczba) { return true; } //jezeli liczba jest w kopcu to zwraca true
	}
	return false;                                   //jezeli nie ma to zwraca false

}

void Kopiec::wyswietlTablice()
{
	for (int i = 0; i < rozmiar; i++)
	{
		cout << poczatek[i] << " ";
	}
}

void Kopiec::wygeneruj(int liczba)
{
	for (int i = 0; i < rozmiar; i++)
	{
		poczatek[i]=NULL;

	}
	rozmiar = 0;
	for (int i = 0; i < liczba; i++)
	{
		dodaj(rand(), true);
	}
}