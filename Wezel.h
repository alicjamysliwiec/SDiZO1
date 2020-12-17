#include <iostream>
using namespace std;


class Wezel{
	public:
	  Wezel *rodzic; //wskaznik na rodzica danego wêz³a
	  Wezel *lewy;   // wskaznik na lewego potomka danego wezla
	  Wezel *prawy;  // wskaznik na prawego potomka danego wezla
	  int klucz;     // wartosc wêz³a
	  bool kolor;    // true - czerwony, false - czarny
	  Wezel();       // konstruktor wêz³a

};