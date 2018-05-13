// SDIZO_Zadanie2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GrafMacierzowy.h"
#include "GrafListowy.h"


int main()
{
	GrafMacierzowy macierz;
	GrafListowy lista;

	lista.wczytaj();
	lista.wypisz();
	
	system("pause");
	return 0;
}

