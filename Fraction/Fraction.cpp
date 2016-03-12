/*
	Eustacia Rajman
	214514354
	ENEL3CC - Computer Methods 3
	Tut2-Fraction
*/

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
	Fraction operator+(const Fraction& addend);
	Fraction operator-(const Fraction& subtrahend);
	Fraction operator*(const Fraction& multiplicand);
	Fraction operator/(const Fraction& divisor);
	friend ostream& operator<< (ostream&, Fraction&);
	friend ostream& operator>> (ostream&, Fraction&);
	int gcd();
	void print();
};

// constructor
Fraction::Fraction()
{
	numerator = 0;
	denominator = 1; // Can't leave at zero because that is mathematically nonsensical
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
Fraction Fraction::operator+(const Fraction& addend)
{
	Fraction answer;
	int ansDen = denominator * addend.denominator; // find LCM for denominator
	int ansNum = (numerator*addend.denominator) + (addend.numerator*denominator);
	
	answer.setNumDenom(ansNum,ansDen);
	
	return answer;
}

// subtracts fraction taken as parameter from the fraction object
Fraction Fraction::operator-(const Fraction& subtrahend)
{
	Fraction answer;
	int ansDen = denominator * subtrahend.denominator; // find LCM for denominator
	int ansNum = (numerator*subtrahend.denominator) - (subtrahend.numerator*denominator);
	
	answer.setNumDenom(ansNum, ansDen);
	
	return answer;
}

// multiplies fraction object with fraction taken as parameter
Fraction Fraction::operator*(const Fraction&  multiplicand)
{
	Fraction answer;
	int ansDen = denominator * multiplicand.denominator; 
	int ansNum = numerator * multiplicand.numerator;
	
	answer.setNumDenom(ansNum, ansDen);
	
	return answer;
}

// divides fraction object with fraction taken as parameter
Fraction Fraction::operator/(const Fraction&  divisor)
{
	Fraction answer;
	int ansDen = denominator * divisor.numerator;
	int ansNum = numerator * divisor.denominator;
	
	answer.setNumDenom(ansNum, ansDen);
	
	return answer;
}

// Overload << operator
ostream& operator<< (ostream& output, Fraction& fra)
{
	int greatestDivisor = fra.gcd();

	// simplify original fraction:
	int simpNumerator = fra.numerator / greatestDivisor;
	int simpDenominator = fra.denominator / greatestDivisor;

	int wholePart = simpNumerator / simpDenominator;
	int fractionPart = simpNumerator % simpDenominator;

	// 
	if (wholePart != 0)
	{
		output << wholePart << " " << fractionPart << "/" << simpDenominator;
	}
	else
	{
		output << fractionPart << "/" << simpDenominator;
	}

	return output;
}

// Overload >> operator non-mixed fraction
istream& operator>> (istream& input, Fraction& fra)
{
	int num, denom;

	input >> num;
	input.ignore(1, '/');
	input >> denom;
	input.ignore(1, '/');
	fra.setNumDenom(num, denom);
	return input;
}



// Finds gcd of the numerator and denominator
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
// this method is now "obsolete" because the << operator is now overloaded
void Fraction::print()
{
	int greatestDivisor = gcd();

	// simplify original fraction:
	int simpNumerator = numerator / greatestDivisor;
	int simpDenominator = denominator / greatestDivisor;

	int wholePart = simpNumerator / simpDenominator;
	int fractionPart = simpNumerator % simpDenominator;

	// 
	if (wholePart != 0)
	{
		cout << wholePart << " " << fractionPart << "/" << simpDenominator << endl;
	}
	else
	{
		cout << fractionPart << "/" << simpDenominator << endl;
	}
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
	(fra1 + fra2).print();
	
	cout << "Fraction 1 - Fraction 2: ";
	(fra1 - fra2).print();

	// Special case of subtraction where answer returned gives a negative answer
	cout << "Fraction 2 - Fraction 1: ";
	(fra2 - fra1).print();
	
	cout << "Fraction 1 * Fraction 2: ";
	(fra1 * fra2).print();
	
	cout << "Fraction 1 / Fraction 2: ";
	(fra1 / fra2).print();
	
	cout << "Testing overloading of <<  operator:" << endl;
	cout << "Fraction 1: " << fra1 << endl;

	cout << "Testing overloading of >>  operator:  Enter fraction in format [numerator]/[denminator] (no spaces)" << endl;
	Fraction fra3;
	cin >> fra3;
	cout << fra3;

	return 0;
}

