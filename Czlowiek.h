#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze
{
public:
	Czlowiek();
	Czlowiek(int x, int y, int sila, int wiek);
	~Czlowiek();

protected:

	//Czlowiek, gdy jest wlaczona aktywnosc specjalna
	//przemieszcza sie o 2 miejsca, zamiast 1
	bool Akcja(Dane_o_Swiecie *informacje) override;

	//Sprawdza w paczce danych, czy umiejetnosc jest aktywowana
	//zwraca aktualny zasieg ruchu dla czlowieka
	int SprawdzZasiegRuchu(Dane_o_Swiecie *informacje);

};

