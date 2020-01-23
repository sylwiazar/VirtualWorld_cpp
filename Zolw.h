#pragma once
#include "Zwierze.h"
class Zolw : public Zwierze
{
public:
	Zolw();
	Zolw(int x, int y, int sila, int wiek);
	~Zolw();

protected:
	//Zolw ma 25% szans na zmiane polozenia
	//W pozosta³ych przypadkach nie rusza sie ze swojego miejsca
	bool SprawdzCzyZmieniPolozenie() override;

	//Zolw potrafi odbic atak przeciwnika, jesli tylko ma sile mniejsza od 4
	bool SprawdzCzyOdbijeAtak(int silaprzeciwnika) override;
};

