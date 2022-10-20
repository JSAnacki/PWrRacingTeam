#include "trojkatProstokatny.h"

double TrojkatProstokatny::przeciwprostokatna()
{
	double odc1 = punkt1->odleglosc(*punkt2);
	double odc2 = punkt2->odleglosc(*punkt3);
	double odc3 = punkt3->odleglosc(*punkt1);
	double przeciwprostokatna;
	if (odc1 > odc2)
	{
		if (odc1 > odc3)
			przeciwprostokatna = odc1;
	}
	else if (odc2 > odc3)
		przeciwprostokatna = odc2;
	else
		przeciwprostokatna = odc3;
	return przeciwprostokatna;
}

