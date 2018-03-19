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

	//dodawanie
	void dodaj_klucz_koniec(int klucz);
	void test_dodaj_klucz_koniec(int rozmiar_struktury);

	void dodaj_klucz_poczatek(int klucz);
	void test_dodaj_klucz_poczatek(int rozmiar_struktury);
	
	void dodaj_klucz_poKluczu(int klucz_listy, int klucz_wprowadzany);
	void test_dodaj_klucz_poKluczu(int rozmiar_struktury);
	
	//szukanie
	bool potwierdz_klucz(int klucz);
	void test_potwierdz_klucz(int rozmiar_struktury);

	//usuwanie
	void usun_klucz_koniec();
	void test_usun_koniec(int rozmiar_struktury);
	
	void usun_klucz_poczatek();
	void test_usun_poczatek(int rozmiar_struktury);
	
	void usun_klucz(int klucz);
	void test_usun_klucz(int rozmiar_struktury);

	void reset();
	void stworz_losowo(int rozmiar);

	//menu
	void menu_stworz();
	void menu_dodaj();
	void menu_usun();
	void menu_szukaj();
	void menu_wczytaj();
	void menu_pomiarowe_dodaj();
	void menu_pomiarowe_szukaj();
	void menu_pomiarowe_usun();

};

