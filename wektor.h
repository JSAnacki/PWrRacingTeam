#pragma once

class Wektor
{
private:
	double p;
	double q;

public:
	void zmienP(double _ile);
	void zmienQ(double _ile);
	double getP() const { return p; }
	double getQ() const { return q; }
};