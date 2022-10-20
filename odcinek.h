#pragma once
#include "punkt.h"
#include "wektor.h"

class Odcinek
{
private:
	Punkt* punkt1;
	Punkt* punkt2;
	double a;
	double b; // a i b ze wzoru na prosta 

public:
	Odcinek();
	void przesunOwektor(Wektor _wektor);
	void obrotOkat(double _alfa, Punkt _srodek);
	double dlugosc();
	int prosta();
	void blizejDalej(Punkt _punkt1, Punkt _punkt2, Punkt* _zwrot1, Punkt* _zwrot2);
	bool czyNalezy(Punkt _doSprawdzenia);
	bool czyRownolegle(Odcinek _drugi);
	Punkt* getPunkt1() const { return punkt1; }
	Punkt* getPunkt2() const { return punkt2; }
	double getA() const { return a; }
	double getB() const { return b; }
	bool czyProstopadle(Odcinek _drugi);
	bool punktPrzeciecia(Odcinek _drugi, Punkt *_pPrzeciecia);
};
