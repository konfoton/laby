#include <iostream>
using namespace std;
#include <cmath>
#include <iomanip>
#include "credit.h"


credit::credit( double value, double percent, int years, int payments_in_year , const char* info )
{ 

	this->value = value;
	this->percent = percent; 
	this->years = years;
	this->payments_in_year = payments_in_year;
	this->info = info;

}



double credit::payment() const	//rata kredytu
{
	double q = percent * 0.01 / payments_in_year;     
	return value * q * pow(1 + q, payments()) / (pow(1 + q, payments()) - 1);

}


void credit::write(ostream& out) const
{
	out << this->info << " credit: " << value << " ( " << percent << "%)" << " years: " << years
	<< " r/r " << payments_in_year << " " << payment(); 
	
}

ostream& operator<<(ostream& out, const credit& os)
{
	os.write(out);
	return out;
}
credit* credit::clone() const {
        return new credit(*this);
    }


