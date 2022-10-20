#pragma once
#include <string>
#include <iostream>

template <typename T>
class tem 
{
private:
	bool sprawdzPrzedzial(int _czesc, int gora, int dol)
	{
		if (_czesc <= gora && _czesc >= dol)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	T& test(int wersja)
	{
		T temp;
		std::string::size_type st;
		std::string wejscie;

		std::cin >> wejscie; //pobranie zmiennej do weryfikacji warunkow petli

		while (std::cin.fail() /*brak znaku nowej linii*/ || std::cin.eof() /*koniec wpisywania/pobierania*/ || wejscie.find_first_not_of("0123456789.") != std::string::npos /*zostal wpisany znak po numerze bez spacji*/) //wykrycie bledu
		{
			std::cout << "Blad! Podaj poprawna liczbe: " << std::endl;  //komunikat o bledzie

			if (wejscie.find_first_not_of("0123456789.") == std::string::npos) //zdejmowanie flag
			{
				std::cin.clear();                   //resetowanie flag bledu
				std::cin.ignore(256, '\n');     //czyszczenie 256 znakow bufora
			}

			std::cin >> wejscie; //pobranie nowej wartosci zmiennej po komunikacie bledu
		}
		//przeksztalcenie typu string na float
		if (wersja == 1)
			temp = std::stof(wejscie, &st);
		//przeksztalcenie typu string na int
		else if (wersja == 2)
			temp = std::stoi(wejscie, &st);
		//zwrot zweryfikowanej zmiennej 
		return temp;
	}

public:
	bool wpisywanieParametrow(int wersja, T* probka, int gora, int dol)
	{
		int wprowadzone = test(1);
		if (sprawdzPrzedzial(wprowadzone, gora, dol) == false)
		{
			return false;
		}
		else
		{
			*probka = wprowadzone;
			return true;
		}
	}
};