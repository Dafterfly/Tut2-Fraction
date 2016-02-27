#include <iostream>

using namespace std;

class Fraction
{
public:
	Fraction();
	~Fraction();
	int numerator;
	int denominator;
	void getNumDenom();
	void setNumDenom(int num, int denom);
	// TODO will add these later
};

Fraction::Fraction()
{
	numerator = 0;
	denominator = 1; // Can't leave at zero because that is mathemaically nosensical
}

Fraction::~Fraction()
{
}

void Fraction::getNumDenom()
{
// TO DO
}

void Fraction::setNumDenom(int num, int denom)
{

}