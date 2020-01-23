#include "Czlowiek.h"
#include <conio.h>

Czlowiek::Czlowiek()
	: Zwierze(CZLOWIEK_NAZWA, CZLOWIEK_SILA, CZLOWIEK_INICJATYWA, CZLOWIEK, ZASIEG_RUCHU_DEFAULT)
{
}

Czlowiek::Czlowiek(int x, int y, int sila, int wiek)
	: Zwierze(CZLOWIEK_NAZWA,sila, CZLOWIEK_INICJATYWA, CZLOWIEK, ZASIEG_RUCHU_DEFAULT, wiek, x, y)
{
}

int Czlowiek::SprawdzZasiegRuchu(Dane_o_Swiecie *informacje)
{
	if (informacje->AktywowanaSpecjalnaUmiejetnosc)
	{
		if (informacje->CzasTrwaniaSpecjalnejUmiejetnosci < 3)
			return 2;
		else
		{
			int szansa = rand() % 100;
			if (szansa < 50)
				return 2;
			else
				return 1;
		}
	}
	else
		return 1;
}

bool Czlowiek::Akcja(Dane_o_Swiecie *informacje)
{
	printf("Wybierz kierunek ruchu dla czlowieka: ");
	unsigned char kierunek;
	int obecny_zasieg_ruchu = SprawdzZasiegRuchu(informacje);
	Wspolrzedne nowa_pozycja = this->GetPozycja();

	while (1)
	{
		kierunek = _getch();
		if (kierunek == 224 || kierunek == 0 ) 
		{
			kierunek = _getch();
			if (kierunek == STRZA£KA_W_GORE)
			{
				if (nowa_pozycja.y - obecny_zasieg_ruchu >= 0)
				{
					nowa_pozycja.y -= obecny_zasieg_ruchu;
					informacje->nowa_pozycja = nowa_pozycja;
					printf("Idz w GORE \n");
					break;
				}
			}
			else if (kierunek == STRZALKA_W_DOL)
			{
				if (nowa_pozycja.y + obecny_zasieg_ruchu < informacje->GetWysokosc())
				{
					nowa_pozycja.y += obecny_zasieg_ruchu;
					informacje->nowa_pozycja = nowa_pozycja;
					printf("Idz w DOL \n");
					break;
				}
			}
			else if (kierunek == STRZALKA_W_PRAWO)
			{
				if (nowa_pozycja.x + obecny_zasieg_ruchu < informacje->GetSzerokosc())
				{
					nowa_pozycja.x += obecny_zasieg_ruchu;
					informacje->nowa_pozycja = nowa_pozycja;
					printf("Idz w PRAWO \n");
					break;
				}
			}
			else if (kierunek == STRZALKA_W_LEWO)
			{
				if (nowa_pozycja.x - obecny_zasieg_ruchu >= 0 )
				{
					nowa_pozycja.x -= obecny_zasieg_ruchu;
					informacje->nowa_pozycja = nowa_pozycja;
					printf("Idz w LEWO \n");
					break;
				}
			}
		}
	}

	if (!informacje->SprawdzCzyPoleJestWolne(nowa_pozycja.x, nowa_pozycja.y))//zajete
	{
		return false;
	}
	else
	{
		informacje->OrganizmAtakujacyDoPrzeniesienia = nowa_pozycja;
		return true;
	}
}

Czlowiek::~Czlowiek()
{
}