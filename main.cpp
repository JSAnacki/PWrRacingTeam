#include "tem.h"
#include "symulacja.h"

using namespace std;

void sprawdzanie(int *doSprawdzenia, int gora, int dol)
{
	bool zgodnosc = false;
	tem<int> test1;
	while (zgodnosc == false)
	{
		zgodnosc = test1.wpisywanieParametrow(1, doSprawdzenia, gora, dol);
		if(zgodnosc == false)
			cout << "Sprobuj jeszcze raz: ";
	}

	system("cls");
}

int main()
{
	int n, m, a, b;
	cout << "Podaj n: ";
	sprawdzanie(&n, GORA, DOL);
	cout << "Podaj m: ";
	sprawdzanie(&m, GORA, DOL);
	cout << "Podaj a: ";
	sprawdzanie(&a, n, DOL);
	cout << "Podaj b: ";
	sprawdzanie(&b, n, DOL);

	Symulacja dzialanie;
	
	dzialanie.przebieg(n);
	
	return 0;
}