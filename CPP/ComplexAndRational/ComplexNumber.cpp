
#include "ComplexNumber.h"
#include <cmath>

using namespace std;

ComplexNumber::ComplexNumber(double r, double i)
    : real(r), imag(i)
{
    this->real = RationalNumber(r*PRECISION,PRECISION);
    this->imag = RationalNumber(i*PRECISION,PRECISION);
}

ComplexNumber::ComplexNumber(const ComplexNumber &ncn) : real(ncn.getReal()), imag(ncn.getImag())
{
}

ComplexNumber::~ComplexNumber()
{
}

void ComplexNumber::setReal(double r)
{
    this->real = RationalNumber(r*this->PRECISION,this->PRECISION);
}

void ComplexNumber::setImag(double i)
{
    this->imag = RationalNumber(i*this->PRECISION,this->PRECISION);
}

double ComplexNumber::getReal() const
{
    return (double)this->real.getNumerator() / (double)this->real.getDenominator();
}

double ComplexNumber::getImag() const
{
    return (double)this->imag.getNumerator() / (double)this->imag.getDenominator();
}

string ComplexNumber::toString() const
{
    return to_string(this->getReal()) + (this->getImag() < 0 ? " - " : " + ") + to_string(this->getImag()) + "i";
}

ComplexNumber ComplexNumber::add(const ComplexNumber &rhs) const
{
    return ComplexNumber(this->getReal() + rhs.getReal(), this->getImag() + rhs.getImag());
}

ComplexNumber ComplexNumber::sub(const ComplexNumber &rhs) const
{
    return ComplexNumber(this->getReal() - rhs.getReal(), this->getImag() - rhs.getImag());
}

ComplexNumber ComplexNumber::mult(const ComplexNumber &rhs) const
{
    return ComplexNumber(this->getReal() * rhs.getReal() - this->getImag() * rhs.getImag(), this->getReal() * rhs.getImag() + this->getImag() * rhs.getReal());
}

ComplexNumber ComplexNumber::div(const ComplexNumber &rhs) const
{
    if (rhs.getReal() == 0 && rhs.getImag() == 0)
    {
        throw "Cannot divide by zero";
    }
    return ComplexNumber((this->getReal() * rhs.getReal() + this->getImag() * rhs.getImag()) / (rhs.getReal() * rhs.getReal() + rhs.getImag() * rhs.getImag()), (this->getImag() * rhs.getReal() - this->getReal() * rhs.getImag()) / (rhs.getReal() * rhs.getReal() + rhs.getImag() * rhs.getImag()));
}

double ComplexNumber::mag() const
{
    return std::sqrt(this->getReal() * this->getReal() + this->getImag() * this->getImag());
}

ComplexNumber ComplexNumber::conj() const
{
    return ComplexNumber(this->getReal(), -this->getImag());
}

ComplexNumber ComplexNumber::sqrt() const
{
    if (this->getImag() == 0)
    {
        if (this->getReal() < 0)
        {
            return ComplexNumber(0, std::sqrt(-this->getReal()));
        }
        else
        {
            return ComplexNumber(std::sqrt(this->getReal()), 0);
        }
    }
    else
    {
        double r = (std::sqrt((this->getReal() + std::sqrt(this->getReal() * this->getReal() + this->getImag() * this->getImag())) / 2));
        double i = (std::sqrt(-this->getReal() + std::sqrt(this->getReal() * this->getReal() + this->getImag() * this->getImag()) / 2));
        return ComplexNumber(r, i);
    }
}

bool ComplexNumber::equals(const ComplexNumber &rhs) const
{
    return rhs.getReal() == this->getReal() && rhs.getImag() == this->getImag();
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber&rhs) {
    this->real.setNumerator(rhs.real.getNumerator());
    this->real.setDenominator(rhs.real.getDenominator());
    this->imag.setDenominator(rhs.imag.getDenominator());
    this->imag.setNumerator(rhs.imag.getNumerator());
    return *this;
}