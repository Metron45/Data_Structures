// SDIZO_Zadanie2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GrafMacierzowy.h"
#include "GrafListowy.h"
void menu_testowe();
void menu_pomiarowe();

int main()
{
	int menu;
	std::cout << "Wybierz dzialanie programu:" << std::endl;
	std::cout << "1.testowanie algorytmow" << std::endl;
	std::cout << "2.przeprowadzanie pomiarow" << std::endl;
	std::cin >> menu;
	switch (menu)
	{
	default:
		break;
	case 1:
		menu_testowe();
		break;
	case 2:
		menu_pomiarowe();
		break;
	}
	system("pause");
	return 0;
}

void menu_pomiarowe() {
	GrafMacierzowy	macierz;
	GrafListowy		lista;
	int struktura, algorytm, rozmiar;
	float gestosc;
	do {
		std::cout << "Menu Pomiarowe: " << std::endl;
		std::cout << "0: Powtor " << std::endl;
		std::cout << "1: Testowanie Macierzowego " << std::endl;
		std::cout << "2: Testowanie Listowego " << std::endl;
		std::cin >> (int)struktura;
		if (struktura != 0) {
			if (struktura == 1) {
				std::cout << "Menu Pomiarowe:: Graf Macierzowy " << std::endl;
			}
			else if (struktura == 2) {
				std::cout << "Menu Pomiarowe:: Graf Listowy " << std::endl;
			}
			std::cout << "0: Powtor " << std::endl;
			std::cout << "1: Prima " << std::endl;
			std::cout << "2: Kruskala" << std::endl;
			std::cout << "3: Djikstry" << std::endl;
			std::cout << "4: Bellmana" << std::endl;
			std::cin >> (int)algorytm;

			if (algorytm != 0) {
				std::cout << "Podaj rozmiar: ";
				std::cin >> rozmiar;
				std::cout << "Podaj gestosc: ";
				std::cin >> gestosc;

				switch (algorytm)
				{
				default:
					break;
				case 1:
					if (struktura == 1) {
						macierz.test_algorytm_Prima(rozmiar, gestosc);
					}
					else if (struktura == 2) {
						lista.test_algorytm_Prima(rozmiar, gestosc);
					}
					break;
				case 2:
					if (struktura == 1) {
						macierz.test_algorytm_Kruskala(rozmiar, gestosc);
					}
					else if (struktura == 2) {
						lista.test_algorytm_Kruskala(rozmiar, gestosc);
					}
					break;
				case 3:
					if (struktura == 1) {
						macierz.test_algorytm_Djikstry(rozmiar, gestosc);
					}
					else if (struktura == 2) {
						lista.test_algorytm_Djikstry(rozmiar, gestosc);
					}
					break;
				case 4:
					if (struktura == 1) {
						macierz.test_algorytm_Bellmana(rozmiar, gestosc);
					}
					else if (struktura == 2) {
						lista.test_algorytm_Bellmana(rozmiar, gestosc);
					}
					break;
				}

			}
		}
	} while (struktura != 0);
}

void menu_testowe() {
	GrafMacierzowy	macierz;
	GrafListowy		lista;
	ListaKrawedzi	wynik;
	int struktura,metoda;
	int rozmiar,pocz,kon; float gestosc;
	do {
		std::cout << "Menu Testowe: " << std::endl;
		std::cout << "0: Powtor " << std::endl;
		std::cout << "1: Testowanie Macierzowego " << std::endl;
		std::cout << "2: Testowanie Listowego " << std::endl;
		std::cin >> struktura;

		if (struktura != 0) {
			do {
				if (struktura == 1) {
					std::cout << "Menu Testowe:: Graf Macierzowy " << std::endl;
				}
				else if (struktura == 2) {
					std::cout << "Menu Testowe:: Graf Listowy " << std::endl;
				}

				std::cout << "0: Powtor " << std::endl;
				std::cout << "1: Wczytaj " << std::endl;
				std::cout << "2: Stworz losowe" << std::endl;
				std::cout << "3: Wyswietl" << std::endl;
				std::cout << "4: Prima " << std::endl;
				std::cout << "5: Kruskala" << std::endl;
				std::cout << "6: Djikstry" << std::endl;
				std::cout << "7: Bellmana" << std::endl;
				std::cin >> metoda;

				switch (metoda)
				{
				default:
				case 0:
					break;
				case 1:
					if (struktura == 1) {
						macierz.wczytaj();
						macierz.wypisz();
					}
					else if (struktura == 2) {
						lista.wczytaj();
						lista.wypisz();
					}
					break;

				case 2:
					std::cout << "Podaj rozmiar: ";
					std::cin >> rozmiar;
					std::cout << "Podaj gestosc: ";
					std::cin >> gestosc;
					if (struktura == 1) {
						macierz.stworz_losowe(rozmiar, gestosc);
						macierz.wypisz();
					}
					else if (struktura == 2) {
						lista.stworz_losowe(rozmiar, gestosc);
						lista.wypisz();
					}
					break;
				case 3:
					if (struktura == 1) {
						macierz.wypisz();
					}
					else if (struktura == 2) {
						lista.wypisz();
					}
					break;
				case 4:
					std::cout << "Podaj poczatek: ";
					std::cin >> pocz;
					if (struktura == 1) {
						wynik = macierz.algorytm_Prima(pocz);
					}
					else if (struktura == 2) {
						wynik = lista.algorytm_Prima(pocz);
					}
					wynik.wypisz();
					break;
				case 5:
					if (struktura == 1) {
						wynik = macierz.algorytm_Kruskala();
					}
					else if (struktura == 2) {
						wynik = lista.algorytm_Kruskala();
					}
					wynik.wypisz();
					break;
				case 6:
					std::cout << "Podaj poczatek: ";
					std::cin >> pocz;
					std::cout << "Podaj koniec: ";
					std::cin >> kon;
					if (struktura == 1) {
						wynik = macierz.algorytm_Djikstry(pocz, kon);
					}
					else if (struktura == 2) {
						wynik = lista.algorytm_Djikstry(pocz, kon);
					}
					wynik.wypisz();
					break;

				case 7:
					std::cout << "Podaj poczatek: ";
					std::cin >> pocz;
					std::cout << "Podaj koniec: ";
					std::cin >> kon;
					if (struktura == 1) {
						wynik = macierz.algorytm_Bellmana(pocz, kon);
					}
					else if (struktura == 2) {
						wynik = lista.algorytm_Bellmana(pocz, kon);
					}
					wynik.wypisz();
					break;
				}
			} while (metoda != 0);
		}
	}while (struktura != 0);
}