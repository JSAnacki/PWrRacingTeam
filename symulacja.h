#pragma once
#include "droga.h"
#include "Miejsce.h"
#include "symulacja.h"
#include "tem.h"
#include <iostream>
#define GORA 500000
#define DOL 1
using namespace std;
class Symulacja
{
private:
	int zlamanPrawa;
	bool mozliweDoWykonania;
	droga *drogi;
	Miejsce *miejsca;

public:
	Symulacja(int _zlamanPrawa = 0, bool _doWykonania = true);
	void stworzMiejsca(int _ile);
	void stworzDrogi(int _ile);
	void dodajZlamaniePrawa();
	void zmienmozliweDoWykonania(bool _dowykonania);
	int getzlamanPrawa() const { return zlamanPrawa; }
	bool getmozliweDoWykonania() const { return mozliweDoWykonania; }
	void przebieg(int _miejsc);
	~Symulacja();
};