#include "punkt.h"
#include <math.h>
#include <cmath>
#include <iostream>
#include "tem.h"

using namespace std;

Punkt::Punkt()
{
	tem<float> test1;
	bool zgodnosc = false;
	float _X, _Y;
	while (zgodnosc == false)
	{
		system("cls");
		cout << "Podaj wartosc wspolrzednej x punktu: ";
		zgodnosc = test1.wpisywanieParametrow(1, &_X, 100, -100);

	}
	x = _X;
	zgodnosc = false;
	while (zgodnosc == false)
	{
		system("cls");
		cout << "Podaj wartosc wspolrzednej y punktu: ";
		zgodnosc = test1.wpisywanieParametrow(1, &_Y, 100, -100);
	}
	y = _Y;
}

void Punkt::zmienX(double _x)
{
	x = _x;
}

void Punkt::zmienY(double _y)
{
	y = _y;
}

void Punkt::przesunOwektor(Wektor _wektor)
{
	x += _wektor.getP();
	y += _wektor.getQ();
}

void Punkt::obrotOkat(double _alfa, Punkt _srodek)
{
	double temp1 = abs(x-_srodek.getX()), temp2 = abs(y-_srodek.getY());
	x = temp1 * cos(_alfa) - temp2 * sin(_alfa);
	y = temp1 * sin(_alfa) + temp2 * cos(_alfa);
}

double Punkt::odleglosc(Punkt _bazowy)
{
	return sqrt(pow((_bazowy.getX() - x), 2.0) - pow((_bazowy.getY() - y), 2.0));
}
