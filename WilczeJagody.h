#pragma once
#include "Roslina.h"
class WilczeJagody : public Roslina
{
public:
	WilczeJagody();
	WilczeJagody(int x, int y, int sila, int wiek);
	~WilczeJagody();

protected:

	//Wilcze Jagody s� truj�ce dla zwierz�t
	//Ka�de zwierze po zjedzeniu umiera
	bool ZjedzenieSmiertelnejRosliny() override;
};