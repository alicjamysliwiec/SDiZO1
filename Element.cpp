#include <iostream>
#include "Element.h"

using namespace std;

	Element::Element(){
		Element::nastepny = NULL;  //domy�lnie wszystkie warto�ci ustawiamy na zero
		Element::poprzedni = NULL;
		Element::klucz = 0;
	};