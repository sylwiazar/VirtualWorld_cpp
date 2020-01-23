#pragma once
#include "Roslina.h"

class BarszczSosnowskiego : public Roslina
{
public:
	
	BarszczSosnowskiego();
	BarszczSosnowskiego(int x, int y, int sila, int wiek);
	~BarszczSosnowskiego();

protected:

	//Barszcz jest truj¹cy dla zwierz¹t
	//Ka¿de zwierze po zjedzeniu umiera
	bool ZjedzenieSmiertelnejRosliny() override;

	//Barszcz atakuje wszystkie s¹siednie zwierzêta zabijaj¹c je
	void ZabijWszystkieSasiednieOrganizmy(Wspolrzedne pozycja, Dane_o_Swiecie *informacje) override;
};

