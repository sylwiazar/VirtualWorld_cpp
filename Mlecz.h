#pragma once
#include "Roslina.h"
class Mlecz: public Roslina
{
public:
	Mlecz();
	Mlecz(int x, int y, int sila, int wiek);
	~Mlecz();

protected:
	//Mlecz podejmuje 3 pr�by rozprzestrzenienia swoich nasion
	bool ZasiejRosline() override;
};

