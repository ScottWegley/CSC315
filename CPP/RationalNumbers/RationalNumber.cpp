
#include "RationalNumber.h"

using namespace std;

RationalNumber::RationalNumber(int n = 0, int d = 0)
    : numerator(n), denominator(d)
{
    if (d == 0)
    {
        throw "The denominator cannot be 0.";
    }
    if (d < 0)
    {
        this->numerator *= -1;
        this->denominator *= -1;
    }
}

RationalNumber::RationalNumber(const RationalNumber &nrn)
    : numerator(nrn.numerator), denominator(nrn.denominator)
{
}

RationalNumber RationalNumber::add(const RationalNumber &rhs) const
{
    return RationalNumber(this->numerator * rhs.getDenominator() + this->denominator * rhs.getNumerator(), this->denominator * rhs.getDenominator());
}

RationalNumber RationalNumber::sub(const RationalNumber &rhs) const
{
    return RationalNumber(this->numerator * rhs.getDenominator() - this->denominator * rhs.getNumerator(), this->denominator * rhs.getDenominator());
}

RationalNumber RationalNumber::mult(const RationalNumber &rhs) const
{
    return RationalNumber(this->numerator * rhs.getNumerator(), this->denominator * rhs.getDenominator());
}

RationalNumber RationalNumber::div(const RationalNumber &rhs) const
{
    if (rhs.getNumerator() == 0)
        throw "Divide By Zero Exception";
    return RationalNumber(this->numerator * rhs.getDenominator(), this->denominator * rhs.getNumerator());
}

double RationalNumber::sqrt() const
{
    if (this->numerator < 0)
    {
        throw "Cannot square root a negative number";
    }
    else
    {
        return std::sqrt((double)this->numerator / (double)this->denominator);
    }
}

}

RationalNumber RationalNumber::add(const RationalNumber &rhs){
    return RationalNumber(this->numerator * rhs.denominator + this->denominator * rhs.numerator, this->denominator * rhs.denominator);
}

int RationalNumber::getNumerator(){
    return this->numerator;
}

int RationalNumber::getDenominator(){
    return this->denominator;
}