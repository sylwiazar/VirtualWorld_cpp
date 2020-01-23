#pragma once
#include "Roslina.h"

class BarszczSosnowskiego : public Roslina
{
public:
	
	BarszczSosnowskiego();
	BarszczSosnowskiego(int x, int y, int sila, int wiek);
	~BarszczSosnowskiego();

protected:

	//Barszcz jest truj�cy dla zwierz�t
	//Ka�de zwierze po zjedzeniu umiera
	bool ZjedzenieSmiertelnejRosliny() override;

	//Barszcz atakuje wszystkie s�siednie zwierz�ta zabijaj�c je
	void ZabijWszystkieSasiednieOrganizmy(Wspolrzedne pozycja, Dane_o_Swiecie *informacje) override;
};

