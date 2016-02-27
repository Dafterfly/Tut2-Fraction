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
	int gcd();
	void print();
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

int Fraction::gcd()
{
	int larger, smaller, temp;

	//determine whether denom or numerator is larger or smaller
	if (numerator > denominator)
	{
		larger = numerator;
		smaller = denominator;
	}
	else
		{
			larger = denominator;
			smaller = numerator;
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

void Fraction::print()
{
	int greatestDivisor = gcd();

	// simplify original fraction:
	int simpNumerator = numerator / greatestDivisor;
	int simpDenominator = denominator / greatestDivisor;
	
	int wholePart = simpNumerator / simpDenominator;
	int fractionPart = simpNumerator % simpDenominator;

	cout << wholePart << " + (" << fractionPart << "/" << simpDenominator << ")" << endl;
}

int main()
{
	return 0;

}

