#pragma once
#include <iostream>
#include "tem.h"
#include "punkt.h"
#include "trojkat.h"
#include "trojkatProstokatny.h"
#include "odcinek.h"

class Obsluga
{
private:
	Punkt *_punkty;
	int _punktow;
	Odcinek *_odcinki;
	int _odcinkow;
	Trojkat *_trojkaty;
	int _trojkatow;
	TrojkatProstokatny *_trojkatyProstokatne;
	int _trojkatowProstokatnych;

public:
	Obsluga();
	void stworzPunkt(int _ile);
	void stworzOdcinek(int _ile);
	void stworzTrojkat(int _ile);
	void stworzTrojkatProstokatny(int _ile);
	int getPunktow() const { return _punktow; }
	int getOdcinkow() const { return _odcinkow; }
	int getTrojkatow() const { return _trojkatow; }
	int getTrojkatowProstokatnych() const { return _trojkatowProstokatnych; }
	Punkt getPunkt(int _ktory) const { return _punkty[_ktory]; }
	Odcinek getOdcinek(int _ktory) const { return _odcinki[_ktory]; }
	Trojkat getTrojkat(int _ktory) const { return _trojkaty[_ktory]; }
	TrojkatProstokatny getTrojkatProstokatny(int _ktory) const { return _trojkatyProstokatne[_ktory]; }
	~Obsluga();

};