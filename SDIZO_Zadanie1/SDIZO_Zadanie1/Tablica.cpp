#include "stdafx.h"
#include "Tablica.h"


Tablica::Tablica()
{
	wskaznik_tablicy = new int;
    rozmiar_tablicy	 = 0;
}


Tablica::~Tablica()
{
	delete wskaznik_tablicy;
}

void Tablica::wypisz() {
	
	for (int index_tablicy = 0; index_tablicy < rozmiar_tablicy; index_tablicy++) {
		printf("%i ", (int)*(wskaznik_tablicy+index_tablicy));
	}
	printf("\n");
}

void Tablica::dodaj_element_koniec(int element)
{
	*(wskaznik_tablicy + rozmiar_tablicy) = element;
	rozmiar_tablicy++;
}



void Tablica::usun_element_koniec()
{
	delete (wskaznik_tablicy + (rozmiar_tablicy - 1));
	rozmiar_tablicy --;
}

void Tablica::reset() {
	
}


