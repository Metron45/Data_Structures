#pragma once
class Kopiec
{
private:

	int * wskaznik_kopca;
	int rozmiar_kopca;



public:
	Kopiec();
	~Kopiec();



protected:

	void dodaj_klucz_koniec(int klucz);

	int  szukaj_ojca(int index_syna);
	int	 szukaj_syna_prawy(int index_ojca);
	int	 szukaj_syna_lewy(int index_ojca);


	void PUSH(int klucz);

	

	void stworz_losowo(int rozmiar);

	void usun_klucz_koniec();
	void POP();

	
	

	bool szukaj_klucz(int klucz, int index);

	
public:
	void test_szukaj();
	void test_push();
	void test_pop();

public:
	void reset();
	bool szukaj_klucz(int klucz);
	void wypisz();
	void menu_dodaj();
	void menu_wczytaj();
	void menu_usun();
	void menu_szukaj();
	void menu_stworz();
};

