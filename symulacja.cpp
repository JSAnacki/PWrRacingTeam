#include "symulacja.h"

Symulacja::Symulacja(int _miejsc, bool _doWykonania)
{
	zmienmozliweDoWykonania(_doWykonania);
}

void Symulacja::stworzDrogi(int _ile)
{
	drogi = new droga[_ile];
}

void Symulacja::stworzMiejsca(int _ile)
{
	miejsca = new Miejsce[_ile];
}

void Symulacja::dodajZlamaniePrawa()
{
	if (zlamanPrawa < 0)
		zlamanPrawa = 0;
	else
		zlamanPrawa++;
}

void Symulacja::zmienmozliweDoWykonania(bool _dowykonania)
{
	mozliweDoWykonania = _dowykonania;
}

void Symulacja::przebieg(int _miejsc)
{
	stworzMiejsca(_miejsc);
	stworzDrogi(_miejsc - 1);
	for (int i = 0; i < _miejsc; i++)
	{
		miejsca[i].zmienPoprzednie(i);
		if (i == _miejsc - 1)
			miejsca[i].zmienNastepne(0);
		else
			miejsca[i].zmienNastepne(i + 1);
	} // zapis danych miejscs
	int u, v;
	bool zgodnosc1 = false;
	bool zgodnosc2 = false;
	tem<int> test1;
	for (int i = 0; i < _miejsc - 1; i++) // pobranie danych drog
	{
		while (zgodnosc1 == false)
		{
			zgodnosc1 = test1.wpisywanieParametrow(1, &u, _miejsc, DOL);
			if (zgodnosc1 == false)
				cout << "Sprobuj jeszcze raz: ";
		}
		zgodnosc1 = false;
		drogi[i].zmienPoczatkowe(u);
		while (zgodnosc2 == false)
		{
			zgodnosc2 = test1.wpisywanieParametrow(1, &v, _miejsc, DOL);
			if (zgodnosc2 == false || u == v)
				cout << "Sprobuj jeszcze raz: ";
			if (u == v) // blad jesli sa rowne - droga nigdzie nie prowadzi
				zgodnosc2 = false;
		}
		zgodnosc2 = false;
		system("cls");
		drogi[i].zmienKoncowe(v);
		if (u > v) // zamiana miejscami kierunkow pod prad w drogach i oznaczenie jako pod prad
		{
			drogi[i].zmienPoczatkowe(v);
			drogi[i].zmienKoncowe(u);
			drogi[i].zmienpodPrad(true);
		}
	}
	// poszukiwanie najmniejszej wartosci miejsca poczatkowego:
	int temp = 0, ktory = 0, obecny = 0, zapisanaAlternatywa = 0; // ktory - zapis numeru drogi w kolejnosci wpisywania do programu
	bool zmiana = false, pierwszy = true;
	int *uzyte = new int[_miejsc];
	int kroki = 0, znaleziony = 0, dopasowanie = 0;
	droga alternatywa;
	while (zmiana == false && getmozliweDoWykonania() == true)
	{
		for (int i = 0; i < _miejsc - 1; i++)
		{
			if (drogi[i].getPoczatkowe() < temp || pierwszy == true)
			{
				if (pierwszy == false && i != obecny)
				{
					for (int j = 0; j < znaleziony; j++)
					{
						if (drogi[i].getPoczatkowe() > drogi[uzyte[j+1]].getPoczatkowe())
							dopasowanie++;
					}
					if (dopasowanie == znaleziony)
					{
						temp = drogi[i].getPoczatkowe();
						ktory = i;
						zmiana = false;
						pierwszy = false;
						dopasowanie = 0;
					}
					else
						dopasowanie = 0;
				}
				else if ((i != obecny || kroki == 0)&&pierwszy == true)
				{
					temp = drogi[i].getPoczatkowe();
					ktory = i;
					zmiana = true;
					pierwszy = false;
				}
			}
		}
		if (zmiana == true)
			zmiana = false;
		else
		{
			znaleziony++;
			if (temp == drogi[obecny].getKoncowe() || znaleziony == 1) // czy poczatek nowego == koniec poprzedniego
			{
				if (drogi[ktory].getKoncowe() == (drogi[ktory].getPoczatkowe() + 1)) // czy polaczenie do kolejnego miejsa
				{
					obecny = ktory;
					uzyte[znaleziony] = obecny;
				}
				else
				{
					if (drogi[ktory].getpodPrad() == false) // jesli nie pod prad
					{
						if (drogi[ktory].getKoncowe() <= _miejsc) // jesli nie idzie dalej niz cel
						{
							if (drogi[ktory].getKoncowe() == _miejsc)  // jesli rowna sie cel
							{
								obecny = ktory;
								uzyte[znaleziony] = obecny;
								zmienmozliweDoWykonania(true);
								break;
							}
							else
							{
								obecny = ktory;
								uzyte[znaleziony] = obecny;
							}
						}
						else
						{
							//usun- idzie dalej niz cel - prosty sposob na "usuwanie" z braku czasu na rozwazenie innych sposobow
							// zwykla kopia nastepnego
							if (ktory + 1 <= _miejsc - 1)
								drogi[ktory] = drogi[ktory + 1];
							else
								drogi[ktory] = drogi[ktory - 1];
						}
					}
					else if(zapisanaAlternatywa == 0)  // kilka krokow pod prad - oznaczyc jako alternatywe w przypadku braku lepszych mozliwosci
					{	// i "usunac" j.w.
						alternatywa = drogi[ktory];
						zapisanaAlternatywa++;
						if (ktory + 1 <= _miejsc - 1)
							drogi[ktory] = drogi[ktory + 1];
						else
							drogi[ktory] = drogi[ktory - 1];
					}
				}
			}
			else
			{
				zmienmozliweDoWykonania(false);
			}
			temp = drogi[ktory].getKoncowe() + 1;
			if (temp > _miejsc)
			{
				zmienmozliweDoWykonania(true);
				break;
			}
		}
		if (getmozliweDoWykonania() == false && zapisanaAlternatywa != 0)
			drogi[ktory] = alternatywa;
		kroki++;
		// jesli na koniec nadal brak rozwiazania - ustawic alternatywe jako obecny
	}
	if (getmozliweDoWykonania() == false)
		cout << "-1";
	else
	{
		for (int i = 0; i < _miejsc-1; i++) // zliczanie uzytych drog pod prad
		{
			if (drogi[uzyte[i+1]].getpodPrad() == true)
				dodajZlamaniePrawa();
		}
		cout << getzlamanPrawa();
	}
}

Symulacja::~Symulacja()
{
	delete[] miejsca;
	delete[] drogi;
}
