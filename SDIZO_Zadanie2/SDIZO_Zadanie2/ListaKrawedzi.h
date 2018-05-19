#pragma once
class ListaKrawedzi
{
public:
	ListaKrawedzi();
	~ListaKrawedzi();

	struct krawedz {
		int wierzcholek_nastepny;
		int wierzcholek_poprzedni;
		int waga;
	};
	krawedz * lista;
	int ilosc_krawedzi;

	void dodaj_krawedz(int wierzcholek_poczatku, int wierzchole_konca, int waga);
	void dodaj_krawedz_napoczatek(int wierzcholek_poczatku, int wierzchole_konca, int waga);
	void usun_krawedz(int wierzcholek_poczatku, int wierzchole_konca, int waga);
	void wypisz();
	void reset();
};

