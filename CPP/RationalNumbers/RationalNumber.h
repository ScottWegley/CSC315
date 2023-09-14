
#pragma RationalNumber_h

#include <iostream>
#include <string>

using namespace std;

class RationalNumber
{

public:
    RationalNumber(int n = 0, int d = 1);
    RationalNumber(const RationalNumber &nrn);
    ~RationalNumber();

    int getNumerator() const;
    int getDenominator() const;

    RationalNumber add(const RationalNumber &rhs) const;
    RationalNumber sub(const RationalNumber &rhs) const;
    RationalNumber mult(const RationalNumber &rhs) const;
    RationalNumber div(const RationalNumber &rhs) const;
    double sqrt() const;
    string toString() const;
    bool equals(const RationalNumber &rhs) const;
    void setNumerator(int _n);
    void setDenominator(int _d);

private:
    int numerator;
    int denominator;

    int eucGCD(int a, int b) const;
};
