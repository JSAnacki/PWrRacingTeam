#include "droga.h"
#define GORA 500000
#define DOL 1

droga::droga(int _miejscePoczatkowe, int _miejsceKoncowe, bool _podPrad)
{
	zmienPoczatkowe(_miejscePoczatkowe);
	zmienKoncowe(_miejsceKoncowe);
	zmienpodPrad(_podPrad);
}

void droga::zmienPoczatkowe(int _poczatkowe)
{
	miejscePoczatkowe = _poczatkowe;
}

void droga::zmienKoncowe(int _koncowe)
{
	miejsceKoncowe = _koncowe;
}

void droga::zmienpodPrad(bool _podPrad)
{
	podPrad = _podPrad;
}


