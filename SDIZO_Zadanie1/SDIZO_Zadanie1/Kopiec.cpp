#include "stdafx.h"
#include "Kopiec.h"


Kopiec::Kopiec()
{
	wskaznik_kopca = (int*)calloc(0, sizeof(int));
	rozmiar_kopca = 0;
}

Kopiec::~Kopiec()
{
	free(wskaznik_kopca);
}

void Kopiec::dodaj_klucz_koniec(int klucz)
{
	rozmiar_kopca++;
	wskaznik_kopca = (int*)realloc(wskaznik_kopca, rozmiar_kopca * sizeof(int));
	wskaznik_kopca[rozmiar_kopca - 1] = klucz;
}

int Kopiec::szukaj_ojca(int index_syna)
{
	return ( ( index_syna -1 ) / 2 );
}

int Kopiec::szukaj_syna_prawy(int index_ojca)
{
	int index_syna;
	index_syna = 2 * index_ojca + 2;
	if (index_syna >= rozmiar_kopca) {
		return 0;
	}
	else {
		return index_syna;
	}
}

int Kopiec::szukaj_syna_lewy(int index_ojca)
{
	int index_syna;
	index_syna = 2 * index_ojca + 1;
	if (index_syna >= rozmiar_kopca) {
		return 0;
	}
	else {
		return index_syna;
	}
}

void Kopiec::PUSH(int klucz)
{
	dodaj_klucz_koniec(klucz);

	int index, tmp;
	index = rozmiar_kopca-1;

	while (index != 0) {
		if (wskaznik_kopca[szukaj_ojca(index)] < wskaznik_kopca[index])
		{
			tmp = wskaznik_kopca[szukaj_ojca(index)];
			wskaznik_kopca[szukaj_ojca(index)] = wskaznik_kopca[index];
			wskaznik_kopca[index] = tmp;
			index = szukaj_ojca(index);
		}
		else 
		{
			break;
		}
	}
}

void Kopiec::stworz_losowo(int rozmiar)
{
	if (rozmiar > 0) {
		reset();
		srand((int)time(NULL));
		while (rozmiar_kopca < rozmiar) {
			dodaj_klucz_koniec(rand());
		}
	}
}

void Kopiec::usun_klucz_koniec()
{
	rozmiar_kopca--;
	wskaznik_kopca = (int*)realloc(wskaznik_kopca, rozmiar_kopca * sizeof(int));
}

void Kopiec::POP()
{
	wskaznik_kopca[0] = wskaznik_kopca[rozmiar_kopca - 1];
	usun_klucz_koniec();

	int index_ojca = 0, tmp;
	while (szukaj_syna_lewy(index_ojca) != 0 && szukaj_syna_lewy(index_ojca) != 0) {

		if (szukaj_syna_lewy(index_ojca) == 0)
		{
			if (wskaznik_kopca[index_ojca] < wskaznik_kopca[szukaj_syna_prawy(index_ojca)])
			{

				tmp = wskaznik_kopca[index_ojca];
				wskaznik_kopca[index_ojca] = wskaznik_kopca[szukaj_syna_prawy(index_ojca)];
				wskaznik_kopca[szukaj_syna_prawy(index_ojca)] = tmp;
			}
			break;
		}
		else if (szukaj_syna_prawy(index_ojca) == 0)
		{
			if (wskaznik_kopca[index_ojca] < wskaznik_kopca[szukaj_syna_lewy(index_ojca)])
			{
				tmp = wskaznik_kopca[index_ojca];
				wskaznik_kopca[index_ojca] = wskaznik_kopca[szukaj_syna_lewy(index_ojca)];
				wskaznik_kopca[szukaj_syna_lewy(index_ojca)] = tmp;
			}
			break;
		}
		else if (wskaznik_kopca[szukaj_syna_prawy(index_ojca)] < wskaznik_kopca[szukaj_syna_lewy(index_ojca)]) 
		{
			if (wskaznik_kopca[index_ojca] < wskaznik_kopca[szukaj_syna_lewy(index_ojca)])
			{
				tmp = wskaznik_kopca[index_ojca];
				wskaznik_kopca[index_ojca] = wskaznik_kopca[szukaj_syna_lewy(index_ojca)];
				wskaznik_kopca[szukaj_syna_lewy(index_ojca)] = tmp;

				index_ojca = szukaj_syna_lewy(index_ojca);
			}
			else {
				break;
			}
		}
		else if (wskaznik_kopca[szukaj_syna_prawy(index_ojca)] > wskaznik_kopca[szukaj_syna_lewy(index_ojca)]) {

			if (wskaznik_kopca[index_ojca] < wskaznik_kopca[szukaj_syna_prawy(index_ojca)])
			{
				tmp = wskaznik_kopca[index_ojca];
				wskaznik_kopca[index_ojca] = wskaznik_kopca[szukaj_syna_prawy(index_ojca)];
				wskaznik_kopca[szukaj_syna_prawy(index_ojca)] = tmp;

				index_ojca = szukaj_syna_prawy(index_ojca);
			}
			else {
				break;
			}
			
		}

	}

}

void Kopiec::reset()
{
	rozmiar_kopca = 0;
	wskaznik_kopca = (int*)realloc(wskaznik_kopca, rozmiar_kopca * sizeof(int));
}

bool Kopiec::szukaj_klucz(int klucz, int index)
{
	if (wskaznik_kopca[index] == klucz) {
		return true;
	} 
	else if (wskaznik_kopca[index] < klucz) {
		return false;
	}
	else if (szukaj_syna_lewy(index)!=0 && szukaj_klucz(klucz, szukaj_syna_lewy(index))){
		return true;
	}
	else if (szukaj_syna_prawy(index)!=0 && szukaj_klucz(klucz, szukaj_syna_prawy(index))) {
		return true;
	}

	return false;
}

void Kopiec::wypisz()
{
	int *wskaznik;
	wskaznik = wskaznik_kopca;
	std::cout << std::endl;
	for (int i = 0; i < rozmiar_kopca; i++)
	{
		std::cout << *wskaznik << " ";
		wskaznik++;
	}


	std::cout << std::endl;
	std::cout << std::endl;
	int j = 1, rows = 0, width = 0;
	while (j <= rozmiar_kopca)
	{
		j = j * 2;
		rows++;
	}

	j = 0;
	while (j<rows - 1)
	{
		width = width * 2 + 1;
		j++;
	}

	j = 2;
	wskaznik = wskaznik_kopca;
	for (int i = 0; i < rozmiar_kopca; i++)
	{

		if (i == j - 1) {
			std::cout << std::endl;
			j = j * 2;
			width--;
			width = width / 2;

		}

		std::cout << std::setw(width * 4) << "";
		std::cout << std::setw(4) << *wskaznik << std::setw(4) << "";
		std::cout << std::setw(width * 4) << "";
		wskaznik++;
	}
	printf("\n");
}

void Kopiec::menu_dodaj()
{
	int klucz;
	printf("\n===Dodaj liczbe===\n");
	printf("podaj liczbe do dodania: ");
	std::cin >> klucz;
	PUSH(klucz);

	wypisz();
}

void Kopiec::menu_wczytaj()
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
		//ustalenie iloœci wprowadonych danych
		getline(file, data);
		quantity = std::stoi(data);

		//dodanie do struktury
		while (i < quantity)
		{
			std::getline(file, data);
			PUSH(std::stoi(data));
			i++;

		}
		file.close();
	}
	else {
		printf("No such file\n");
	}
	wypisz();
}

void Kopiec::menu_usun()
{
	printf("\n===Dodaj liczbe===\n");
	printf("Jedyna opcja usuwania z kopca to Pop");
	POP();

	wypisz();
}

void Kopiec::menu_szukaj()
{
	int tmp;
	printf("Podaj liczbe do znalezienia:");
	std::cin >> tmp;
	if (szukaj_klucz(tmp,0)) {
		printf("Libcza zosta³a odnaleziona\n");
	}
	else {
		printf("Kopiec nie posiada takiej liczby.\n");
	}
}

void Kopiec::menu_stworz()
{
	int rozmiar;
	printf("\nPodaj liczbe elementow:");
	std::cin >> rozmiar;
	stworz_losowo(rozmiar);
	wypisz();
}

