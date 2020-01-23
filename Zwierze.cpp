#include "Zwierze.h"
#include "Zwierzeta.h"
#include "Roslina.h"

Zwierze::Zwierze(const std::string & nazwa, const int & sila, const int & inicjatywa, const char & symbol, const int &zasieg_ruchu)
	:Organizm(nazwa, sila, inicjatywa, symbol)
{
	this->zasieg_ruchu = zasieg_ruchu;
}

Zwierze::Zwierze(const std::string & nazwa, const int & sila, const int & inicjatywa, const char & symbol, const int & zasieg_ruchu, int wiek, int x, int y)
	:Organizm(nazwa, sila, inicjatywa, symbol, wiek, x,y)
{
	this->zasieg_ruchu = zasieg_ruchu;
}

bool Zwierze::Akcja(Dane_o_Swiecie * informacje)
{
	informacje->nowa_pozycja = WylosujPozycje(this->GetPozycja(), informacje, zasieg_ruchu);

	if (!informacje->SprawdzCzyPoleJestWolne(informacje->nowa_pozycja.x, informacje->nowa_pozycja.y))//zajete
	{	
		return false; //Dziêki temu, w kolejnym etapie wywo³a siê kolizja
	}
	else
	{	
		informacje->OrganizmAtakujacyDoPrzeniesienia = informacje->nowa_pozycja;
		return true;
	}
}

void Zwierze::Kolizja(Organizm *org, Dane_o_Swiecie *informacje)
{
	int sila_rywala = org->GetSila();
	org->ZwiekszSileZwierzecia(this);
	if (SprawdzCzyToTeSameOrganizmy(org)) //Jesli tak, to nastepuje rozmnazanie
	{
		Wspolrzedne pozycja_dla_dziecka1 = ZnajdzPozycjeXOddalonaOdDanegoOrganizmu(this->GetPozycja(), informacje, ZASIEG_RUCHU_DEFAULT);
		Wspolrzedne pozycja_dla_dziecka2 = ZnajdzPozycjeXOddalonaOdDanegoOrganizmu(org->GetPozycja(), informacje, ZASIEG_RUCHU_DEFAULT);

		//sprawdza, czy istnieje jakies wolne miejsce dla dziecka, jesli tak to nowe zwierze sie rodzi
		if (pozycja_dla_dziecka1.x != this->GetPozycja().x || pozycja_dla_dziecka1.y != this->GetPozycja().y) //dla pierwszego rodzica
		{
			informacje->NowyOrganizm = pozycja_dla_dziecka1;
			informacje->komentator->NoweOrganizmy(this->GetNazwa());
		}
		else if (pozycja_dla_dziecka2.x != org->GetPozycja().x || pozycja_dla_dziecka2.y != org->GetPozycja().y)//dla drugiego rodzica
		{
			informacje->NowyOrganizm = pozycja_dla_dziecka2;
			informacje->komentator->NoweOrganizmy(this->GetNazwa());
		}//else nie znaleziono miejsca dla dziecka, wiec nowe zwierze sie nie rodzi
	}
	else
	{
		if (org->ZjedzenieSmiertelnejRosliny())
		{
			informacje->OrganizmAtakujacyDoUsuniecia = this->GetPozycja();
			informacje->OrganizmUciekajacyDoUsuniecia = org->GetPozycja();
			informacje->komentator->ZjedliTrujaceRosliny(this->GetNazwa());
		}
		else
		{
			if (sila_rywala > this->GetSila()) // jesli sila przeciwnika jest wieksza, to organizm umiera
			{
				if (SprawdzCzyOdwazySieWalczycZSilniejszymOrganizmem(org->GetSila())) //Organizm podejmuje walke
				{
					informacje->OrganizmAtakujacyDoUsuniecia = this->GetPozycja(); //nie przezyl
					informacje->komentator->WWynikuWalkZgineli(this->GetNazwa());
				}
				//else nic sie nie dzieje, bo lis jesli wyczu³ ¿e na jego docelowym polu jest silniejszy organizm, wiec pozosta³ na swoim miejscu
			}
			else //jest silniejszy, badz rowny -> ale zaatakowal wiec ma szanse wygrywac
			{
				if (org->SprawdzCzyOdbijeAtak(this->GetSila()))
				{
					//nic sie nie dzieje, bo przeciwnik odbil atak, wiec organizm i przeciwnik zostaja na swoim miejscu
				}
				else if (org->CzyWMomencieAtakuUcieknieNaInneMiejsce())
				{
					Wspolrzedne nowa_pozycja = ZnajdzPozycjeXOddalonaOdDanegoOrganizmu(org->GetPozycja(), informacje, zasieg_ruchu);

					if (nowa_pozycja.x == org->GetPozycja().x && nowa_pozycja.y == org->GetPozycja().y)
					{
						informacje->OrganizmUciekajacyDoUsuniecia = org->GetPozycja();
						informacje->komentator->WWynikuWalkZgineli(org->GetNazwa());
						informacje->OrganizmAtakujacyDoPrzeniesienia = org->GetPozycja();
					}
					else
					{
						informacje->OrganizmUciekajacyDoPrzeniesienia = nowa_pozycja;
						informacje->OrganizmAtakujacyDoPrzeniesienia = org->GetPozycja();
					}
				}
				else // Jesli przeciwnik nie odbil ataku i nie uciekl na inne miejsce, przegrywa
				{
					informacje->OrganizmUciekajacyDoUsuniecia = org->GetPozycja();

					if(dynamic_cast<Roslina *>(org))
						informacje->komentator->ZjedzoneRosliny(org->GetNazwa());
					else
						informacje->komentator->WWynikuWalkZgineli(org->GetNazwa());

					informacje->OrganizmAtakujacyDoPrzeniesienia = org->GetPozycja();
				}
			}
		}
	}
}

Wspolrzedne Zwierze::WykonajRuch(int zasieg_ruchu, Dane_o_Swiecie *informacje, Wspolrzedne pozycja)
{
	while (true)
	{
		int kierunek = rand()% 4;
		if (kierunek == GORA && pozycja.y - zasieg_ruchu >= 0)
		{
			pozycja.y-=zasieg_ruchu;
			return pozycja;
		}
		else if (kierunek == PRAWO && pozycja.x + zasieg_ruchu < informacje->GetSzerokosc())
		{
			pozycja.x += zasieg_ruchu;
			return pozycja;
		}
		else if (kierunek == DOL && pozycja.y + zasieg_ruchu < informacje->GetWysokosc()) 
		{
			pozycja.y += zasieg_ruchu;
			return pozycja;
		}
		else if(pozycja.x - zasieg_ruchu >= 0)//Lewo
		{
			pozycja.x -= zasieg_ruchu;
			return pozycja;
		}
	}
	return pozycja;
}

bool Zwierze::SprawdzCzyToTeSameOrganizmy(Organizm * org)
{
	if(dynamic_cast<Antylopa *> (this)&& dynamic_cast<Antylopa *> (org))
		return true;
	else if (dynamic_cast<Lis *> (this) && dynamic_cast<Lis *> (org))
		return true;
	else if (dynamic_cast<Wilk *> (this) && dynamic_cast<Wilk *> (org))
		return true;
	else if (dynamic_cast<Zolw *> (this) && dynamic_cast<Zolw *> (org))
		return true;
	else if (dynamic_cast<Owca *> (this) && dynamic_cast<Owca *> (org))
		return true;

	return false;
}

int Zwierze::GetZasiegRuchu() const
{
	return this->zasieg_ruchu;
}

Zwierze::~Zwierze()
{
}