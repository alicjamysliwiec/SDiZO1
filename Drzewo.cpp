#include<iostream>
#include <string>
#include "Drzewo.h"

using namespace std;

Drzewo::Drzewo( ){
	straznik.kolor = 0;          // Inicjacja stra¿nika
	straznik.rodzic = &straznik; //przypisanie wlasnosci staraznikowi
	straznik.lewy = &straznik;   //przypisanie wlasnosci staraznikowi
	straznik.prawy = &straznik;  //przypisanie wlasnosci staraznikowi
	korzen = &straznik;          // Korzeñ wskazuje stra¿nika
	gora = 201;  //elementy ramki
	gora += 205; //elementy ramki
	gora += 205; //elementy ramki
	dol = 200;   //elementy ramki
	dol += 205;  //elementy ramki
	dol += 205;  //elementy ramki
	prosto = 186;//elementy ramki
	prosto += ' ';
	prosto += ' ';
}

Drzewo::~Drzewo(){
	usun(korzen);      // Rekurencyjnie usuwamy wêz³y
}

void Drzewo::usun(Wezel *wezel)
{
	if (wezel != &straznik)
	{
		usun(wezel->lewy);  // usuwamy lewe poddrzewo
		usun(wezel->prawy); // usuwamy prawe poddrzewo
		delete[] wezel;     // usuwamy sam wêze³
	}
}

// Wypisuje zawartoœæ drzewa
void Drzewo::wyswietl(Wezel * n, string glowny, char info){
	string tmp;

	//wyswietlanie prawego potmka
	tmp = glowny;
	if (info == 'g') tmp[tmp.length() - 3] = ' ';                    //zastapienie elementu laczacego spacja
	if (n->prawy != &straznik) wyswietl(n->prawy, tmp + prosto, 'g');//przechodzimy do prawego potomka
	tmp = tmp.substr(0, tmp.length() - 3);                           //skraca o 3 linie by sie poprawnie wyswietlo

	cout << tmp;
	if (info == 'g') cout << gora;     //wypisuje elementy laczace do prawego potomka
	else if (info == 'd') cout << dol; //wypisuje elementy laczace do lewego potomka
	if (n->kolor == 0) KOLOR_CZARNY;   // jezeli kolor wezla jest czarny to zmienia kolor wyswietlania na czarny
	else KOLOR_CZERWONY;               // jezeli kolor wezla jest czerwony to zmienia kolor wyswietlania na czerwony
	cout << n->klucz << endl;          //wyswietla wartosc
	KOLOR_NORMALNY;                    //zmien kolor na normalny 

	//wyswietlanie lewego potmkka
	tmp = glowny;
	if (info == 'd') tmp[tmp.length() - 3] = ' ';                   //zastapienie elementu laczacego spacja
	if (n->lewy != &straznik) wyswietl(n->lewy, tmp + prosto, 'd'); //przechodzimy do lewego potomka
	
}


Wezel *Drzewo::wyszukaj(int klucz){
	Wezel *wezel;
	wezel = korzen;
	while( ( wezel != &straznik ) && ( wezel->klucz != klucz ) ) 
		if( klucz < wezel->klucz ) wezel = wezel->lewy; // jezeli podana wartosc jest mniejsza niz klucz wezla, idziemy w 'lewo'
		else  wezel = wezel->prawy;                     // je¿eli jest wiêksza idziemy w 'prawo'
	
	if( wezel == &straznik ) return &straznik; 
	else return wezel;
}

// Usuwa z drzewa wêze³ X
void Drzewo::usun(int n, bool test)
{
	Wezel *X, *Y, *Z;   //X-usuwany wezel, Y wezel na miejsce X, Z wezel na miejsce Y
	X = wyszukaj(n);    //wyszukujemy weze³ o podanym kluczu n
	if (X == &straznik) //je¿eli wêze³ oka¿e sie stra¿nikiem nie mo¿emy go usun¹æ
	{
		cout << "Nie ma takiej liczby w drzewie\n";
	}
	else{
		Y = X; //gdy jeden syn jest straznikiem (gdy obaj nie beda nastopi przypisanie w nastepnym ifie)
		if ((X->lewy != &straznik) && (X->prawy != &straznik)) //jezeli ma obu synow
		{
			//dziedziczy jego nastepnik
			Y = X->prawy;                            // najpierw prawy syn
			while(Y->lewy != &straznik) Y = Y->lewy; //a pozniej najmlodszy lewy potomek (prawego syna)
			X->klucz = Y->klucz;
		}

		
		if (Y->lewy != &straznik) Z = Y->lewy; //jesli X mial tylko lewego potomka wtedy ten potomek zajmie miejsce Y
		else  Z = Y->prawy;                    // jesli X mial prawego potomka to wtedy prawy potomek Y zajmuje miejsce Y
		Z->rodzic = Y->rodzic;                 //Z zajmuje miejsce Y

		if (Y->rodzic == &straznik) korzen = Z;             //jezeli usuwamy korzen
		else if (Y == Y->rodzic->lewy) Y->rodzic->lewy = Z; //jezeli X byl lewym potomkiem
		else Y->rodzic->prawy = Z;                          //jezeli X byl prawym potomek

		if(!test) wyswietl(); //jesli nie do testow to wyswietl nienaprawione drzewo


		if (Y->kolor == 0)   // jesli kolor usuwanego wezla jest czarny to moze wystepowac potrzeba naprawy
		while ((Z != korzen) && (Z->kolor == 0))
		if (Z == Z->rodzic->lewy) //zajmujemy sie lewa strona
		{
			// Przypadek 1 Brat wezla, ktory nie spelnia warunku jest czerwony
			if (Z->rodzic->prawy->kolor == 1)
			{
				Z->rodzic->prawy->kolor = 0;
				Z->rodzic->kolor = 1;
				rotacjaL(Z->rodzic);
			}
			// Przypadek 2 Brat wezla, ktory nie spelnia warunku jest czarny i posiada dwoch czarnych synow
			if ((Z->rodzic->prawy->lewy->kolor == 0) && (Z->rodzic->prawy->prawy->kolor == 0))
			{
				Z->rodzic->prawy->kolor = 1;
				Z = Z->rodzic;
				continue; //problem przesunal sie w gore w drzewie
			}
			// Przypadek 3 Brat wezla ktory nie spelnia warunku jest czarny, jego lewy syn jest czerwony, a prawy czarny
			if (Z->rodzic->prawy->prawy->kolor == 0)
			{
				Z->rodzic->prawy->lewy->kolor = 0;
				Z->rodzic->prawy->kolor = 1;
				rotacjaP(Z->rodzic->prawy);
			}
			// Przypadek 4 Brat wezla, ktory nie spelnia warunku jest czarny a jego prawy syn jest czerwony
			Z->rodzic->prawy->kolor = Z->rodzic->kolor;
			Z->rodzic->kolor = 0;
			Z->rodzic->prawy->prawy->kolor = 0;
			rotacjaL(Z->rodzic);
			break;
		}
		else // Przypadki symetryczne, zajmujemy sie prawa strona
		{
			// Przypadek 1 Brat wezla, ktory nie spelnia warunku jest czerwony
			if (Z->rodzic->lewy->kolor == 1)
			{
				Z->rodzic->lewy->kolor = 0;
				Z->rodzic->kolor = 1;
				rotacjaP(Z->rodzic);
			}
			// Przypadek 2  Brat wezla, ktory nie spelnia warunku jest czarny i posiada dwoch czarnych synow
			if ((Z->rodzic->lewy->lewy->kolor == 0) && (Z->rodzic->lewy->prawy->kolor == 0))
			{
				Z->rodzic->lewy->kolor = 1;
				Z = Z->rodzic;
				continue;
			}
			// Przypadek 3 Brat wezla ktory nie spelnia warunku jest czarny, jego prawy syn jest czerwony, a lewy czarny
			if (Z->rodzic->lewy->lewy->kolor == 0)
			{
				Z->rodzic->lewy->prawy->kolor = 0;
				Z->rodzic->lewy->kolor = 1;
				rotacjaL(Z->rodzic->lewy);
			}
			// Przypadek 4  Brat wezla, ktory nie spelnia warunku jest czarny a jego lewy syn jest czerwony
			Z->rodzic->lewy->kolor = Z->rodzic->kolor;
			Z->rodzic->kolor = 0;
			Z->rodzic->lewy->lewy->kolor = 0;
			rotacjaP(Z->rodzic);
			break;
		}
		Z->kolor = 0;
		delete Y;
	}
}

// Wykonuje rotacjê w lewo wzglêdem Obracany
void Drzewo::rotacjaL(Wezel * O)
{
	Wezel *P = O->prawy;  //P - prawy potomek obracanego
	Wezel *R = O->rodzic; //R - rodzic obracanego

	O->prawy = P->lewy;
	if (O->prawy != &straznik) O->prawy->rodzic = O; //jezeli lewy potomek X nie byl straznikiem to nadajemy mu rodzica

	P->lewy = O;
	P->rodzic = R;
	O->rodzic = P;

	if (R != &straznik) //sprawdza czy B nie bylo korzeniem (tylko korzen ma rodzica straznika
	{
		//sprawdzenie ktorym potomkiem bylo B (lewym czy prawym)
		if (R->lewy == O) R->lewy = P; 
		else R->prawy = P;
	}
	else korzen = P;
}

// Wykonuje rotacjê w prawo wzglêdem Obracany
void Drzewo::rotacjaP(Wezel * O)
{
	Wezel *L = O->lewy;   // L - lewy potomek obracanego
	Wezel *R = O->rodzic; //R - rodzic obracanego

	O->lewy = L->prawy;
	if (O->lewy != &straznik) O->lewy->rodzic = O; //jezeli prawy potomek X nie byl straznikiem to nadajemy mu rodzica

	L->prawy = O;
	L->rodzic = R;
	O->rodzic = L;

	if (R != &straznik) //sprawdza czy B nie bylo korzeniem (tylko korzen ma rodzica straznika)
	{
		//sprawdzenie ktorym potomkiem bylo B (lewym czy prawym)
		if (R->lewy == O) R->lewy = L;
		else R->prawy = L;
	}
	else korzen = L;
}

void Drzewo::wyswietl() {
	if (korzen!=&straznik)wyswietl(korzen);
	else cout << "Drzewo jest puste\n";
}


void Drzewo::wczytaj(fstream plik)
{
	usun(korzen);
	korzen = &straznik;
	int rozmiar, klucz;
	plik >> rozmiar;    //wczytanie rozmiaru drzewa

	for (int i = 0; i < rozmiar; i++)
	{
		plik >> klucz;
		naprawa(dodaj(klucz)); //dodawanie do drzewa
	}
	cout << "\nDrzewo zostalo poprawnie wczytane.\n";

}

//do testow
void Drzewo::wygeneruj(int liczba){
	usun(korzen);
	korzen = &straznik;
	for (int i = 0; i < liczba; i++)
	{
		naprawa(dodaj(i - liczba / 2));
	}
}

//do wyswietlania
void Drzewo::wygenerujLosowo(int liczba) {
	usun(korzen);
	korzen = &straznik;
	for (int i = 0; i < liczba; i++)
	{
		naprawa(dodaj(rand()));
	}
}

Wezel* Drzewo::dodaj(int klucz)
{
	Wezel *X = new Wezel;
	X->klucz = klucz;
	X->lewy = &straznik;     // Inicjujemy pola
	X->prawy = &straznik;
	X->rodzic = korzen;
	if (X->rodzic == &straznik) korzen = X; // jezeli nie ma jeszcze korzenia to X staje siê korzeniem
	else
	{
		do
		{
			if (X->klucz < X->rodzic->klucz)      //sprawdza, w ktora strone ma sie przesunac
			{
				if (X->rodzic->lewy == &straznik) //dopoki nie napotka straznika
				{
					X->rodzic->lewy = X;          // X zastêpuje lewy liœæ
					break;
				}
				X->rodzic = X->rodzic->lewy;      //przechodzimy do nastepnego lewego potomka
			}
			else
				{
				if (X->rodzic->prawy == &straznik)
				{
					X->rodzic->prawy = X;     // X zastêpuje prawy liœæ
					break;
				}
				X->rodzic = X->rodzic->prawy; //przechodzimy do nastepnego prawego potomka
			}
		} while (true);  // Szukamy liœcia do zast¹pienia przez X
		X->kolor = 1;    // Wêze³ kolorujemy na czerwono, by liczba wezlow czarnych od korzenia sie zgadzala
	}
	return X;
}

void Drzewo::naprawa(Wezel *X) //naprawia po dodaniu/usunieciu wezla
{
	Wezel *Y;
	//naprawa
	//Sprawdzanie przypadkow
	while ((X != korzen) && (X->rodzic->kolor == 1))
	{
		if (X->rodzic == X->rodzic->rodzic->lewy) //przypadki gdy rodzic X jest lewym dzieckiem swojego rodzica
		{
			Y = X->rodzic->rodzic->prawy;         // Y to wujek X

			if (Y->kolor == 1)                    // Przypadek 1 Wujek X-a jest czerwony
			{
				X->rodzic->kolor = 0;
				Y->kolor = 0;
				X->rodzic->rodzic->kolor = 1;
				X = X->rodzic->rodzic;
			}
			else
			{
				if (X == X->rodzic->prawy) // Przypadek 2 Wujek X-a jest czarny, a X jest prawym dzieckiem swojego rodzica
				{
					X = X->rodzic;
					rotacjaL(X);
				}

				X->rodzic->kolor = 0;     // Przypadek 3 Wujek X-a jest czarny, a X jest lewym dzieckiem swojego rodzica
				X->rodzic->rodzic->kolor = 1;
				rotacjaP(X->rodzic->rodzic);
				break;
			}
		}
		else // Przypadki symetryczne (gdy rodzic X jest prawym dzieckiem swojego rodzica)
		{
			Y = X->rodzic->rodzic->lewy; // Y to wujek X
			if (Y->kolor == 1)           // Przypadek 1 Wujek X-a jest czerwony
			{
				X->rodzic->kolor = 0;
				Y->kolor = 0;
				X->rodzic->rodzic->kolor = 1;
				X = X->rodzic->rodzic;
			}
			else
			{
				if (X == X->rodzic->lewy) // Przypadek 2 Wujek X-a jest czarny, a X jest lewym dzieckiem swojego rodzica
				{
					X = X->rodzic;
					rotacjaP(X);
				}
				X->rodzic->kolor = 0;     // Przypadek 3 Wujek X-a jest czarny, a X jest prawym dzieckiem swojego rodzica
				X->rodzic->rodzic->kolor = 1;
				rotacjaL(X->rodzic->rodzic);
				break;
			}
		}
	}
	korzen->kolor = 0;
}