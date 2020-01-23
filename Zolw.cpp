#include "Zolw.h"



Zolw::Zolw()
	:Zwierze(ZOLW_NAZWA, ZOLW_SILA, ZOLW_INICJATYWA, ZOLW, ZASIEG_RUCHU_DEFAULT)
{
}

Zolw::Zolw(int x, int y, int sila, int wiek)
	: Zwierze(ZOLW_NAZWA, sila, ZOLW_INICJATYWA, ZOLW, ZASIEG_RUCHU_DEFAULT, wiek, x, y)
{
}

bool Zolw::SprawdzCzyZmieniPolozenie()
{
	if (rand() % 100 < PRAWDOPODOBIENSTWO_ZMIANY_POLOZENIA_ZOLWIA)
		return true;
	else
		return false;
}

bool Zolw::SprawdzCzyOdbijeAtak(int silaprzeciwnika)
{
	if (silaprzeciwnika <= MAKSYMALNA_SILA_PRZECIWNIKA_BY_ZOLW_ODBIL_ATAK)
		return true;
	else
		return false;
}


Zolw::~Zolw()
{
}
