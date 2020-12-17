#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include "Lista.h"

using namespace std;
  
Lista::Lista(){
    Lista::poczatek = NULL; //domy�lnie ustawiamy pierwszy element na zero
    Lista::koniec = NULL;	//ostatni te� ustawiamy domy�lnie na zero
};
  
Lista::~Lista(){
	Element *element; //tworzymy wskaznik na element
	while(poczatek){  //dopo�ki jest element pocz�tkowy
		element = poczatek->nastepny; //wskaznik z pierwszego elementu na nast�pny przypisujemy do elementu
		delete[]poczatek;			  //usuwamy pierwszy element
		poczatek = element;			  //ustawiamy jako pierwszy ten, na ktory wczesniej byl wskaznik, czyli 'element'
	}
};

void Lista::dodajNaPoczatek(int wartosc){ //funckja dodaje element o zadanej wartosci na poczatek listy
	if (poczatek == NULL){                // je�eli nie istnieje pierwszy element
		poczatek = new Element;			  // tworzymy nowy i ustawiamy jako pierwszy
		koniec = poczatek;				  // ostatni element jest jednocze�nie pierwszym
		poczatek->klucz = wartosc;		  // przypisujemy podan� warto�� do elementu
	}
	else{
		Element *element = new Element;     //tworzymy nowy element
		element->klucz = wartosc; 		    //ustawiamy klucz elementu na podan� wartosc
		element->nastepny = poczatek;		//wskaznik na nastepny element naszego dodawanego elementu wskazuje na pierwszy element
		element->poprzedni = NULL;			//a wskaznik na poprzedni wskazuje na NULL	
		poczatek->poprzedni = element;		//wskaznik na poprzedni element dotychczasowego pierwszego elementu wskazuje na dodawany
		poczatek = element;				    //dodawany element ustawiamy jako pierwszy	
	}
}

void Lista::dodajNaKoniec(int wartosc){ //funckcja dodaje element o zadanej wartosci na koniec listy
	if (poczatek == NULL){				//je�eli nie ma pierwszego elementu
		poczatek = new Element;			//tworzymy nowy i ustawiamy go jako pierwszy
		koniec = poczatek;				//ostatni element jest jednocze�nie pierwszym
		poczatek->klucz = wartosc;      //przypisujemy podan� warto�� do elementu
	}
	else
	{
		Element *element = new Element; //tworzymy nowy element	
		element->klucz = wartosc;	    //przypisujemy podan� warto�� do elementu
		element->nastepny = NULL;		//wskaznik na nastepny ustawiamy na NULL
		element->poprzedni = koniec;	//wskaznik na poprzedni ustawiamy na obecny ko�cowy element
		koniec->nastepny = element;		//wskaznik na nastepny obecnego ko�cowego ustawiamy na nowy element
		koniec = element;				//nasz nowy element ustawiamy jako ostatni w li�cie
	}
}

void Lista::dodajPo(int pozycja, int wartosc) //funkcja dodaje element o podanej wartosci na podanej pozycji
{
	if (poczatek == NULL){              //je�eli nie ma pierwszego elementu
		poczatek = new Element;			//tworzymy nowy i ustawiamy go jako pierwszy
		koniec = poczatek;				//ostatni element jest jednocze�nie pierwszym
		poczatek->klucz = wartosc;      //przypisujemy podan� warto�� do elementu
	}
	else{
		Element *element = poczatek;
		for (int i = 0; i < pozycja&&element != NULL; i++)
		{
			element = element->nastepny;                        //wyszukujemy element, za kt�rym wstawimy nasz  
		}
		if (element == poczatek) dodajNaPoczatek(wartosc);		//je�eli znaleziony element jest pierwszy
		else if (element == NULL) dodajNaKoniec(wartosc);
		else
		{
			Element *nowy = new Element;			//tworzymy nowy element
			nowy->klucz = wartosc;					//nadajemy mu podan� wartosc
			nowy->poprzedni = element->poprzedni;	//ustawiamy odpowiednie wska�niki na nastepne i poprzednie elementy
			nowy->nastepny = element;			
			element->poprzedni->nastepny = nowy;	
			element->poprzedni = nowy;
		}
	}
}

//wyswietlenie listy
void Lista::wyswietl(){
	wyswietlPrzod(); //od przodu
	cout << endl;
	wyswietlTyl();	 //od ty�u
}

//wyswietlenie listy od przodu
void Lista::wyswietlPrzod(){
	Element *element = poczatek;						//Pierwszy element listy
	if (element == NULL) cout << "Lista jest pusta\n";  //Je�eli pierwszy element nie istnieje, to lista jest pusta
	while (element != NULL){							//Dop�ki lista nie jest pusta
		cout << element->klucz << " ";					//Wy�wietlaj warto�ci element�w
		element = element->nastepny;					//Przej�cie do nast�pnego elementu
	}
}

//Wy�wietlenie listy od ty�u
void Lista::wyswietlTyl(){								
	Element *element = koniec;							//Ostatni element listy
	if (element == NULL) cout << "Lista jest pusta\n";	//Je�eli ostatni element nie istnieje, to lista jest pusta
	while (element != NULL){							//Dop�ki lista nie jest pusta
		cout << element->klucz << " ";					//Wy�wietlaj warto�ci element�w
		element = element->poprzedni;					//Przej�cie do poprzedniego elementu
	}
}

//Usuwanie pierwszego elementu
void Lista::usunPierwszy(){
	if(poczatek == NULL) cout<<"Lista jest pusta\n";	//Je�eli nie istnieje pierwszy element, to lista jest pusta
	else
	{
		Element *e = poczatek;							//Ustawienie elementu e jako pierwszego
		usun(e);										//Wywo�anie funkcji usuwaj�cej element
	}
}

void Lista::usunOstatni(){
	if (koniec== NULL) cout << "Lista jest pusta\n";	//Je�eli nie istnieje ostatni element, to lista jest pusta
	else
	{
		Element* e = koniec;							//Ustawienie elementu e jako ostatniego
		usun(e);										//Wywo�anie funkcji usuwaj�cej element
	}
}

//usuwa o podanej wartosci
void Lista::usunWartosc(int wartosc){
	if (poczatek == NULL) cout << "Lista jest pusta\n";  //Je�eli nie istnieje pierwszy element, to lista jest pusta
	else
	{
		Element *e = poczatek;
		while (e->klucz != wartosc && e!=koniec)
		{

			e = e->nastepny;						     //Wyszukujemy element, kt�ry chcemy usun��
		}
		if (e->klucz == wartosc) usun(e);				 //Wywo�ujemy funkcj� usuwaj�c� element
		else cout << "Nie ma takiej liczby na liscie\n"; //Nie zosta� znaleziony element o podanym kluczu
	}
}

//Usuwa kolejny na liscie
void Lista::usunMiejsce(int miejsce){
	if (poczatek == NULL) cout << "Lista jest pusta\n"; //Je�eli nie istnieje pierwszy element, to lista jest pusta
	else
	{
		Element *e = poczatek;							//Pierwszy element 
		for (int i = 0; i < miejsce;i++)
		{
			e = e->nastepny;							//Wyszukujemy element, kt�ry mamy usun��
		}
		usun(e);										//Wywyo�ujemy funkcj� usuwaj�c� kolejny element z listy
	}
}


//Wyszukanie elementu o podanej warto�ci
bool Lista::wyszukaj(int wartosc) {
	Element* element = poczatek;
	while (element != NULL) {
		if (element->klucz == wartosc) return true;
		element = element->nastepny;
	}
	return false;
}

//Usuwa znaleziony element na liscie (potrzebuje wskazanika na ten element)
void Lista::usun(Element *e)
{
  if(e->poprzedni!=NULL) e->poprzedni->nastepny = e->nastepny;
  else        poczatek = e->nastepny;
  if(e->nastepny!=NULL) e->nastepny->poprzedni = e->poprzedni;
  else        koniec = e->poprzedni;
  delete[] e;
}

//Wczytywanie element�w listy z pliku tekstowego
void Lista::wczytajZPliku(fstream plik){
	delete[]poczatek;			 //usuwamy poczatek
	delete[]koniec;				 //usuwamy koniec
	int rozmiar, klucz;
	Element *nowy = new Element; //Utworzenie nowego elementu
	plik >> rozmiar;		
	plik >> klucz;				 

	poczatek = nowy;             //ustawiamy poczatek listy
	for (int i = 1; i < rozmiar; i++)
	{
		nowy->klucz=klucz;                //przypisujemy klucz
		plik >> klucz;                    //wczytuje koleje liczby do tablicy
		nowy->nastepny = new Element;     //ustawiamy wskaznik na nastepny
		nowy->nastepny->poprzedni = nowy; //ustawiamy wskaznik nastepnego na poprzedni
		nowy = nowy->nastepny;            //przechodzimy do nastepnego elementu
	}
	nowy->klucz = klucz; //ustawiamy klucz ostatniego
	koniec = nowy;       //ustawiamy koniec listy

	cout << "Lista zostala wczytana.\n";
}

//Generowanie listy o  podanej liczbe element�w
void Lista::wygeneruj(int liczba){
	delete[]poczatek;			 //usuwamy pocz�tek
	delete[]koniec;				 //usuwamy koniec
	Element *nowy = new Element; //tworzymy nowy element
	poczatek = nowy;
	koniec = new Element;

	for (int i = 1; i < liczba; i++){
		nowy->klucz = rand();
		nowy->nastepny = new Element;
		nowy->nastepny->poprzedni = nowy;
		nowy = nowy->nastepny;
	}
	nowy->klucz = rand();
	koniec = nowy;
}
