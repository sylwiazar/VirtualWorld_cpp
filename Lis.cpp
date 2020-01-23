#include "Lis.h"

Lis::Lis()
	:Zwierze(LIS_NAZWA, LIS_SILA, LIS_INICJATYWA, LIS, ZASIEG_RUCHU_DEFAULT)
{
}

Lis::Lis(int x, int y, int sila, int wiek)
	: Zwierze(LIS_NAZWA, sila, LIS_INICJATYWA, LIS, ZASIEG_RUCHU_DEFAULT, wiek, x, y)
{
}

bool Lis::SprawdzCzyOdwazySieWalczycZSilniejszymOrganizmem(int sila_przeciwnika)
{
	if (sila_przeciwnika > this->GetSila())
		return false;
	else
		return true;
}


Lis::~Lis()
{
}
