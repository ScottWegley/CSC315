
#pragma RationalNumber_h

#include <iostream>
#include <string>

using namespace std;

class RationalNumber {

public:
RationalNumber();
RationalNumber(int n, int d);
RationalNumber(const RationalNumber &nrn);
~RationalNumber();

int getNumerator();
int getDenominator();

RationalNumber add(const RationalNumber &rhs);
RationalNumber sub(const RationalNumber &rhs);
RationalNumber mult(const RationalNumber &rhs);
RationalNumber div(const RationalNumber &rhs);
double sqrt();
string toString();
bool equals(const RationalNumber &rhs);

private:
int numerator;
int denominator;

int eucGCD(int a, int b);
};
