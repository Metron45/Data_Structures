// SDIZO_Zadanie1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tablica.h"

int main()
{
	Tablica tab;
	tab.dodaj_element_koniec(3);
	tab.dodaj_element_koniec(2);
	tab.dodaj_element_koniec(1);
	tab.wypisz();
	tab.usun_element_koniec();
	tab.dodaj_element_koniec(4);
	tab.dodaj_element_koniec(5);
	tab.wypisz();

	printf("Nacisnij dowolny przycisk");
	getchar();
    return 0;
}

