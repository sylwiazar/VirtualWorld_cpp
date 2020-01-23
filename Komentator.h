#pragma once
#include <string>
class Komentator
{
public:
	Komentator();

	void WWynikuWalkZgineli(const std::string nazwa);
	void ZjedzoneRosliny(const std::string nazwa);
	void NoweOrganizmy(const std::string nazwa);
	void ZjedliTrujaceRosliny(const std::string nazwa);

	//Jednoczesnie usuwa wszystkie komentarze, by w nastepnej turze zapisywac w nich nowe informacje
	void WypiszKomentarze();

	~Komentator();

private:
	std::string zjedzone_rosliny;
	std::string w_wyniku_walk_zgineli;
	std::string nowe_organizmy;
	std::string zjedli_trujace_rosliny;
};