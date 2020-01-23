#pragma once
#include "CONST.h"
#include "Dane_o_Swiecie.h"
#include <vector>

class Organizm
{
public:
	Organizm(const std::string &nazwa, const int &sila, const int &inicjatywa, const char &symbol);
	Organizm(const std::string &nazwa, const int &sila, const int &inicjatywa, const char &symbol, int wiek,int x,int y);
	void Rysuj() const; 

	int GetInicjatywa() const; 
	int GetSila() const; 
	int GetWiek() const;
	char GetSymbol() const;
	std::string GetNazwa() const;
	Wspolrzedne GetPozycja() const;

	//true jesli tylko akcja, false jesli wykonala sie kolizja
	virtual bool Akcja(class Dane_o_Swiecie *informacje) = 0;
	virtual void Kolizja(Organizm *organizm, Dane_o_Swiecie *informacje) = 0;

	void SetPozycja(Wspolrzedne pozycja);
	void SetSila(int nowaSila);
	void SetWiek(int wiek);

	virtual void ZwiekszSileZwierzecia(Organizm *org); //true - jeœli zwiêkszy
	virtual bool ZjedzenieSmiertelnejRosliny();
	virtual bool CzyWMomencieAtakuUcieknieNaInneMiejsce();
	virtual bool SprawdzCzyOdbijeAtak(int sila_przeciwnika);
	virtual bool SprawdzCzyZmieniPolozenie(); //true - jeœli zmieni

	~Organizm(); 

protected:

	virtual bool SprawdzCzyOdwazySieWalczycZSilniejszymOrganizmem(int sila_przeciwnika); //true - jesli siê odwa¿y
	virtual void ZabijWszystkieSasiednieOrganizmy(Wspolrzedne pozycja, class Dane_o_Swiecie *informacje);

	//Znajduje wolna, losowa pozycje wokol danego organizmu
	virtual Wspolrzedne ZnajdzPozycjeXOddalonaOdDanegoOrganizmu(Wspolrzedne pozycja, Dane_o_Swiecie *informacje, int zasieg_ruchu);
	//Znajduje jakakolwiek pozycje, moze byc zajeta
	virtual Wspolrzedne WylosujPozycje(Wspolrzedne pozycja, Dane_o_Swiecie *informacje, int zasieg_ruchu);

private:

	int sila; 
	int inicjatywa; 
	int wiek; 
	Wspolrzedne pozycja;
	char symbol;
	std::string nazwa;
};

