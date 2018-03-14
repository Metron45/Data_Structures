// SDIZO_Zadanie1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tablica.h"
#include "Lista.h"
#include "Kopiec.h"


int main()
{
	Tablica tablica;
	Lista lista;
	Kopiec kopiec;
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
		printf("2.Lista Dwukierunkowa\n");
		printf("3.Kopiec\n");
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
			printf("===Lista Testowanie===\n");
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
				lista.reset();
				goto label_testowy_Struktura;
			case 1:
				lista.wypisz();
				goto label_testowy_ListaDwukierunkowa;
			case 2:
				lista.menu_stworz();
				goto label_testowy_ListaDwukierunkowa;
			case 3:
				lista.menu_wczytaj();
				goto label_testowy_ListaDwukierunkowa;
			case 4:
				lista.menu_dodaj();
				goto label_testowy_ListaDwukierunkowa;
			case 5:
				lista.menu_usun();
				goto label_testowy_ListaDwukierunkowa;
			case 6:
				lista.menu_szukaj();
				goto label_testowy_ListaDwukierunkowa;
			default:
				break;
			}
			
			break;

		case 3:
		label_testowy_Kopiec:						//menu testowe Kopca
			printf("===Kopiec Testowanie===\n");
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
				kopiec.reset();
				goto label_testowy_Struktura;
			case 1:
				kopiec.wypisz();
				goto label_testowy_Kopiec;
			case 2:
				kopiec.menu_stworz();
				goto label_testowy_Kopiec;
			case 3:
				kopiec.menu_wczytaj();
				goto label_testowy_Kopiec;
			case 4:
				kopiec.menu_dodaj();
				goto label_testowy_Kopiec;
			case 5:
				kopiec.menu_usun();
				goto label_testowy_Kopiec;
			case 6:
				kopiec.menu_szukaj();
				goto label_testowy_Kopiec;
			default:
				goto label_testowy_Kopiec;
			}

		default:
			goto label_testowy_Kopiec;
		}
		break;

	case 1:
	label_pomiarowy_Struktura:									//meny wyboru struktury do pomiarów
		printf("===Wybierz Strukture Danych do pomiarow===\n");
		printf("0.Powrot\n");
		printf("1.Tablica\n");
		printf("2.Lista Dwukierunkowa\n");
		printf("3.Kopiec\n");
		std::cin >> menu;

		switch (menu) {
		case 0: 
			goto label_pomiarowy_Struktura;
		case 1:					//menu wybory pomiarów na tablicy		
			label_pomiarowy_Tablica:
			printf("===Tablica_Pomiary===\n");
			printf("0.Powrot\n");
			printf("1.Dodaj element\n");
			printf("2.Usun element\n");
			printf("3.Szukaj element\n");
			std::cin >> menu;
			switch (menu) {
			case 0:
				tablica.reset();
				break;
			case 1:
				tablica.menu_pomiarowe_dodaj();
				break;
			case 2:
				tablica.menu_stworz();
				break;
			case 3:
				tablica.menu_wczytaj();
				break;

			default:
				break;
			}
			goto label_pomiarowy_Tablica;



		default:
			goto label_TrybPracy;
		}


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

