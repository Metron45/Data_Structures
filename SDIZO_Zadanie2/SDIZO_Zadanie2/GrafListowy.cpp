#include "stdafx.h"
#include "GrafListowy.h"


GrafListowy::GrafListowy()
{
	ilosc_krawedzi = 0;
	ilosc_wierzcholkow = 0;
	lista = (krawedz*)calloc(0, sizeof(krawedz));
}


GrafListowy::~GrafListowy()
{
}

void GrafListowy::wypisz()
{
	for (int index = 0; index < ilosc_krawedzi; index++) {
		std::cout 
			<< " Od:" << std::setw(3) << lista[index].wierzcholek_nastepny 
			<< " Do:" << std::setw(3) << lista[index].wierzcholek_poprzedzajacy
			<< " Waga:" << std::setw(6) << lista[index].waga << std::endl;
	}
}

void GrafListowy::dodaj_wierzcholek()
{
	ilosc_wierzcholkow++;
}

void GrafListowy::dodaj_krawedz(int wierzcholek_poczatku, int wierzchole_konca, int waga)
{
	ilosc_krawedzi++;
	lista = (krawedz*)realloc(lista,ilosc_krawedzi*sizeof(krawedz));
	lista[ilosc_krawedzi - 1].waga = waga;
	lista[ilosc_krawedzi - 1].wierzcholek_nastepny = wierzcholek_poczatku;
	lista[ilosc_krawedzi - 1].wierzcholek_poprzedzajacy = wierzchole_konca;
}

void GrafListowy::reset()
{
	ilosc_krawedzi = 0;
	ilosc_wierzcholkow = 0;
	lista = (krawedz*)calloc(0, sizeof(krawedz));
}

void GrafListowy::stworz_minimalne(int rozmiar)
{
	reset();
	srand(time(NULL));
	while (ilosc_wierzcholkow < rozmiar) {
		dodaj_wierzcholek();
		if (ilosc_wierzcholkow > 1) {
			dodaj_krawedz(rand() % (ilosc_wierzcholkow - 1), ilosc_wierzcholkow - 1, rand());
		}
	}
}

void GrafListowy::stworz_losowe(int rozmiar, float gestosc)
{
	srand(time(NULL));
	float gestoscObecna = 0;
	int wierzcholek1, wierzcholek2, iloscKrawedzi;
	stworz_minimalne(rozmiar);
	iloscKrawedzi = ilosc_wierzcholkow - 1;
	gestoscObecna = (float)(2 * iloscKrawedzi) / (float)(ilosc_wierzcholkow*(ilosc_wierzcholkow - 1));

	while (gestoscObecna < gestosc) {
		wierzcholek1 = rand() % ilosc_wierzcholkow;
		do {
			wierzcholek2 = rand() % ilosc_wierzcholkow;
		} while (wierzcholek2 == wierzcholek1);
		dodaj_krawedz(wierzcholek1, wierzcholek2, rand());

		iloscKrawedzi++;
		gestoscObecna = (float)(2 * iloscKrawedzi) / (float)(ilosc_wierzcholkow*(ilosc_wierzcholkow - 1));
	}
}

void GrafListowy::wczytaj()
{
	reset();
	std::string name, input;
	std::fstream file;
	int krawedzie_ilosc, wierzcholki_ilosc;
	int wierzcholek_poczatkowy, wierzcholek_koncowy, waga_krawedzi;

	printf("Podaj nazwe pliku: ");
	std::cin >> name;
	file.open(name, std::ios::in);

	if (file.is_open())
	{
		//ustalenie iloœci wprowadonych danych
		std::getline(file, input, ' ');
		krawedzie_ilosc = std::stoi(input);
		std::getline(file, input);
		wierzcholki_ilosc = std::stoi(input);

		//dodanie wierzcho³ków
		for (int i = 0; i < wierzcholki_ilosc; i++) {
			dodaj_wierzcholek();
		}

		//dodanie krawedzi
		for (int i = 0; i < krawedzie_ilosc; i++) {
			std::getline(file, input, ' ');
			wierzcholek_poczatkowy = std::stoi(input);

			std::getline(file, input, ' ');
			wierzcholek_koncowy = std::stoi(input);

			std::getline(file, input);
			waga_krawedzi = std::stoi(input);

			dodaj_krawedz(wierzcholek_poczatkowy, wierzcholek_koncowy, waga_krawedzi);
		}
		file.close();
	}
	else {
		printf("No such file\n");
	}
}
