#include "Owca.h"

Owca::Owca()
	:Zwierze(OWCA_NAZWA, OWCA_SILA, OWCA_INICJATYWA, OWCA, ZASIEG_RUCHU_DEFAULT)
{
}

Owca::Owca(int x, int y, int sila, int wiek)
	: Zwierze(OWCA_NAZWA, sila, OWCA_INICJATYWA, OWCA, ZASIEG_RUCHU_DEFAULT, wiek, x, y)
{
}

Owca::~Owca()
{
}