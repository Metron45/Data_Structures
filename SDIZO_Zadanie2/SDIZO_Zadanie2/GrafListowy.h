#pragma once
class GrafListowy
{
private:
	
	struct krawedz{
		int wierzcholek_nastepny;
		int wierzcholek_poprzedzajacy;
		int waga;
	};
	
	int ilosc_wierzcholkow;
	int ilosc_krawedzi;
	krawedz * lista;

public:
	GrafListowy();
	~GrafListowy();
	void wypisz();
	void dodaj_wierzcholek();
	void dodaj_krawedz(int wierzcholek_poczatku, int wierzchole_konca, int waga);
	void reset();
	void stworz_minimalne(int rozmiar);
	void stworz_losowe(int rozmiar, float gestosc);
	void wczytaj();
	ListaKrawedzi algorytm_Prima();
	ListaKrawedzi algorytm_Kruskala();
	ListaKrawedzi algorytm_Djikstry(int wierzcholek_poczatkowy, int wierzcholek_szukany);
	ListaKrawedzi algorytm_Bellmana(int wierzcholek_poczatkowy, int wierzcholek_szukany);
};

