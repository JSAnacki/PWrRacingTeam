#include "obsluga.h"
using namespace std;

Obsluga::Obsluga()
	: _punktow(0)
	, _odcinkow(0)
	, _trojkatow(0)
	, _trojkatowProstokatnych(0)
	, _punkty(NULL)
	, _odcinki(NULL)
	, _trojkaty(NULL)
	, _trojkatyProstokatne(NULL)
{}


void Obsluga::stworzPunkt(int _ile)
{
	_punktow = 0;
	delete[] _punkty;
	_punkty = new Punkt[_ile];
	_punktow += _ile;
}

void Obsluga::stworzOdcinek(int _ile)
{
	_odcinkow = 0;
	delete[] _odcinki;
	_odcinki = new Odcinek[_ile];
	_odcinkow += _ile;
}

void Obsluga::stworzTrojkat(int _ile)
{
	_trojkatow = 0;
	delete[] _trojkaty;
	_trojkaty = new Trojkat[_ile];
	_trojkatow += _ile;
}

void Obsluga::stworzTrojkatProstokatny(int _ile)
{
	_trojkatowProstokatnych = 0;
	delete[] _trojkatyProstokatne;
	_trojkatyProstokatne = new TrojkatProstokatny[_ile];
	_trojkatowProstokatnych += _ile;
}

Obsluga::~Obsluga()
{
	delete[] _punkty;
	delete[] _odcinki;
	delete[] _trojkaty;
	delete[] _trojkatyProstokatne;
}