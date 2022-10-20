#pragma once
#include "wektor.h"
#include "math.h"

class Punkt
{
private:
	double x;
	double y;

public:
	Punkt();
	void przesunOwektor(Wektor _wektor);
	void obrotOkat(double _alfa, Punkt _srodek);
	double odleglosc(Punkt _bazowy);
	void zmienX(double _x);
	void zmienY(double _y);
	double getX() const { return x; }
	double getY() const { return y; }
};