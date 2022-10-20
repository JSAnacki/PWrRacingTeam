#pragma once


class Miejsce
{
private:
	int poprzednie;
	int nastepne;

public:
	Miejsce(int _poprzednie = 0, int _nastepne = 0);
	void zmienPoprzednie(int _poprzednie);
	void zmienNastepne(int _nastepne);
	int getPoprzednie() const {	return poprzednie;	}
	int getNastepne() const { return nastepne; }
};
