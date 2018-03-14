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
	//funkcje dodawania
	void dodaj_klucz_koniec(int klucz);
	void dodaj_klucz_poczatek(int klucz); 
	void dodaj_klucz_naIndex(int klucz, int index);
	//testowanie funkcji dodawania
	void test_dodaj_klucz_koniec(int rozmiar_struktury);
	void test_dodaj_klucz_poczatek(int rozmiar_struktury);
	void test_dodaj_klucz_index(int rozmiar_struktury);
	
	//funkcje szukaj¹ce klucza
	bool potwierdz_klucz(int klucz);
	int  szukaj_indexKlucza(int klucz);
	int  szukaj_kluczIndexu(int index);
	//funkcje testowe wyszukiwania klucza
	//WIP

	//fuckcje usuwaj¹ce elementy
	void usun_klucz_koniec();
	void usun_klucz_poczatek();
	void usun_klucz_naIndex(int index);
	void usun_klucz(int klucz);
	//fuckje testuj¹ce usuwanie elementów
	//WIP

	//funkcje strukturalne do inicjowania stuktury
	void reset();
	void stworz_losowo(int rozmiar);

public:
	void wypisz();
	
	void menu_stworz();
	void menu_dodaj();
	void menu_usun();
	void menu_szukaj();
	void menu_wczytaj();
	void menu_pomiarowe_dodaj();
	
};

