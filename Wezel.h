#include <iostream>
using namespace std;


class Wezel{
	public:
	  Wezel *rodzic; //wskaznik na rodzica danego w�z�a
	  Wezel *lewy;   // wskaznik na lewego potomka danego wezla
	  Wezel *prawy;  // wskaznik na prawego potomka danego wezla
	  int klucz;     // wartosc w�z�a
	  bool kolor;    // true - czerwony, false - czarny
	  Wezel();       // konstruktor w�z�a

};