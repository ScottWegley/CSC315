
#include "RationalNumber.h"
#include <cmath>
#include <inttypes.h>

using namespace std;

RationalNumber::RationalNumber(int64_t n, int64_t d)
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

string RationalNumber::toString() const
{
    int tempNum = this->numerator;
    int tempDen = this->denominator;
    int prefix = 0;
    while (tempNum >= tempDen)
    {
        prefix++;
        tempNum -= tempDen;
    }
    int gcd = eucGCD(tempNum, tempDen);
    return ((prefix != 0 ? to_string(prefix) + "  " : "")) + (tempNum == 0 ? "0" : to_string(tempNum / gcd) + " / " + to_string(tempDen / gcd));
}

bool RationalNumber::equals(const RationalNumber &rhs) const
{
    return this->numerator == rhs.getNumerator() && this->denominator == rhs.getDenominator();
}

int64_t RationalNumber::getNumerator() const
{
    return this->numerator;
}

int64_t RationalNumber::getDenominator() const
{
    return this->denominator;
}

RationalNumber::~RationalNumber()
{
}

void RationalNumber::setNumerator(int64_t _n){
    this->numerator = _n;
    return;
}

void RationalNumber::setDenominator(int64_t _d){
    if(_d == 0){
        throw "Denominator cannot equal 0.";
    }
    this->denominator = _d;
    return;
}

int64_t RationalNumber::eucGCD(int64_t a, int64_t b) const
{
    a = std::abs(a);
    b = std::abs(b);
    if (a == 0)
    {
        return 1;
    }
    int temp = 0;
    do
    {
        temp = b % a;
        b = a;
        a = temp;
    } while (temp != 0);
    return b;
}