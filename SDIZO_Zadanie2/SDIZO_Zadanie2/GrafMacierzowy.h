#pragma once

class GrafMacierzowy
{
private:
	int **macierz;
	int *wagi_krawedzi;
	int ilosc_wierzcholkow;
	int ilosc_krawedzi;
public:
	GrafMacierzowy();
	~GrafMacierzowy();
protected:
	void dodaj_wierzcholek();
	void dodaj_krawedz(int wierzcholek_poczatku, int wierzchole_konca, int waga);
	void reset();
	void stworz_minimalne(int rozmiar);
public:
	void wypisz();
	void stworz_losowe(int rozmiar, float gestosc);
	void wczytaj();
	ListaKrawedzi algorytm_Prima();
	ListaKrawedzi algorytm_Prima(int wierzcholek_poczatkowy);
	ListaKrawedzi algorytm_Kruskala();
	ListaKrawedzi algorytm_Djikstry();
	ListaKrawedzi algorytm_Djikstry(int wierzcholek_poczatkowy, int wierzcholek_szukany);
	ListaKrawedzi algorytm_Bellmana();
	ListaKrawedzi algorytm_Bellmana(int wierzcholek_poczatkowy, int wierzcholek_szukany);
	void test_algorytm_Prima(int rozmiar, float gestosc);
	void test_algorytm_Kruskala(int rozmiar, float gestosc);
	void test_algorytm_Djikstry(int rozmiar, float gestosc);
	void test_algorytm_Bellmana(int rozmiar, float gestosc);
};

