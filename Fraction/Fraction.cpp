#include <iostream>

using namespace std;

// Class Definition
class Fraction
{
	int numerator;
	int denominator;

public:
	Fraction();
	~Fraction();
	void getNumDenom(int &pointNumerator, int &pointDenominator);
	void setNumDenom(int num, int denom);
	Fraction add(Fraction addend);
	Fraction subtract(Fraction subtrahend);
	Fraction multiply(Fraction multiplicand);
	Fraction divide(Fraction divisor);
	int gcd();
	void print();
};

// constructor
Fraction::Fraction()
{
	numerator = 0;
	denominator = 1; // Can't leave at zero because that is mathemaically nosensical
}

// destructor
Fraction::~Fraction()
{
}

// get function
void Fraction::getNumDenom(int &pointNumerator, int &pointDenominator)
{
	pointNumerator = numerator;
	pointDenominator = denominator;

}

// set function
void Fraction::setNumDenom(int num, int denom)
{
	numerator = num;

	if (denom != 0) // CHeck to make sure the denominator is not set to zero
	{
		denominator = denom;
	}
}

// adds fraction taken as parameter to the fraction object
Fraction Fraction::add(Fraction addend)
{
	Fraction answer;
	int ansDen = denominator * addend.denominator; // find LCM for denominator
	int ansNum = (numerator*addend.denominator) + (addend.numerator*denominator);

	answer.setNumDenom(ansNum,ansDen);

	return answer;
}

// subtracts fraction taken as parameter from the fraction object
Fraction Fraction::subtract(Fraction subtrahend)
{
	Fraction answer;
	int ansDen = denominator * subtrahend.denominator; // find LCM for denominator
	int ansNum = (numerator*subtrahend.denominator) - (subtrahend.numerator*denominator);

	answer.setNumDenom(ansNum, ansDen);

	return answer;
}

// multiplies fraction object with fraction taken as parameter
Fraction Fraction::multiply(Fraction multiplicand)
{
	Fraction answer;
	int ansDen = denominator * multiplicand.denominator; 
	int ansNum = numerator * multiplicand.numerator;

	answer.setNumDenom(ansNum, ansDen);

	return answer;
}

// divides fraction object with fraction taken as parameter
Fraction Fraction::divide(Fraction divisor)
{
	Fraction answer;
	int ansDen = denominator * divisor.numerator;
	int ansNum = numerator * divisor.denominator;

	answer.setNumDenom(ansNum, ansDen);

	return answer;
}

// Finds gcd of the numberator and denominator
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

// prints a simplified fraction in mixed number form
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
	// Testing part
	Fraction fra1, fra2;
	fra1.setNumDenom(4, 3);
	fra2.setNumDenom(2, 4);

	cout << "Fraction 1: "; 
	fra1.print();
	cout << "Fraction 2: "; 
	fra2.print();

	cout << endl; 

	cout << "Fraction 1 + Fraction 2: ";
	(fra1.add(fra2)).print();

	cout << "Fraction 1 - Fraction 2: ";
	(fra1.subtract(fra2)).print();

	cout << "Fraction 1 * Fraction 2: ";
	(fra1.multiply(fra2)).print();

	cout << "Fraction 1 / Fraction 2: ";
	(fra1.divide(fra2)).print();

	return 0;
}

