#include "stdafx.h"
#include "Lista.h"

Lista::Lista()
{
}

Lista::~Lista()
{
	
}

void Lista::wypisz()
{
	
	if (wskaznik_listy != nullptr) {
		Lista_Dwukierunkowa *wskaznik;
		wskaznik = wskaznik_listy;
		while (wskaznik->nastepny != nullptr)
		{
			std::cout << wskaznik->klucz << " ";
			wskaznik = wskaznik->nastepny;
		}
		std::cout << wskaznik->klucz << " " << std::endl;

		while (wskaznik->poprzedni != nullptr) {
			std::cout << wskaznik->klucz << " ";
			wskaznik = wskaznik->poprzedni;
		}
		std::cout << wskaznik->klucz << " " << std::endl;
	}
}

void Lista::dodaj_klucz_koniec(int klucz)
{
	Lista_Dwukierunkowa * wskaznik, *nowy_element;
	if (wskaznik_listy == nullptr) {
		wskaznik_listy = new Lista_Dwukierunkowa;
		wskaznik_listy->klucz = klucz;
	}
	else {
		wskaznik = wskaznik_listy;
		while (wskaznik->nastepny != nullptr)
		{
			wskaznik = wskaznik->nastepny;
		}
		nowy_element = new Lista_Dwukierunkowa;
		nowy_element->klucz = klucz;
		nowy_element->poprzedni = wskaznik;
		wskaznik->nastepny = nowy_element;
		
	}

}

void Lista::dodaj_klucz_poczatek(int klucz)
{
	
	if (wskaznik_listy != NULL) {
		Lista_Dwukierunkowa *wskaznik;
		wskaznik_listy->poprzedni = new Lista_Dwukierunkowa;
		wskaznik = wskaznik_listy;
		wskaznik_listy = wskaznik->poprzedni;
		wskaznik_listy->klucz = klucz;
		wskaznik_listy->nastepny = wskaznik;
	}
	else {
		wskaznik_listy = new Lista_Dwukierunkowa;
		wskaznik_listy->klucz = klucz;
	}
}

void Lista::dodaj_klucz_poKluczu(int klucz_listy, int klucz_wprowadzany){
	
	if (potwierdz_klucz(klucz_listy)) {
		Lista_Dwukierunkowa * wskaznik, * nowy_element;
		wskaznik = wskaznik_listy;
		while (wskaznik->nastepny != nullptr)
		{
			if (wskaznik->klucz == klucz_listy) {
				break;
			}
			wskaznik = wskaznik->nastepny;
		}
		
		if (wskaznik->nastepny == nullptr) {
			dodaj_klucz_koniec(klucz_wprowadzany);
		}
		else {
			nowy_element = new Lista_Dwukierunkowa;
			nowy_element->klucz = klucz_wprowadzany;
			nowy_element->nastepny = wskaznik->nastepny;
			nowy_element->poprzedni = wskaznik;

			wskaznik->nastepny->poprzedni = nowy_element;
			wskaznik->nastepny = nowy_element;
		}
	}
	else  {
		dodaj_klucz_koniec(klucz_wprowadzany);
	}
}

bool Lista::potwierdz_klucz(int klucz)
{
	if (wskaznik_listy != nullptr) {
		Lista_Dwukierunkowa *wskaznik;
		wskaznik = wskaznik_listy;
		while (wskaznik->nastepny != nullptr){
			if (wskaznik->klucz==klucz){
				return true;
			}
				wskaznik = wskaznik->nastepny;
		} 
		if (wskaznik->klucz == klucz) {
			return true;
		}
	}
	return false;
}

void Lista::usun_klucz_koniec()
{
	Lista_Dwukierunkowa * wskaznik;
	if (wskaznik_listy != nullptr) {

		wskaznik = wskaznik_listy;

		while (wskaznik->nastepny != nullptr)
		{
			wskaznik = wskaznik->nastepny;
		}

		if (wskaznik->poprzedni != nullptr) {
			wskaznik = wskaznik->poprzedni;
			free(wskaznik->nastepny);
			wskaznik->nastepny = nullptr;
		}
		else {
			free(wskaznik_listy);
			wskaznik_listy = nullptr;
		}
		
	}
}

void Lista::usun_klucz_poczatek()
{
	wskaznik_listy = wskaznik_listy->nastepny;
	free(wskaznik_listy->poprzedni);
	wskaznik_listy->poprzedni = nullptr;
}

void Lista::usun_klucz(int klucz)
{
	if (potwierdz_klucz(klucz)) {
		Lista_Dwukierunkowa * wskaznik;
		wskaznik = wskaznik_listy;
		while (wskaznik->nastepny != nullptr)
		{
			if (wskaznik->klucz == klucz) {
				break;
			}
			wskaznik = wskaznik->nastepny;
		}

			wskaznik->poprzedni->nastepny = wskaznik->nastepny;
			wskaznik->nastepny->poprzedni = wskaznik->poprzedni;
			free(wskaznik);
	}
}

void Lista::reset() {
	if (wskaznik_listy != nullptr) {
		Lista_Dwukierunkowa *wskaznik;
		wskaznik = wskaznik_listy;
		while (wskaznik->nastepny != nullptr){
			wskaznik = wskaznik->nastepny;
		}

		while (wskaznik->poprzedni != nullptr) {
			wskaznik = wskaznik->poprzedni;
			free(wskaznik->nastepny);
			wskaznik->nastepny = nullptr;
		}
		free(wskaznik->nastepny);
		wskaznik->nastepny = nullptr;
		free(wskaznik_listy);
		wskaznik_listy = nullptr;
	}
}

void Lista::stworz_losowo(int rozmiar)
{

	if (rozmiar > 0) {
		int i = 0;
		reset();
		srand((int)time(NULL));
		while (i < rozmiar) {
			dodaj_klucz_koniec(rand());
			i++;
		}
	}
}

void Lista::menu_stworz()
{
	int rozmiar;
	printf("\nPodaj liczbe elementow:");
	std::cin >> rozmiar;
	stworz_losowo(rozmiar);
	wypisz();
}

void Lista::menu_dodaj()
{
	int menu, klucz, klucz2;
	printf("\n===Dodaj liczbe===\n");
	printf("0.Na koniec\n");
	printf("1.Na poczatek\n");
	printf("2.Po okreœlonym kluczu\n");
	std::cin >> menu;
	switch (menu)
	{
	case 0:
		printf("podaj liczbe do dodania: ");
		std::cin >> klucz;
		dodaj_klucz_koniec(klucz);
		break;
	case 1:
		printf("podaj liczbe do dodania: ");
		std::cin >> klucz;
		dodaj_klucz_poczatek(klucz);
		break;
	case 2:
		printf("podaj liczbe po ktorej dodac: ");
		std::cin >> klucz2;
		printf("podaj liczbe do dodania: ");
		std::cin >> klucz;
		dodaj_klucz_poKluczu(klucz2,klucz);
		break;
	default:
		break;
	}

	wypisz();
}

void Lista::menu_usun()
{
	int menu, klucz;
	printf("\n===Usun liczbe===\n");
	printf("0.Ostatnia\n");
	printf("1.Pierwsza\n");
	printf("2.Po kluczu\n");
	std::cin >> menu;
	switch (menu)
	{
	case 0:
		usun_klucz_koniec();
		break;
	case 1:
		usun_klucz_poczatek();
		break;
	case 2:
		printf("podaj liczbe do usuniecia: ");
		std::cin >> klucz;
		usun_klucz(klucz);
		break;
	default:
		break;
	}
	wypisz();
}

void Lista::menu_szukaj()
{
	int tmp;
	printf("Podaj liczbe do znalezienia:");
	std::cin >> tmp;
	if (potwierdz_klucz(tmp)) {
		printf("Libcza zosta³a odnaleziona\n");
	}
	else {
		printf("Lista nie posiada takiej liczby.\n");
	}
}

void Lista::menu_wczytaj()
{
	reset();
	std::string name, data;
	std::fstream file;
	printf("Podaj nazwe pliku: ");
	std::cin >> name;
	int quantity, i = 0;


	file.open(name, std::ios::in);
	if (file.is_open())
	{
		getline(file, data);
		quantity = std::stoi(data);

		while (i < quantity)
		{
			std::getline(file, data);
			dodaj_klucz_koniec(std::stoi(data));
			i++;

		}
		file.close();
	}
	else {
		printf("No such file\n");
	}
	wypisz();
}
