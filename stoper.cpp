#include <iostream>
#include <Windows.h>
#include "stoper.h"
using namespace std;

//konstruktor klasy stoper
stoper::stoper(){
	stoper::licznik=0;
}

//destruktor klasy stoper
stoper::~stoper(){};

//funkcja zwracajaca czas komputera
LARGE_INTEGER stoper::getTime()
{
	LARGE_INTEGER time;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&time);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return time;
}

//funkcja zapisujaca czas startu
void stoper::start(){
	performanceCountStart = getTime();
}

//funkcja zapisujaca czas zakonczenia
void stoper::stop(){
	performanceCountEnd = getTime();
}

//funkcja liczaca czas miedzy poczatkiem, a koncem
void stoper::dodajCzas(){
	licznik += performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
}

//funkcja zerujaca licznik
void stoper::zerujLicznik(){
	licznik = 0;
}
