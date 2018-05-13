#include "stdafx.h"
#include "GrafMacierzowy.h"


GrafMacierzowy::GrafMacierzowy()
{
	ilosc_wierzcholkow = 0;
	ilosc_krawedzi = 0;
	macierz = (int**)calloc(0, sizeof(int));
	wagi_krawedzi = (int*)calloc(0, sizeof(int));
}

GrafMacierzowy::~GrafMacierzowy()
{
	free(macierz);
}

void GrafMacierzowy::wypisz()
{
	std::cout << "Waga: ";
	for (int index = 0; index < ilosc_krawedzi; index++) {
		std::cout << std::setw(6) << wagi_krawedzi[index];
	}
	std::cout << std::endl;

	for (int index = 0; index < ilosc_wierzcholkow; index++) {
		std::cout << std::setw(4) << index << ": ";
		for (int indexWiersza = 0; indexWiersza < ilosc_krawedzi; indexWiersza++)
		{
			std::cout << std::setw(6) << macierz[index][indexWiersza];
		}
		std::cout << std::endl;
	}
}

void GrafMacierzowy::dodaj_wierzcholek()
{
		ilosc_wierzcholkow++;
		macierz = (int **)realloc(macierz, ilosc_wierzcholkow * sizeof(int));
		
		macierz[ilosc_wierzcholkow - 1] = (int *)calloc(ilosc_krawedzi, sizeof(int));
		for (int i = 0 ; i < ilosc_krawedzi; i++) {
			macierz[ilosc_wierzcholkow - 1][i] = 0;
		}
}

void GrafMacierzowy::dodaj_krawedz(int wierzcholek_poczatku, int wierzcholek_konca, int waga)
{
	if (wierzcholek_poczatku < ilosc_wierzcholkow && wierzcholek_konca < ilosc_wierzcholkow) {
		ilosc_krawedzi++;

		for (int i = 0; i < ilosc_wierzcholkow; i++) {
			macierz[i] = (int*)realloc(macierz[i],ilosc_krawedzi*sizeof(int));
			macierz[i][ilosc_krawedzi - 1] = 0;
		}

		wagi_krawedzi = (int*)realloc(wagi_krawedzi, ilosc_krawedzi * sizeof(int));
		wagi_krawedzi[ilosc_krawedzi - 1] = waga;
		macierz[wierzcholek_poczatku][ilosc_krawedzi - 1] = 1;
		macierz[wierzcholek_konca][ilosc_krawedzi - 1] = -1;
	}
}

void GrafMacierzowy::reset()
{
	ilosc_wierzcholkow = 0;
	ilosc_krawedzi = 0;
	macierz = (int**)calloc(0, sizeof(int));
	wagi_krawedzi = (int*)calloc(0, sizeof(int));
}

void GrafMacierzowy::stworz_minimalne(int rozmiar)
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

void GrafMacierzowy::stworz_losowe(int rozmiar, float gestosc)
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

void GrafMacierzowy::wczytaj()
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
		for (int i = 0; i < wierzcholki_ilosc;i++) {
			dodaj_wierzcholek();
		}

		//dodanie krawedzi
		for(int i = 0 ; i < krawedzie_ilosc; i++) {
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

