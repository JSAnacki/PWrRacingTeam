#include "Miejsce.h"
#define GORA 500000
#define DOL 1

Miejsce::Miejsce(int _poprzednie, int _nastepne) 
{
	zmienPoprzednie(_poprzednie);
	zmienNastepne(_nastepne);
}

void Miejsce::zmienPoprzednie(int _poprzednie)
{
	poprzednie = _poprzednie;
}

void Miejsce::zmienNastepne(int _nastepne)
{
	nastepne = _nastepne;
}