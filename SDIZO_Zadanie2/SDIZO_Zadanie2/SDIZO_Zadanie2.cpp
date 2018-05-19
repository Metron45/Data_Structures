// SDIZO_Zadanie2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GrafMacierzowy.h"
#include "GrafListowy.h"


int main()
{
	GrafMacierzowy	macierz;
	GrafListowy		lista;
	ListaKrawedzi	wynik;

	/*
	lista.wczytaj();
	lista.wypisz();
	std::cout << std::endl;
	wynik = lista.algorytm_Bellmana(0,3);
	wynik.wypisz();
	*/

	//macierz.wczytaj();
	macierz.stworz_losowe(6, 0.5);
	macierz.wypisz();
	std::cout << std::endl;
	wynik = macierz.algorytm_Bellmana(0, 5);
	wynik.wypisz();


	system("pause");
	return 0;
}

