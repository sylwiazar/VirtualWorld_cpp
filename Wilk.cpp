#include "Wilk.h"

Wilk::Wilk()
	:Zwierze(WILK_NAZWA, WILK_SILA, WILK_INICJATYWA, WILK, ZASIEG_RUCHU_DEFAULT)
{
}

Wilk::Wilk(int x, int y, int sila, int wiek)
	: Zwierze(WILK_NAZWA, sila, WILK_INICJATYWA, WILK, ZASIEG_RUCHU_DEFAULT, wiek, x,y)
{
}

Wilk::~Wilk()
{
}