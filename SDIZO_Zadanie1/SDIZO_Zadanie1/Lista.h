#pragma once
class Lista
{
private:
	struct Lista_Dwukierunkowa
	{
		int klucz;
		Lista_Dwukierunkowa * nastepny = nullptr;
		Lista_Dwukierunkowa * poprzedni = nullptr;
	};

	Lista_Dwukierunkowa * wskaznik_listy;

public:
	Lista();
	~Lista();

	void wypisz();

	void dodaj_klucz_koniec(int klucz);
	void dodaj_klucz_poczatek(int klucz);
	void dodaj_klucz_poKluczu(int klucz_listy, int klucz_wprowadzany);
	
	bool potwierdz_klucz(int klucz);

	void usun_klucz_koniec();
	void usun_klucz_poczatek();
	void usun_klucz(int klucz);

	void reset();
	void stworz_losowo(int rozmiar);

	void menu_stworz();
	void menu_dodaj();
	void menu_usun();
	void menu_szukaj();
	void menu_wczytaj();

};

