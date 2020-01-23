#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <time.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "Swiat.h"

using namespace std;

int main()
{
	int wysokosc = 0;
	int szerokosc = 0;
	int rodzajgry;
	srand(time(NULL));
	SetConsoleTitleA("Sylwia, Zaroslak, 171477");
	printf("Wybierz gre: \n1.Wczytaj stan gry z pliku: 1\n2.Rozpocznij nowa gre: 2\n");
	scanf("%d", &rodzajgry);
	if (rodzajgry == 2)
	{
		while (1)
		{
			printf("Wpisz wysokosc planszy (najmniejszy mozliwy rozmiar to 10): \n");
			scanf_s("%d", &wysokosc);
			printf("Wpisz szerokosc planszy: (najmniejszy mozliwy rozmiar to 10)\n");
			scanf_s("%d", &szerokosc);
			system("cls");
			if ((wysokosc >= 10) && (szerokosc >= 10))
				break;
		}
		Swiat swiat(szerokosc, wysokosc);
		char decyzja_uzytkownika;
		scanf("%c", &decyzja_uzytkownika);
		while (decyzja_uzytkownika != 'q')
		{
			swiat.PrzeprowadzGre(decyzja_uzytkownika);
			scanf("%c", &decyzja_uzytkownika);
		}
	}
	else
	{
		Swiat swiat;
		char decyzja_uzytkownika;
		scanf("%c", &decyzja_uzytkownika);
		while (decyzja_uzytkownika != 'q')
		{
			swiat.PrzeprowadzGre(decyzja_uzytkownika);
			scanf("%c", &decyzja_uzytkownika);
		}
	}




	system("pause");
	return 0;
}
