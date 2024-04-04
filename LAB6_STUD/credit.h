#pragma once
#include <iostream>
#include "functions.h"

class credit
{
protected:
	double value;			//wartosc creditu
	double percent;			//w procentach - rocznie, np. 9%, 12%
	int years;				//na ile lat
	int payments_in_year;	//ile rat w roku

	string info;		// dodatkowa informacja o kredycie, opis

public:
	credit() : value{ 0 }, percent{ 0 }, years{ 0 }, payments_in_year{ 0 }, info{ "" } { }
	credit(double value, double percent, int years, int payments_in_year, const char* info = "xxxxxxxxxx");
	virtual credit* clone() const;
	friend bool cmp_value(const credit& k1, const credit& k2);
	friend bool cmp_value_info(const credit& k1, const credit& k2);

	//credit(const credit& k);				//zdefiniuj, je�eli uwa�asz �e jest potrzebne
	//credit& operator = (const credit& k);	//zdefiniuj, je�eli uwa�asz �e jest potrzebne
	//~credit();							//zdefiniuj, je�eli uwa�asz �e jest potrzebne

	int payments() const { return years * payments_in_year; }	//liczba rat kredytu
	double payment() const;				//rata kredytu

	virtual void write(std::ostream& out) const;
	friend std::ostream& operator<<(std::ostream& out, const credit& os);

	
};
