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
	void wypisz();
	void dodaj_wierzcholek();
	void dodaj_krawedz(int wierzcholek_poczatku, int wierzchole_konca, int waga);
	void reset();
	void stworz_minimalne(int rozmiar);
	void stworz_losowe(int rozmiar, float gestosc);
	void wczytaj();
};

