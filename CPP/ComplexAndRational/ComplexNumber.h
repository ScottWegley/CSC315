#pragma ComplexNumber_h

#include <iostream>
#include <string>
#include "RationalNumber.h"

using namespace std;

class ComplexNumber
{

private:
    RationalNumber real;
    RationalNumber imag;
    const double PRECISION = 100000;
public:
    ComplexNumber(double r=0,double i=0);
    ComplexNumber(const ComplexNumber &ncn);
    ~ComplexNumber();

    void setReal(double r);
    void setImag(double i);

    double getReal() const;
    double getImag() const;

    string toString() const;

    ComplexNumber add(const ComplexNumber &rhs) const;
    ComplexNumber sub(const ComplexNumber &rhs) const;
    ComplexNumber mult(const ComplexNumber &rhs) const;
    ComplexNumber div(const ComplexNumber &rhs) const;

    double mag() const;
    ComplexNumber conj() const;
    ComplexNumber sqrt() const;
    bool equals(const ComplexNumber &rhs) const;

    ComplexNumber& operator=(const ComplexNumber& rhs);
};