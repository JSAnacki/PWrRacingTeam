#include <string>
#include "obsluga.h"
using namespace std;

void menu(int* wybor)
{
	tem<int> test1;
	int temp = 0;
	bool zgodnosc = false;
	while (zgodnosc == false)
	{
		system("cls");
		cout << "*****\tZadanie 1. - FIGURY\t*****\n\nWitaj!\nWybierz obiekt do utworzenia przez podanie numeru:\n\n\t1 - punkt\n\t2 - odcinek\n\t3 - trojkat\n\t4 - trojkat prostokatny\n\t0 - wyjscie z programu\n\nTwoj wybor: ";
		zgodnosc = test1.wpisywanieParametrow(1, &temp, 4, 0);
	}
	*wybor = temp;
}

int powrot()
{
	int pytanie = 0;
	tem<int> test1;
	bool zgodnosc = false;
	while (zgodnosc == false)
	{
		system("cls");
		cout << endl << "\nCzy chcesz zakonczyc?\n1 - menu glowne\n2 - wyjdz z programu" << endl;
		zgodnosc = test1.wpisywanieParametrow(1, &pytanie, 2, 1);
	}
	return pytanie;
}

int main()
{
	tem<int> test1;
	int pierwszyWybor = 9;
	bool zgodnosc = false;
	Obsluga przebieg;
	while (pierwszyWybor != 0)
	{
		switch (pierwszyWybor)
		{
		case 1:  // punkty
		{
			system("cls");
			int punkty;
			zgodnosc = false;
			while (zgodnosc == false)
			{
				system("cls");
				cout << "Podaj liczbe punktow (1-3): ";
				zgodnosc = test1.wpisywanieParametrow(1, &punkty, 3, 1);
			}
			przebieg.stworzPunkt(punkty);
			int pytanie2 = 9;
			zgodnosc = false;
			while (zgodnosc == false)
			{
				system("cls");
				cout << "Wybierz zadanie do wykonania na wybranym punkcie przez podanie numeru:\n\n\t1 - przesuw o wektor\n\t2 - obrot dookola zadanego punktu o zadany kat\n\t3 - odleglosc miedzy dwoma punktami\n\t0 - powrot\n\nTwoj wybor: ";
				zgodnosc = test1.wpisywanieParametrow(1, &pytanie2, 3, 0);
			}
			switch (pytanie2)
			{
			case 1:
			{
				system("cls");
				cout << "Wybrales zadanie: przesuw o wektor.\n";
				zgodnosc = false;
				int pytanie3;
				while (zgodnosc == false)
				{
					cout << "Wybierz punkt na ktorym ma zostac wykonany przesuw o wektor:\n\n\t";
					for (int i = 0; i < przebieg.getPunktow(); i++)
						cout << i + 1 << ". punkt: X = " << przebieg.getPunkt(i).getX() << "; Y = " << przebieg.getPunkt(i).getY() << endl;
					cout << "Twoj Wybor: ";
					zgodnosc = test1.wpisywanieParametrow(2, &pytanie3, przebieg.getPunktow(), 1);
				}
				zgodnosc = false;
				Wektor _wektor;
				tem<float> test2;
				float _p, _q;
				cout << "Wpisz dane wektora:\n\t";
				while (zgodnosc == false)
				{
					cout << "Podaj wartosc wspolrzednej p wektora: " << endl;
					zgodnosc = test2.wpisywanieParametrow(2, &_p, 100, -100);
				}
				zgodnosc = false;
				while (zgodnosc == false)
				{
					cout << "Podaj wartosc wspolrzednej q wektora: " << endl;
					zgodnosc = test2.wpisywanieParametrow(2, &_q, 100, -100);
				}
				_wektor.zmienP(_p);
				_wektor.zmienQ(_q);
				przebieg.getPunkt(pytanie3).przesunOwektor(_wektor);

				// wyswietlanie nowych wspolrzednych
				break;
			}
			case 2:	// obrot
			{

				break;
			}
			case 3: // odleglosc miedzy dwoma punktami
			{

				break;
			}
			case 0: // powrot
			{

				break;
			}
			}
			if (powrot() == 2)
			{
				pierwszyWybor = 0;
			}
			else
				break;
		}
		case 2: // odcinki
		{
			system("cls");
			int odcinki;
			zgodnosc = false;
			while (zgodnosc == false)
			{
				system("cls");
				cout << "Podaj liczbe odcinkow (1-3): ";
				zgodnosc = test1.wpisywanieParametrow(1, &odcinki, 3, 1);
			}
			przebieg.stworzOdcinek(odcinki);
			int pytanie2 = 9;
			zgodnosc = false;
			while (zgodnosc == false)
			{
				system("cls");
				cout << "Wybierz zadanie do wykonania na wybranym odcinku przez podanie numeru:\n\n\t1 - przesuw o wektor\n\t2 - obrot dookola zadanego punktu o zadany kat\n\t3 - odleglosc miedzy dwoma punktami\n\t0 - powrot\n\nTwoj wybor: ";
				zgodnosc = test1.wpisywanieParametrow(1, &pytanie2, 3, 0);
			}
			switch (pytanie2)
			{
			case 1:
			{
				system("cls");
					break;
			}
			case 2:
			{

				break;
			}
			case 3:
			{

				break;
			}
			case 0:
			{

				break;
			}
			}
			if (powrot() == 2)
			{
				pierwszyWybor = 0;
			}
			else
				break;
		}
		case 3: // trojkaty
		{
			system("cls");
			int trojkaty;
			zgodnosc = false;
			while (zgodnosc == false)
			{
				system("cls");
				cout << "Podaj liczbe trojkatow (1-3): ";
				zgodnosc = test1.wpisywanieParametrow(1, &trojkaty, 3, 1);
			}
			przebieg.stworzTrojkat(trojkaty);
			int pytanie2 = 9;
			zgodnosc = false;
			while (zgodnosc == false)
			{
				system("cls");
				cout << "Wybierz zadanie do wykonania na wybranym trojkacie przez podanie numeru:\n\n\t1 - przesuw o wektor\n\t2 - obrot dookola zadanego punktu o zadany kat\n\t3 - odleglosc miedzy dwoma punktami\n\t0 - powrot\n\nTwoj wybor: ";
				zgodnosc = test1.wpisywanieParametrow(1, &pytanie2, 3, 0);
			}
			switch (pytanie2)
			{
			case 1:
			{
				system("cls");
					break;
			}
			case 2:
			{

				break;
			}
			case 3:
			{

				break;
			}
			case 0:
			{

				break;
			}
			}
			if (powrot() == 2)
			{
				pierwszyWybor = 0;
			}
			else
				break;
		}
		case 4: // trojkaty prostokatne
		{
			system("cls");
			int trojkatyProstokatne;
			zgodnosc = false;
			while (zgodnosc == false)
			{
				system("cls");
				cout << "Podaj liczbe trojkatow prostokatnych (1-3): ";
				zgodnosc = test1.wpisywanieParametrow(1, &trojkatyProstokatne, 3, 1);
			}
			przebieg.stworzTrojkatProstokatny(trojkatyProstokatne);
			int pytanie2 = 9;
			zgodnosc = false;
			while (zgodnosc == false)
			{
				system("cls");
				cout << "Wybierz zadanie do wykonania na wybranym trojkacie prostokatnym przez podanie numeru:\n\n\t1 - przesuw o wektor\n\t2 - obrot dookola zadanego punktu o zadany kat\n\t3 - odleglosc miedzy dwoma punktami\n\t0 - powrot\n\nTwoj wybor: ";
				zgodnosc = test1.wpisywanieParametrow(1, &pytanie2, 3, 0);
			}
			switch (pytanie2)
			{
			case 1:
			{
				system("cls");
					break;
			}
			case 2:
			{

				break;
			}
			case 3:
			{

				break;
			}
			case 0:
			{

				break;
			}
			}
			if (powrot() == 2)
			{
				pierwszyWybor = 0;
			}
			else
				break;
		}
		case 0:
		{
			break;
		}
		default:
			break;
		}
		if (pierwszyWybor == 0)
			break;
		menu(&pierwszyWybor);
	}
	return 0;
}