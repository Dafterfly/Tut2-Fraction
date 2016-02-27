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
	Fraction add(Fraction addend);
	Fraction subtract(Fraction subtrahend);
	Fraction multiply(Fraction multiplicand);
	Fraction divide(Fraction divisor);
	void print(Fraction fra);
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

}

void Fraction::setNumDenom(int num, int denom)
{
	numerator = num;

	if (denom != 0) // CHeck to make sure the denominator is not set to zero
	{
		denominator = denom;
	}
}

Fraction Fraction::add(Fraction addend)
{
	Fraction answer;
	int ansDen = denominator * addend.denominator; // find LCM for denominator
	int ansNum = (numerator*addend.denominator) + (addend.numerator*denominator);

	answer.setNumDenom(ansNum,ansDen);

	return answer;
}

Fraction Fraction::subtract(Fraction subtrahend)
{
	Fraction answer;
	int ansDen = denominator * subtrahend.denominator; // find LCM for denominator
	int ansNum = (numerator*subtrahend.denominator) + (subtrahend.numerator*denominator);

	answer.setNumDenom(ansNum, ansDen);

	return answer;
}

Fraction Fraction::multiply(Fraction multiplicand)
{
	Fraction answer;
	int ansDen = denominator * multiplicand.denominator; 
	int ansNum = numerator * multiplicand.numerator;

	answer.setNumDenom(ansNum, ansDen);

	return answer;
}

Fraction Fraction::divide(Fraction divisor)
{
	Fraction answer;
	int ansDen = denominator * divisor.numerator;
	int ansNum = numerator * divisor.denominator;

	answer.setNumDenom(ansNum, ansDen);

	return answer;
}

int gcd(Fraction fra)
{
	int num = fra.numerator;
	int denom = fra.denominator;

	int larger, smaller, temp;

	//determine whether denom or numerator is larger or smaller
	if (num > denom)
	{
		larger = num;
		smaller = denom;
	}
	else
		{
			larger = denom;
			smaller = num;
		}

	// calculating gcd
	while (smaller != 0)
	{
	temp = smaller;
	smaller = larger % smaller;
	larger = temp;
	}
	
	return larger;
}

void Fraction::print(Fraction fra)
{
	int greatestDivisor = gcd(fra);

	// simplify original fraction:
	fra.numerator = fra.numerator / greatestDivisor;
	fra.denominator = fra.denominator / greatestDivisor;
	
	int wholePart = fra.numerator / fra.denominator;
	int fractionPart = fra.numerator % fra.denominator;

	cout << "The fraction is: " << wholePart << "+ (" << fractionPart << "/" << fra.denominator << ")";
}

int main()
{

	return 0;
}

