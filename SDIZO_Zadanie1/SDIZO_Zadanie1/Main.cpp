// SDIZO_Zadanie1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tablica.h"


int main()
{
	Tablica tablica;
	int menu=0;

	label_TrybPracy:							//menu TrybPracy
	printf("===Wybierz tryb Pracy===\n");
	printf("0.testowy\n");
	printf("1.pomiarowy\n");
	printf("2.zakoncz dzialanie programu\n");
	std::cin >> menu;

	switch(menu){

	case 0:
	label_testowy_Struktura:									//meny wyboru struktury do testów
		printf("===Wybierz Strukture Danych===\n");
		printf("0.Powrot\n");
		printf("1.Tablica\n");
		printf("2.\n");
		printf("3.\n");
		std::cin >> menu;
		switch (menu) {
		case 0:
			goto label_TrybPracy;
		case 1:												//meny testowe tablicy
		label_testowy_Tablica:
			printf("===Tablica_Tesowanie===\n");
			printf("0.Powrot\n");
			printf("1.Wyswietl Strukture\n");
			printf("2.Stworz losowa Strukture\n");
			printf("3.Wczytaj Strukture\n");
			printf("4.Dodaj element\n");
			printf("5.Usun element\n");
			printf("6.Szukaj element\n");
			std::cin >> menu;
			switch (menu) {
			case 0:
				tablica.reset();
				break;
			case 1:
				tablica.wypisz();
				break;
			case 2:
				tablica.menu_stworz();
				break;
			case 3:
				tablica.menu_wczytaj();
				break;
			case 4:
				tablica.menu_dodaj();
				break;
			case 5:
				tablica.menu_usun();
				break;
			case 6:
				tablica.menu_szukaj();
				break;
			default:
				break;
			}
			goto label_testowy_Tablica;
			break;
		case 2:
		label_testowy_ListaDwukierunkowa:					//menu lista dwukierunkowa

			break;
		case 3:
		label_testowy_Kopiec:
		default:
			goto label_testowy_Struktura;
		}
		break;
	case 1:

		break;
	case 2:
		return 0;
		break;
	default:
		goto label_TrybPracy;
	}

	printf("Blad w menu:Nacisnij dowolny przycisk by zakoñczyæ program\n");
	getchar();
    return 0;
}

