#include "stdafx.h"
#include "Tablica.h"



Tablica::Tablica()
{
	wskaznik_tablicy = (int*) calloc(0, sizeof(int));
    rozmiar_tablicy	 = 0;
}

Tablica::~Tablica()
{
	free(wskaznik_tablicy);
}

void Tablica::dodaj_klucz_koniec(int klucz)
{
	rozmiar_tablicy++;
	wskaznik_tablicy = (int*) realloc(wskaznik_tablicy, rozmiar_tablicy*sizeof(int));
	wskaznik_tablicy[rozmiar_tablicy - 1] = klucz;
}

void Tablica::dodaj_klucz_poczatek(int klucz)
{
	rozmiar_tablicy++;
	wskaznik_tablicy = (int*)realloc(wskaznik_tablicy, rozmiar_tablicy * sizeof(int));
	memmove(wskaznik_tablicy + 1, wskaznik_tablicy, (rozmiar_tablicy-1)*sizeof(int));
	*wskaznik_tablicy = klucz;
	
}

void Tablica::dodaj_klucz_naIndex(int klucz, int index)
{
	if (index < rozmiar_tablicy && index >= 0) {
		rozmiar_tablicy++;
		wskaznik_tablicy = (int*)realloc(wskaznik_tablicy, rozmiar_tablicy * sizeof(int));
		memmove(wskaznik_tablicy + index + 1, wskaznik_tablicy + index, (rozmiar_tablicy - 1 - index) * sizeof(int));
		*(wskaznik_tablicy + index) = klucz;
	}
}

void Tablica::test_dodaj_klucz_koniec(int rozmiar_struktury)
{
	int i = 0, temp;
	std::chrono::high_resolution_clock::time_point clock;
	std::chrono::nanoseconds diff;

	reset();
	stworz_losowo(rozmiar_struktury);

	srand(time(NULL));
	while (i < 100)
	{
		temp = rand();

		clock = std::chrono::high_resolution_clock::now();
		dodaj_klucz_koniec(temp);
		diff = std::chrono::high_resolution_clock::now() - clock;
		
		std::cout << diff.count() << std::endl;
		usun_klucz_koniec();
		i++;
	}
}

void Tablica::test_dodaj_klucz_poczatek(int rozmiar_struktury)
{
	int i = 0,temp;
	std::chrono::high_resolution_clock::time_point clock;
	std::chrono::nanoseconds diff;

	reset();
	stworz_losowo(rozmiar_struktury);

	srand(time(NULL));
	while (i < 100)
	{
		temp = rand();

		clock = std::chrono::high_resolution_clock::now();
		dodaj_klucz_poczatek(temp);
		diff = std::chrono::high_resolution_clock::now() - clock;

		std::cout << diff.count() << std::endl;
		usun_klucz_poczatek();
		i++;
	}
}

void Tablica::test_dodaj_klucz_index(int rozmiar_struktury)
{
	int i = 0, quantity, temp, index;
	std::chrono::high_resolution_clock::time_point clock;
	std::chrono::nanoseconds diff;

	reset();
	stworz_losowo(rozmiar_struktury);
	index = rozmiar_struktury / 2;

	srand(time(NULL));
	while (i < 100)
	{
		temp = rand();

		clock = std::chrono::high_resolution_clock::now();
		dodaj_klucz_naIndex(temp,index);
		diff = std::chrono::high_resolution_clock::now() - clock;

		std::cout << diff.count() << std::endl;
		usun_klucz_poczatek();
		i++;
	}
}

bool Tablica::potwierdz_klucz(int klucz)
{
	for (int index_tablicy = 0; index_tablicy < rozmiar_tablicy; index_tablicy++)
	{
		if (*(wskaznik_tablicy+index_tablicy) == klucz)
		{
			return true;
		}
	}
	return false;
}

int Tablica::szukaj_indexKlucza(int klucz)
{
	for (int index_tablicy = 0; index_tablicy < rozmiar_tablicy; index_tablicy++) {
		if (*(wskaznik_tablicy + index_tablicy) == klucz) {
			return index_tablicy;
		}
	}
	return 0;
}

int Tablica::szukaj_kluczIndexu(int index)
{
	if (index > rozmiar_tablicy && index < 0)
		return *(wskaznik_tablicy + index);
}

void Tablica::test_potwierdz_klucz(int rozmiar_struktury)
{
	int i = 0,  temp;
	std::chrono::high_resolution_clock::time_point clock;
	std::chrono::nanoseconds diff;

	reset();
	stworz_losowo(rozmiar_struktury);

	srand(time(NULL));
	while (i < 100)
	{
		temp = rand();

		clock = std::chrono::high_resolution_clock::now();
		potwierdz_klucz(-1);
		diff = std::chrono::high_resolution_clock::now() - clock;

		std::cout << diff.count() << std::endl;
		i++;
	}
}

void Tablica::usun_klucz_koniec()
{
	rozmiar_tablicy--;
	wskaznik_tablicy = (int*)realloc(wskaznik_tablicy, rozmiar_tablicy * sizeof(int));
}

void Tablica::usun_klucz_poczatek()
{
	memmove(wskaznik_tablicy, wskaznik_tablicy+1, (rozmiar_tablicy - 1) * sizeof(int));
	rozmiar_tablicy--;
	wskaznik_tablicy = (int*)realloc(wskaznik_tablicy, rozmiar_tablicy * sizeof(int));
}

void Tablica::usun_klucz_naIndex(int index)
{
	if (index < rozmiar_tablicy && index >= 0) {
		rozmiar_tablicy--;
		memmove(wskaznik_tablicy + index, wskaznik_tablicy + index +1, (rozmiar_tablicy - index) * sizeof(int));
		wskaznik_tablicy = (int*)realloc(wskaznik_tablicy, rozmiar_tablicy * sizeof(int));
	}
}

void Tablica::usun_klucz(int klucz)
{
	if (potwierdz_klucz(klucz)) {
		usun_klucz_naIndex(szukaj_indexKlucza(klucz));
	}
}

void Tablica::test_usun_koniec(int rozmiar_struktury)
{
	int i = 0, temp;
	std::chrono::high_resolution_clock::time_point clock;
	std::chrono::nanoseconds diff;

	reset();
	stworz_losowo(rozmiar_struktury);

	srand(time(NULL));
	while (i < 100)
	{
		temp = rand();

		clock = std::chrono::high_resolution_clock::now();
		usun_klucz_koniec();
		diff = std::chrono::high_resolution_clock::now() - clock;

		std::cout << diff.count() << std::endl;
		dodaj_klucz_koniec(temp);
		i++;
	}
}

void Tablica::test_usun_poczatek(int rozmiar_struktury)
{
	int i = 0, temp;
	std::chrono::high_resolution_clock::time_point clock;
	std::chrono::nanoseconds diff;

	reset();
	stworz_losowo(rozmiar_struktury);

	srand(time(NULL));
	while (i < 100)
	{
		temp = rand();

		clock = std::chrono::high_resolution_clock::now();
		usun_klucz_poczatek();
		diff = std::chrono::high_resolution_clock::now() - clock;

		std::cout << diff.count() << std::endl;
		dodaj_klucz_koniec(temp);
		i++;
	}
}

void Tablica::test_usun_klucz(int rozmiar_struktury)
{
	int i = 0;
	std::chrono::high_resolution_clock::time_point clock;
	std::chrono::nanoseconds diff;

	reset();
	while (i < rozmiar_struktury) {
		dodaj_klucz_koniec(i);
		i++;
	}
	
	i = 0;

	
	while (i < 100)
	{
		

		clock = std::chrono::high_resolution_clock::now();
		usun_klucz(rozmiar_tablicy / 2);
		diff = std::chrono::high_resolution_clock::now() - clock;

		std::cout << diff.count() << std::endl;
		dodaj_klucz_naIndex(rozmiar_tablicy / 2, rozmiar_tablicy / 2);
		i++;
	}
}

void Tablica::reset() {
	rozmiar_tablicy = 0;
	wskaznik_tablicy = (int*)realloc(wskaznik_tablicy, rozmiar_tablicy * sizeof(int));
}
																									//Fukcje publiczne:
void Tablica::wypisz() {
	for (int index_tablicy = 0; index_tablicy < rozmiar_tablicy; index_tablicy++) {
		printf("%i ", wskaznik_tablicy[index_tablicy]);
	}
	printf("\n");
}

void Tablica::stworz_losowo(int rozmiar)
{
	if (rozmiar > 0) {
		reset();
		srand((int)time(NULL));
		while (rozmiar_tablicy < rozmiar) {
			dodaj_klucz_koniec(rand());
		}
	}
}

void Tablica::menu_stworz()
{
	int rozmiar;
	printf("\nPodaj liczbe elementow:");
	std::cin >> rozmiar;
	stworz_losowo(rozmiar); 
	wypisz();
}

void Tablica::menu_dodaj()
{
	int menu,klucz,index;
	printf("\n===Dodaj liczbe===\n");
	printf("0.Na koniec\n");
	printf("1.Na poczatek\n");
	printf("2.Na okreslony index\n");
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
		printf("podaj liczbe do dodania: ");
		std::cin >> klucz;
		printf("\npodaj index liczby dodawanej: ");
		std::cin >> index;
		dodaj_klucz_naIndex(klucz, index);
		break;
	default:
		break;
	}

	wypisz();
}

void Tablica::menu_usun() {
	int menu,tmp;
	printf("\n===Usun liczbe===\n");
	printf("0.Ostatnia\n");
	printf("1.Pierwsza\n");
	printf("2.Po indexie\n");
	printf("3.Po kluczu\n");
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
		printf("podaj index liczby usuwanej:");
		std::cin >> tmp;
		usun_klucz_naIndex(tmp);
		break;
	case 3:
		printf("podaj klucz liczby usuwanej:");
		std::cin >> tmp;
		if (potwierdz_klucz(tmp)) {
			usun_klucz_naIndex(szukaj_indexKlucza(tmp));
		}
		else {
			printf("Tablica nie posiada takiej liczby.\n");
		}
		break;
	default:
		break;
	}
	wypisz();
}

void Tablica::menu_szukaj()
{
	int tmp;
	printf("Podaj liczbe do znalezienia:");
	std::cin >> tmp;
	if (potwierdz_klucz(tmp)) {
		printf("Libcza zosta³a odnaleziona na indexie: %i \n", szukaj_indexKlucza(tmp));
	}
	else{
		printf("Tablica nie posiada takiej liczby.\n");
	}
	
}

void Tablica::menu_wczytaj()
{
	reset();
	std::string name, data;
	std::fstream file;
	printf( "Podaj nazwe pliku: ");
	std::cin >> name;
	int quantity, i = 0;
	

	file.open(name, std::ios::in);
	if (file.is_open())
	{
		//ustalenie iloœci wprowadonych danych
		getline(file, data);
		quantity = std::stoi(data);

		//dodanie do struktury
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

void Tablica::menu_pomiarowe_dodaj()
{
	int menu, rozmiar_struktury;
	printf("\n===Mierz dodawanie liczby===\n");
	printf("0.Na koniec\n");
	printf("1.Na poczatek\n");
	printf("2.Na okreslony index\n");
	std::cin >> menu;
	printf("Podaj rozmiar struktury\n");
	std::cin >> rozmiar_struktury;
	switch (menu)
	{
	case 0:

		test_dodaj_klucz_koniec(rozmiar_struktury);
		break;
	case 1:

		test_dodaj_klucz_poczatek(rozmiar_struktury);
		break;
	case 2:

		test_dodaj_klucz_index(rozmiar_struktury);
		break;
	default:
		break;
	}
}

void Tablica::menu_pomiarowe_szukaj()
{
	int menu, rozmiar_struktury;
	printf("\n===Mierz szukanie liczby===\n");
	printf("Podaj rozmiar struktury\n");
	std::cin >> rozmiar_struktury;
	test_potwierdz_klucz(rozmiar_struktury);
}

void Tablica::menu_pomiarowe_usun()
{
	int menu, rozmiar_struktury;
	printf("\n===Mierz usuwanie liczby===\n");
	printf("0.Na koncu\n");
	printf("1.Na poczatku\n");
	printf("2.Po kluczu\n");
	std::cin >> menu;
	printf("Podaj rozmiar struktury\n");
	std::cin >> rozmiar_struktury;
	switch (menu)
	{
	case 0:

		test_usun_koniec(rozmiar_struktury);
		break;
	case 1:

		test_usun_poczatek(rozmiar_struktury);
		break;
	case 2:

		test_usun_klucz(rozmiar_struktury);
		break;
	default:
		break;
	}
}