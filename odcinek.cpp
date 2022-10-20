#include "odcinek.h"
#include <math.h>
#include <iostream>
using namespace std;


Odcinek::Odcinek()
{
}

void Odcinek::przesunOwektor(Wektor _wektor)
{
	punkt1->przesunOwektor(_wektor);
	punkt2->przesunOwektor(_wektor);
}

void Odcinek::obrotOkat(double _alfa, Punkt _srodek)
{
	punkt1->obrotOkat(_alfa, _srodek);
	punkt2->obrotOkat(_alfa, _srodek);
}

double Odcinek::dlugosc()
{
	return punkt1->odleglosc(*punkt2);
}

int Odcinek::prosta()
{
	if (punkt1->getX() == punkt2->getX())
	{
		if (punkt1->getY() == punkt2->getY())
		{
			cout << "Za malo roznych punktow przypisanych odcinkowi, zeby moc wyznaczyc prosta\n";
			return -1;
		}
		else
		{
			a = 0;
			b = 0;		// nie do konca prawda, ale przyjmujemy takie wartosci, zeby wylapac ktory przypadek to jest po wartosciach wspolczynnikow
			return 0;
		}
	}
	else if (punkt1->getY() == punkt2->getY())
	{
		if (punkt1->getX() == punkt2->getX())
		{
			cout << "Za malo roznych punktow przypisanych odcinkowi, zeby moc wyznaczyc prosta\n";
			return -1;
		}
		else
		{
			a = 0;
			b = 0;		// nie do konca prawda, ale przyjmujemy takie wartosci, zeby wylapac ktory przypadek to jest po wartosciach wspolczynnikow
			return 2;
		}
	}
	else
	{
		if (punkt1->getX() != 0 && punkt2->getX() != 0)  // x1 != 0 i x2 != 0
		{
			b = (punkt2->getY() * punkt1->getX() - punkt1->getY() * punkt2->getX()) / (punkt1->getX() - punkt2->getX());
			a = (punkt1->getY() - b)/punkt1->getX();
		}
		else if (punkt1->getX() != 0 && punkt2->getX() == 0) // x1 != 0 i x2 == 0
		{
			b = punkt2->getY();
			a = (punkt1->getY() - punkt2->getY()) / punkt1->getX();
		}
		else if (punkt1->getX() == 0 && punkt2->getX() != 0) // x1 == 0 i x2 != 0
		{
			b = punkt1->getY();
			a = (punkt2->getY() - punkt1->getY()) / punkt2->getX();
		}
		return 1;
	}
}

void Odcinek::blizejDalej(Punkt _punkt1, Punkt _punkt2, Punkt *_zwrot1, Punkt *_zwrot2)
{
	if (_punkt1.getX() > _punkt2.getX())
	{
		(*_zwrot1).zmienX(_punkt1.getX()); // x punktu 1 jest wiekszy niz x punktu 2
		(*_zwrot2).zmienX(_punkt2.getX());
	}
	else
	{
		(*_zwrot1).zmienX(_punkt2.getX());
		(*_zwrot2).zmienX(_punkt1.getX());
	}
	if (_punkt1.getY() > _punkt2.getY())
	{
		(*_zwrot1).zmienY(_punkt1.getY()); // y punktu 1 jest wiekszy niz y punktu 2
		(*_zwrot2).zmienY(_punkt2.getY());
	}
	else
	{
		(*_zwrot1).zmienY(_punkt2.getY()); 
		(*_zwrot2).zmienY(_punkt1.getY());
	}
}

bool Odcinek::czyNalezy(Punkt _doSprawdzenia)
{
	int odpowiedz = prosta();
	if (odpowiedz == 1)
	{
		Punkt _Dalszy, _Blizszy;
		double temp1 = a * _doSprawdzenia.getX() + b;
		if (temp1 == _doSprawdzenia.getY())
		{
			blizejDalej(*punkt1, *punkt2, &_Dalszy, &_Blizszy);
			if (_doSprawdzenia.getX() > _Dalszy.getX() || _doSprawdzenia.getX() < _Blizszy.getX() || _doSprawdzenia.getY() > _Dalszy.getY() || _doSprawdzenia.getY() < _Blizszy.getY())
			{
				cout << "Punkt nalezy do prostej odcinka, ale nie nalezy do odcinka.\n";
				return false;
			}
			else if (_doSprawdzenia.getX() < _Dalszy.getX() && _doSprawdzenia.getX() > _Blizszy.getX() && _doSprawdzenia.getY() < _Dalszy.getY() && _doSprawdzenia.getY() > _Blizszy.getY())
			{
				cout << "Punkt nalezy do odcinka.\n";
				return true;
			}
		}
		else
		{
			cout << "Punkt nie nalezy do odcinka, bo nie lezy na jego prostej!\n";
			return false;
		}
	}
	else if (odpowiedz == 0 || odpowiedz == 2)
	{
		if (odpowiedz == 0 && _doSprawdzenia.getX() != punkt1->getX())
			return false;
		else if (odpowiedz == 2 && _doSprawdzenia.getY() != punkt1->getY())
			return false;
		else
		{
			Punkt _Dalszy, _Blizszy;
			blizejDalej(*punkt1, *punkt2, &_Dalszy, &_Blizszy);
			if (_doSprawdzenia.getX() > _Dalszy.getX() || _doSprawdzenia.getX() < _Blizszy.getX() || _doSprawdzenia.getY() > _Dalszy.getY() || _doSprawdzenia.getY() < _Blizszy.getY())
			{
				cout << "Punkt nalezy do prostej odcinka, ale nie nalezy do odcinka.\n";
				return false;
			}
			if (odpowiedz == 0) //  prosta x = c 
			{
				if (_doSprawdzenia.getY() < _Dalszy.getY() && _doSprawdzenia.getY() > _Blizszy.getY())
				{
					cout << "Punkt nalezy do odcinka.\n";
					return true;
				}
			}
			else if (odpowiedz == 2) // prosta y = c
			{
				if (_doSprawdzenia.getX() < _Dalszy.getX() && _doSprawdzenia.getX() > _Blizszy.getX())
				{
					cout << "Punkt nalezy do odcinka.\n";
					return true;
				}
			}
		}
	}
	else
	{
		cout << "Nie mozna zweryfikowac przynaleznosci punktu do odcinka, bo nie mozna wyznaczyc funkcji prostej tego odcinka!\n";
		return false;
	}
}

bool Odcinek::czyRownolegle(Odcinek _drugi)
{
	int odpowiedz1 = prosta(), odpowiedz2 = _drugi.prosta();
	if (odpowiedz1 != -1 && odpowiedz2 != -1)
	{
		if (odpowiedz1 == 0 && odpowiedz2 == 0)
		{
			return true;
		}
		else if (odpowiedz1 == 2 && odpowiedz2 == 2)
		{
			return true;
		}
		else if ((odpowiedz1 == 0 && odpowiedz2 != 0) || (odpowiedz1 != 0 && odpowiedz2 == 0) || (odpowiedz1 == 2 && odpowiedz2 != 2) || (odpowiedz1 != 2 && odpowiedz2 == 2))
		{
			return false;
		}
		else
		{
			if (a == _drugi.getA())
				return true;
			else
				return false;
		}
	}
	else
	{
		cout << "Nie mozna zweryfikowac rownoleglosci odcinkow, bo nie mozna wyznaczyc funkcji prostych tych odcinkow!\n";
		return false;
	}
}

bool Odcinek::czyProstopadle(Odcinek _drugi)
{
	int odpowiedz1 = prosta(), odpowiedz2 = _drugi.prosta();
	if (odpowiedz1 != -1 && odpowiedz2 != -1)
	{
		if ((odpowiedz1 == 0 && odpowiedz2 == 2) || (odpowiedz1 == 2 && odpowiedz2 == 0))
		{
			return true;
		}
		else if ((odpowiedz1 == 0 && odpowiedz2 != 2) || (odpowiedz1 != 0 && odpowiedz2 == 2) || (odpowiedz1 == 2 && odpowiedz2 != 0) || (odpowiedz1 != 2 && odpowiedz2 == 0))
		{
			return false;
		}
		else if(_drugi.getA() != 0)
		{
			if ((a == (-1) / (_drugi.getA())) || _drugi.getA() == (-1) / a)
				return true;
			else
				return false;
		}
	}
	else
	{
		cout << "Nie mozna zweryfikowac prostopadlosci odcinkow, bo nie mozna wyznaczyc funkcji prostych tych odcinkow!\n";
		return false;
	}
}

bool Odcinek::punktPrzeciecia(Odcinek _drugi, Punkt *_pPrzeciecia)
{
	int odpowiedz1 = prosta(), odpowiedz2 = _drugi.prosta();
	if (a == _drugi.getA())
	{
		cout << "Nie mozna znalezc punktu przeciecia odcinkow, bo sa one rownolegle!\n";
		return false;
	}
	else if (odpowiedz1 != -1 && odpowiedz2 != -1)
	{
		if (odpowiedz1 == 1 && odpowiedz2 == 1)
		{
			_pPrzeciecia->zmienX((_drugi.getB() - b) / (a - _drugi.getA()));
			_pPrzeciecia->zmienY(a * _pPrzeciecia->getX() + b);
			return true;
		}
		else if (odpowiedz1 == 0 && odpowiedz2 == 2) // pierwszy -> x = c drugi -> y = d
		{
			_pPrzeciecia->zmienX(punkt1->getX());
			_pPrzeciecia->zmienY(_drugi.getPunkt1()->getY());
			return true;
		}
		else if (odpowiedz1 == 2 && odpowiedz2 == 0) // pierwszy -> y = c drugi -> x = d
		{
			_pPrzeciecia->zmienX(punkt1->getY());
			_pPrzeciecia->zmienY(_drugi.getPunkt1()->getX());
			return true;
		}
	}
	else
	{
		cout << "Nie mozna znalezc punktu przeciecia odcinkow, bo nie mozna wyznaczyc funkcji prostych tych odcinkow!\n";
		return false;
	}
}