#include <iostream>
using namespace std;

class Element{
	public:
		Element *nastepny; //wskaznik na nast�pny element
		Element *poprzedni;//wskaznik na poprzedni element
		int klucz;	       //wartosc elementu
		Element();		   //konstruktor
};
