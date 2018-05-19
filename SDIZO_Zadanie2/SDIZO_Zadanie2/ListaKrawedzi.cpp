#include "stdafx.h"
#include "ListaKrawedzi.h"


ListaKrawedzi::ListaKrawedzi()
{
	lista = (krawedz*)calloc(0, sizeof(krawedz));
}


ListaKrawedzi::~ListaKrawedzi()
{
	
}

void ListaKrawedzi::dodaj_krawedz(int wierzcholek_poczatku, int wierzcholek_konca, int waga)
{
	ilosc_krawedzi++;
	lista = (krawedz*)realloc(lista, ilosc_krawedzi * sizeof(krawedz));
	lista[ilosc_krawedzi - 1].waga = waga;
	lista[ilosc_krawedzi - 1].wierzcholek_nastepny = wierzcholek_konca;
	lista[ilosc_krawedzi - 1].wierzcholek_poprzedni = wierzcholek_poczatku;
}

void ListaKrawedzi::dodaj_krawedz_napoczatek(int wierzcholek_poczatku, int wierzcholek_konca, int waga)
{
	ilosc_krawedzi++;
	lista = (krawedz*)realloc(lista, ilosc_krawedzi * sizeof(krawedz));

	for (int i = ilosc_krawedzi - 1; i > 1; i--) {
		lista[i + 1] = lista[i];
	}
	lista[0].waga = waga;
	lista[0].wierzcholek_nastepny = wierzcholek_konca;
	lista[0].wierzcholek_poprzedni = wierzcholek_poczatku;
}

void ListaKrawedzi::usun_krawedz(int wierzcholek_poczatku, int wierzcholek_konca, int waga)
{
	for (int index = 0; index < ilosc_krawedzi; index++) {
		if (lista[index].waga == waga && lista[index].wierzcholek_nastepny == wierzcholek_konca && lista[index].wierzcholek_poprzedni == wierzcholek_poczatku) {
			ilosc_krawedzi--;
			memmove(lista + index, lista + index + 1, (ilosc_krawedzi - index) * sizeof(krawedz));
			lista = (krawedz*)realloc(lista,ilosc_krawedzi*sizeof(krawedz));
			break;
		}
	}
}

void ListaKrawedzi::wypisz()
{
	for (int index = 0; index < ilosc_krawedzi; index++) {
		std::cout
			<< " Od:" << std::setw(3) << lista[index].wierzcholek_poprzedni
			<< " Do:" << std::setw(3) << lista[index].wierzcholek_nastepny
			<< " Waga:" << std::setw(6) << lista[index].waga << std::endl;
	}
}

void ListaKrawedzi::reset()
{
	ilosc_krawedzi = 0;
	lista = (krawedz*)calloc(0, sizeof(krawedz));
}