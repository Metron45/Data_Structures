#pragma once
class Tablica
{
private:
		int * wskaznik_tablicy;
		int rozmiar_tablicy;

public:
	Tablica();
	~Tablica();

	void wypisz();

	void dodaj_element_koniec(int element);
	
	void usun_element_koniec();
	void reset();

};

