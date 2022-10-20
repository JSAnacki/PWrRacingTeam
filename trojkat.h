#pragma once
#include "punkt.h"
#include "wektor.h"

class Trojkat
{
protected:
	Punkt* punkt1;
	Punkt* punkt2;
	Punkt* punkt3;

public:
	void przesunOwektor(Wektor _wektor);
	void obrotOkat(double _alfa, Punkt _srodek);
	double obwod();
	double Pole();
	bool czyRozlaczne(Trojkat _drugi);
	Punkt* getPunkt1() const { return punkt1; }
	Punkt* getPunkt2() const { return punkt2; }
	Punkt* getPunkt3() const { return punkt3; }
	double odleglosc(Punkt _pierwszy, Punkt _drugi, Punkt _odTego);
};