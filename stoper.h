
#include <iostream>
#include <Windows.h>

class stoper{
public:
	LARGE_INTEGER performanceCountStart; //zmienna przechowyujaca czas startu 
	LARGE_INTEGER performanceCountEnd;   //zmienna przechowujaca czas zatrzymania
	double	licznik;                     //zmienna przechowujaca czas pomiedzy startem a zatrzymaniem

	LARGE_INTEGER getTime();             //funkcja pobierajaca czas komputera
	void start();                        //funkcja zapisujaca czas startu
	void stop();                         //funkcja zapisujaca czas zakonczenia
	void dodajCzas();                    //funkcja liczaca czas miedzy poczatkiem, a koncem
	void zerujLicznik();                 //funkcja zerujaca licznik
	stoper();                            // konstruktor stopera
	~stoper();                           // destruktor stopera
};