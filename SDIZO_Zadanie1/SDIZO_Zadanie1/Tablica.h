#pragma once
class Tablica
{
private:
		int * wskaznik_tablicy;
		int rozmiar_tablicy;

public:
	Tablica();
	~Tablica();

public:
	void dodaj_klucz_koniec(int klucz);
	void dodaj_klucz_poczatek(int klucz); 
	void dodaj_klucz_naIndex(int klucz, int index);
	
	bool potwierdz_klucz(int klucz);
	int  szukaj_indexKlucza(int klucz);
	int  szukaj_kluczIndexu(int index);
	
	void usun_klucz_koniec();
	void usun_klucz_poczatek();
	void usun_klucz_naIndex(int index);
	void usun_klucz(int klucz);

	void reset();
	void stworz_losowo(int rozmiar);

public:
	void wypisz();
	
	void menu_stworz();
	void menu_dodaj();
	void menu_usun();
	void menu_szukaj();
	void menu_wczytaj();
};

