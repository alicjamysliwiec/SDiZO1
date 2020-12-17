#include <iostream>
using namespace std;

class Element{
	public:
		Element *nastepny; //wskaznik na nastêpny element
		Element *poprzedni;//wskaznik na poprzedni element
		int klucz;	       //wartosc elementu
		Element();		   //konstruktor
};
