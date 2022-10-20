#include "trojkat.h"
#include <cmath>

using namespace std;

void Trojkat::przesunOwektor(Wektor _wektor)
{
	punkt1->przesunOwektor(_wektor);
	punkt2->przesunOwektor(_wektor);
	punkt3->przesunOwektor(_wektor);
}

void Trojkat::obrotOkat(double _alfa, Punkt _srodek)
{
	punkt1->obrotOkat(_alfa, _srodek);
	punkt2->obrotOkat(_alfa, _srodek);
	punkt3->obrotOkat(_alfa, _srodek);
}

double Trojkat::obwod()
{
	return (punkt1->odleglosc(*punkt2) + punkt2->odleglosc(*punkt3) + punkt3->odleglosc(*punkt1));
}

double Trojkat::Pole()
{
	return (1 / 2 * abs((punkt2->getX() - punkt1->getX()) * (punkt3->getY() - punkt1->getY()) - (punkt2->getY() - punkt1->getY()) * (punkt3->getX() - punkt1->getX()))); // punkt1 - A punkt2 - B punkt3 - C
}

double Trojkat::odleglosc(Punkt _pierwszy, Punkt _drugi, Punkt _odTego)
{
	return ((_odTego.getX() - _pierwszy.getX()) * (_drugi.getY() - _pierwszy.getY()) - (_odTego.getY() - _pierwszy.getY()) * (_drugi.getX() - _pierwszy.getX()));
}

bool Trojkat::czyRozlaczne(Trojkat _drugi)
{
	// obliczenie przyblizonych wspolrzednych punktu srodkowego bazowego trojkata:
	bool Wspolne1 = true, Wspolne2 = true, Wspolne3 = true;
	double srodkowyX = 0, srodkowyY = 0;
	srodkowyX = (punkt1->getX() + punkt2->getX() + punkt3->getX()) / 3;
	srodkowyY = (punkt1->getY() + punkt2->getY() + punkt3->getY()) / 3;
	Punkt Srodkowy;
	Srodkowy.zmienX(srodkowyX);
	Srodkowy.zmienY(srodkowyY);
	
	// obliczenie odleglosci bokow bazowego trojkata od przyjetego srodka
	double Sr[3];
	Sr[0] = odleglosc(*punkt1, *punkt2, Srodkowy);
	Sr[1] = odleglosc(*punkt2, *punkt3, Srodkowy);
	Sr[2] = odleglosc(*punkt3, *punkt1, Srodkowy);

	// bierzemy po kolei kazdy punkt drugiego trojkata i sprawdzamy jego odleglosci od konkretnych bokow
	// jesli wszystkie odleglosci maja te same znaki co odleglosci wszystkich bokow pierwszego trojkata od jego srodka 
	// to znaczy ze punkt nalezy do trojkata
	double P[3];
	P[0] = odleglosc(*punkt1, *punkt2, *_drugi.getPunkt1());
	P[1] = odleglosc(*punkt2, *punkt3, *_drugi.getPunkt1());
	P[2] = odleglosc(*punkt3, *punkt1, *_drugi.getPunkt1());

	for (int i = 0; i < 3; i++)
		if (P[i] * Sr[i] < 0)
			Wspolne1 = false;

	P[0] = odleglosc(*punkt1, *punkt2, *_drugi.getPunkt2());
	P[1] = odleglosc(*punkt2, *punkt3, *_drugi.getPunkt2());
	P[2] = odleglosc(*punkt3, *punkt1, *_drugi.getPunkt2());

	for (int i = 0; i < 3; i++)
		if (P[i] * Sr[i] < 0)
			Wspolne2 = false;

	P[0] = odleglosc(*punkt1, *punkt2, *_drugi.getPunkt3());
	P[1] = odleglosc(*punkt2, *punkt3, *_drugi.getPunkt3());
	P[2] = odleglosc(*punkt3, *punkt1, *_drugi.getPunkt3());

	for (int i = 0; i < 3; i++)
		if (P[i] * Sr[i] < 0)
			Wspolne3 = false;

	if (Wspolne1 == true || Wspolne2 == true || Wspolne3 == true)
		return true;
	else
		return false;
}