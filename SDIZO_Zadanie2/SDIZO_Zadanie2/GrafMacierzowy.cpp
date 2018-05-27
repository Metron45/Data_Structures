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
	free(wagi_krawedzi);
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
			dodaj_krawedz(rand() % (ilosc_wierzcholkow - 1), ilosc_wierzcholkow - 1, rand()%10000);
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
		dodaj_krawedz(wierzcholek1, wierzcholek2, rand()%10000);

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

ListaKrawedzi GrafMacierzowy::algorytm_Prima()
{
	return algorytm_Prima(0);
}

ListaKrawedzi GrafMacierzowy::algorytm_Prima(int wierzcholek_poczatkowy)
{
		ListaKrawedzi priorytetowa, koncowa;
		bool * lista_wierzcholkow, *lista_krawedzi, warunek_konca=false;
		int kr_pocz, kr_kon, kr_waga;

		if (wierzcholek_poczatkowy < 0 ||  wierzcholek_poczatkowy >= ilosc_wierzcholkow) {
			std::cout << "Bledny zakres" << std::endl;
			return koncowa;
		}

		//ustalenie tablicy z do sprawdzania warunku konca
		lista_wierzcholkow = (bool*)calloc(ilosc_wierzcholkow, sizeof(bool));
		for (int index = 0; index < ilosc_wierzcholkow; index++) {
			lista_wierzcholkow[index] = false;
		}
		lista_wierzcholkow[wierzcholek_poczatkowy]=true;
		
		lista_krawedzi = (bool*)calloc(ilosc_krawedzi, sizeof(bool));
		for (int index = 0; index < ilosc_krawedzi; index++) {
			lista_krawedzi[index] = false;
		}

		//dodanie krawedzi pierwszego wierzcholka
		for (int index_kr = 0; index_kr < ilosc_krawedzi; index_kr++) {
			if (macierz[wierzcholek_poczatkowy][index_kr] != 0) {
				kr_pocz = wierzcholek_poczatkowy;
				kr_waga = wagi_krawedzi[index_kr];
				for (int index_wr = 1; index_wr < ilosc_wierzcholkow; index_wr++) {
					if (macierz[index_wr][index_kr] != 0) {
						kr_kon = index_wr;
						break;
					}
				}

				lista_krawedzi[index_kr] = true;
				priorytetowa.dodaj_krawedz(kr_pocz, kr_kon, kr_waga);
			}
		}


		while (warunek_konca == false) {
			//znalezienie najmniejszej wagi krawedzi
			kr_kon  = priorytetowa.lista[0].wierzcholek_nastepny;
			kr_pocz = priorytetowa.lista[0].wierzcholek_poprzedni;
			kr_waga = priorytetowa.lista[0].waga;
			for (int index = 0; index < priorytetowa.ilosc_krawedzi; index++) {
				if (kr_waga > priorytetowa.lista[index].waga) {
					kr_kon = priorytetowa.lista[index].wierzcholek_nastepny;
					kr_pocz = priorytetowa.lista[index].wierzcholek_poprzedni;
					kr_waga = priorytetowa.lista[index].waga;
				}
			}
			priorytetowa.usun_krawedz(kr_pocz, kr_kon, kr_waga);
			//dodanie do listy koncowej
			koncowa.dodaj_krawedz(kr_pocz, kr_kon, kr_waga);
			//dodanie wierzcholka
			lista_wierzcholkow[kr_kon] = true;
			//sprawdzenie warunku konca
			warunek_konca = true;
			for (int index = 0; index < ilosc_wierzcholkow; index++) {
				if (!lista_wierzcholkow[index]) {
					warunek_konca = false;
					break;
				}
			}
			if (warunek_konca == true) {
				break;
			}
	
			//dodanie do listy priorytetowej
			for (int index_kr = 0, index_wierzcholka = kr_kon; index_kr < ilosc_krawedzi; index_kr++) {
				if (macierz[index_wierzcholka][index_kr] != 0 && lista_krawedzi[index_kr]==false) {
					kr_pocz = index_wierzcholka;
					kr_waga = wagi_krawedzi[index_kr];
					for (int index_wr = 1; index_wr < ilosc_wierzcholkow; index_wr++) {
						if (macierz[index_wr][index_kr] != 0 && index_wr!=index_wierzcholka) {
							kr_kon = index_wr;
							break;
						}
					}
						lista_krawedzi[index_kr] = true;
						priorytetowa.dodaj_krawedz(kr_pocz, kr_kon, kr_waga);
				}
			}
			if (priorytetowa.lista == NULL) {
				std::cout << "Wystapil blad: Nie mozliwym jest stworzenie drzewa MST" << std::endl;
				break;
			}
		}

	

		return koncowa;	
}

ListaKrawedzi GrafMacierzowy::algorytm_Kruskala()
{
	ListaKrawedzi priorytetowa, koncowa;
	int kr_pocz, kr_kon, kr_waga;
	bool bauble_boost, warunek_konca;
	int * wierzcholki, kolor_wolny, kolor_temp;

	//ustawienie kolejki priorytetowej
	for (int index_krawedzi = 0; index_krawedzi < ilosc_krawedzi; index_krawedzi++) {
		for (int index_w = 0; index_w < ilosc_wierzcholkow; index_w++) {
			if (macierz[index_w][index_krawedzi] == 1) {
				kr_pocz = index_w;
			}
			else if (macierz[index_w][index_krawedzi] == -1) {
				kr_kon = index_w;
			}
		}
		priorytetowa.dodaj_krawedz(kr_pocz, kr_kon, wagi_krawedzi[index_krawedzi]);
	}
	for (int i = 0; i < ilosc_krawedzi; i++) {
		bauble_boost = true;
		for (int j = 0; j < ilosc_krawedzi - i - 1; j++) {
			if (priorytetowa.lista[j].waga > priorytetowa.lista[j + 1].waga) {
				kr_pocz = priorytetowa.lista[j].wierzcholek_poprzedni;
				kr_kon = priorytetowa.lista[j].wierzcholek_nastepny;
				kr_waga = priorytetowa.lista[j].waga;
				priorytetowa.lista[j] = priorytetowa.lista[j + 1];
				priorytetowa.lista[j + 1].wierzcholek_poprzedni = kr_pocz;
				priorytetowa.lista[j + 1].wierzcholek_nastepny = kr_kon;
				priorytetowa.lista[j + 1].waga = kr_waga;
				bauble_boost = false;
			}
		}
		if (bauble_boost == true) {
			break;
		}
	}
	//'kolorowanie' grafu
	kolor_wolny = 0;
	wierzcholki = (int *)calloc(ilosc_wierzcholkow, sizeof(int));
	for (int index = 0; index < ilosc_wierzcholkow; index++) {
		wierzcholki[index] = kolor_wolny;
	}
	kolor_wolny++;
	//Algorytm Kruskala
	warunek_konca = false;
	for (int index_pr = 0; warunek_konca == false; index_pr++) {
		if (index_pr >= ilosc_krawedzi) {
			std::cout << "Nie udalo sie znalesc drzewa MST" << std::endl;
			return koncowa;
		}

		if (wierzcholki[priorytetowa.lista[index_pr].wierzcholek_poprzedni] == 0 && wierzcholki[priorytetowa.lista[index_pr].wierzcholek_nastepny] == 0) {
			wierzcholki[priorytetowa.lista[index_pr].wierzcholek_poprzedni] = kolor_wolny;
			wierzcholki[priorytetowa.lista[index_pr].wierzcholek_nastepny] = kolor_wolny;
			kolor_wolny++;
			koncowa.dodaj_krawedz(priorytetowa.lista[index_pr].wierzcholek_poprzedni, priorytetowa.lista[index_pr].wierzcholek_nastepny, priorytetowa.lista[index_pr].waga);
		}
		else if (wierzcholki[priorytetowa.lista[index_pr].wierzcholek_poprzedni] == 0) {
			wierzcholki[priorytetowa.lista[index_pr].wierzcholek_poprzedni] = wierzcholki[priorytetowa.lista[index_pr].wierzcholek_nastepny];
			koncowa.dodaj_krawedz(priorytetowa.lista[index_pr].wierzcholek_poprzedni, priorytetowa.lista[index_pr].wierzcholek_nastepny, priorytetowa.lista[index_pr].waga);
		}
		else if (wierzcholki[priorytetowa.lista[index_pr].wierzcholek_nastepny] == 0) {
			wierzcholki[priorytetowa.lista[index_pr].wierzcholek_nastepny] = wierzcholki[priorytetowa.lista[index_pr].wierzcholek_poprzedni];
			koncowa.dodaj_krawedz(priorytetowa.lista[index_pr].wierzcholek_poprzedni, priorytetowa.lista[index_pr].wierzcholek_nastepny, priorytetowa.lista[index_pr].waga);
		}
		else if (wierzcholki[priorytetowa.lista[index_pr].wierzcholek_poprzedni] != wierzcholki[priorytetowa.lista[index_pr].wierzcholek_nastepny]) {
			kolor_temp = wierzcholki[priorytetowa.lista[index_pr].wierzcholek_nastepny];
			for (int index = 0; index < ilosc_wierzcholkow; index++) {
				if (wierzcholki[index] == kolor_temp) {
					wierzcholki[index] = wierzcholki[priorytetowa.lista[index_pr].wierzcholek_poprzedni];
				}
			}
			koncowa.dodaj_krawedz(priorytetowa.lista[index_pr].wierzcholek_poprzedni, priorytetowa.lista[index_pr].wierzcholek_nastepny, priorytetowa.lista[index_pr].waga);
		}
		//sprawdzenie warunku konca
		if (wierzcholki[0] > 0) {
			warunek_konca = true;
			kolor_temp = wierzcholki[0];
			for (int index = 1; index < ilosc_wierzcholkow; index++) {
				if (wierzcholki[index] != kolor_temp) {
					warunek_konca = false;
					break;
				}
			}
		}

	}


	return koncowa;
}

ListaKrawedzi GrafMacierzowy::algorytm_Djikstry()
{
	return algorytm_Djikstry(0, ilosc_wierzcholkow - 1);
}

ListaKrawedzi GrafMacierzowy::algorytm_Djikstry(int wierzcholek_poczatkowy, int wierzcholek_szukany) {
	ListaKrawedzi koncowa;
	int *tablica_wag, *tablica_poprzednikow;
	bool warunek_konca = false, *tablica_rozluznionych;
	int wierzcho³ek_obecny;
	int iteracja = 0;

	if (wierzcholek_poczatkowy < 0 || wierzcholek_szukany < 0 || wierzcholek_szukany >= ilosc_wierzcholkow || wierzcholek_poczatkowy >= ilosc_wierzcholkow) {
		std::cout << "Bledny zakres" << std::endl;
		return koncowa;
	}

	tablica_poprzednikow = (int*)calloc(ilosc_wierzcholkow, sizeof(int));
	tablica_wag = (int*)calloc(ilosc_wierzcholkow, sizeof(int));
	tablica_rozluznionych = (bool*)calloc(ilosc_wierzcholkow, sizeof(bool));
	for (int index = 0; index < ilosc_wierzcholkow; index++) {
		tablica_poprzednikow[index] = -1;
		tablica_wag[index] = -1;
		tablica_rozluznionych[index] = false;
		//-1 jest odpowiednikiem NULL i inf
	}
	tablica_wag[wierzcholek_poczatkowy] = 0;
	tablica_poprzednikow[wierzcholek_poczatkowy] = wierzcholek_poczatkowy;

	while (warunek_konca == false) {
		for (int index_wr = 0; index_wr < ilosc_wierzcholkow; index_wr++) {
			if (tablica_poprzednikow[index_wr] != -1 && tablica_rozluznionych[index_wr] == false) {
				for (int nastepny, index_kr = 0; index_kr < ilosc_krawedzi; index_kr++) {
					if (macierz[index_wr][index_kr] == 1) {
						for (int index = 0; index < ilosc_wierzcholkow; index++) {
							if (macierz[index][index_kr] == -1) {
								nastepny = index;
								break;
							}
						}
						if (tablica_wag[nastepny] == -1 || tablica_wag[nastepny] > tablica_wag[index_wr] + wagi_krawedzi[index_kr]) {

							tablica_wag[nastepny] = tablica_wag[index_wr] + wagi_krawedzi[index_kr];
							tablica_poprzednikow[nastepny] = index_wr;

						}
					}
				}
				tablica_rozluznionych[index_wr] = true;
			}
		}


		if (tablica_poprzednikow[wierzcholek_szukany] != -1) {
			warunek_konca = true;
			for (int index = 0; index < ilosc_wierzcholkow; index++) {
				if (tablica_rozluznionych[index] != true && tablica_wag[index] < tablica_wag[wierzcholek_szukany]) {
					warunek_konca = false;
				}
			}
		}
		iteracja++;
		if (iteracja > ilosc_wierzcholkow * 2) {
			std::cout << "Nie udalo sie znalesc sciezki" << std::endl;
			return koncowa;
		}
	}

	wierzcho³ek_obecny = wierzcholek_szukany;
	do {
		koncowa.dodaj_krawedz(tablica_poprzednikow[wierzcho³ek_obecny], wierzcho³ek_obecny, tablica_wag[wierzcho³ek_obecny] - tablica_wag[tablica_poprzednikow[wierzcho³ek_obecny]]);
		wierzcho³ek_obecny = tablica_poprzednikow[wierzcho³ek_obecny];
	} while (wierzcho³ek_obecny != tablica_poprzednikow[wierzcho³ek_obecny]);



	return koncowa;
}

ListaKrawedzi GrafMacierzowy::algorytm_Bellmana()
{
	return algorytm_Bellmana(0, ilosc_wierzcholkow - 1);
}

ListaKrawedzi GrafMacierzowy::algorytm_Bellmana(int wierzcholek_poczatkowy, int wierzcholek_szukany) {

	ListaKrawedzi koncowa;
	int *tablica_wag, *tablica_poprzednikow;

	if (wierzcholek_poczatkowy < 0 || wierzcholek_szukany < 0 || wierzcholek_szukany >= ilosc_wierzcholkow || wierzcholek_poczatkowy >= ilosc_wierzcholkow) {
		std::cout << "Bledny zakres" << std::endl;
		return koncowa;
	}

	tablica_poprzednikow = (int*)calloc(ilosc_wierzcholkow, sizeof(int));
	tablica_wag = (int*)calloc(ilosc_wierzcholkow, sizeof(int));
	for (int index = 0; index < ilosc_wierzcholkow; index++) {
		tablica_poprzednikow[index] = -1;
		tablica_wag[index] = -1;
		//-1 jest odpowiednikiem NULL i inf
	}

	tablica_wag[wierzcholek_poczatkowy] = 0;
	tablica_poprzednikow[wierzcholek_poczatkowy] = wierzcholek_poczatkowy;

	for (int index = 0; index < ilosc_wierzcholkow - 1; index++) {

		for (int nastepny,poprzedni,index_kr = 0; index_kr < ilosc_krawedzi; index_kr++) {

			for (int index = 0; index < ilosc_wierzcholkow; index++) {
				if (macierz[index][index_kr] == -1) {
					nastepny = index;
				}
				else if (macierz[index][index_kr] == 1) {
					poprzedni = index;
				}
			}


			if (tablica_wag[nastepny] == -1 || tablica_wag[nastepny] > tablica_wag[poprzedni] + wagi_krawedzi[index_kr]) {

				tablica_wag[nastepny] = tablica_wag[poprzedni] + wagi_krawedzi[index_kr];
				tablica_poprzednikow[nastepny] = poprzedni;

			}
		}


	}

	int wierzcho³ek_obecny = wierzcholek_szukany;
	do {
		koncowa.dodaj_krawedz(tablica_poprzednikow[wierzcho³ek_obecny], wierzcho³ek_obecny, tablica_wag[wierzcho³ek_obecny] - tablica_wag[tablica_poprzednikow[wierzcho³ek_obecny]]);
		wierzcho³ek_obecny = tablica_poprzednikow[wierzcho³ek_obecny];
	} while (wierzcho³ek_obecny != tablica_poprzednikow[wierzcho³ek_obecny]&& wierzcho³ek_obecny!= -1);
	if (wierzcho³ek_obecny == -1) {
		std::cout << "Nie Powiodlo sie znalezienie sciezki." << std::endl;
	}

	return koncowa;
}

void GrafMacierzowy::test_algorytm_Prima(int rozmiar, float gestosc) {
	int temp;
	std::chrono::high_resolution_clock::time_point clock;
	std::chrono::nanoseconds diff;

	reset();
	stworz_losowe(rozmiar,gestosc);

	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		temp = rand();
		clock = std::chrono::high_resolution_clock::now();
		algorytm_Prima();
		diff = std::chrono::high_resolution_clock::now() - clock;
		std::cout << diff.count() << std::endl;
	}
}

void GrafMacierzowy::test_algorytm_Kruskala(int rozmiar, float gestosc) {
	int temp;
	std::chrono::high_resolution_clock::time_point clock;
	std::chrono::nanoseconds diff;

	reset();
	stworz_losowe(rozmiar, gestosc);

	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		temp = rand();
		clock = std::chrono::high_resolution_clock::now();
		algorytm_Kruskala();
		diff = std::chrono::high_resolution_clock::now() - clock;
		std::cout << diff.count() << std::endl;
	}
}

void GrafMacierzowy::test_algorytm_Djikstry(int rozmiar, float gestosc) {
	int temp;
	std::chrono::high_resolution_clock::time_point clock;
	std::chrono::nanoseconds diff;

	reset();
	stworz_losowe(rozmiar, gestosc);

	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		temp = rand();
		clock = std::chrono::high_resolution_clock::now();
		algorytm_Djikstry();
		diff = std::chrono::high_resolution_clock::now() - clock;
		std::cout << diff.count() << std::endl;
	}
}

void GrafMacierzowy::test_algorytm_Bellmana(int rozmiar, float gestosc) {
	int temp;
	std::chrono::high_resolution_clock::time_point clock;
	std::chrono::nanoseconds diff;

	reset();
	stworz_losowe(rozmiar, gestosc);

	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		temp = rand();
		clock = std::chrono::high_resolution_clock::now();
		algorytm_Bellmana();
		diff = std::chrono::high_resolution_clock::now() - clock;
		std::cout << diff.count() << std::endl;
	}
}