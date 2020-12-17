#include <iostream>
#include "Element.h"

using namespace std;

	Element::Element(){
		Element::nastepny = NULL;  //domyœlnie wszystkie wartoœci ustawiamy na zero
		Element::poprzedni = NULL;
		Element::klucz = 0;
	};