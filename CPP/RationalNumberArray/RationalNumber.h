
#pragma RationalNumber_h

#include <iostream>
#include <string>
#include <inttypes.h>

using namespace std;

class RationalNumber
{

public:
    RationalNumber(int64_t n = 0, int64_t d = 1);
    RationalNumber(const RationalNumber &nrn);
    ~RationalNumber();

    int64_t getNumerator() const;
    int64_t getDenominator() const;

    RationalNumber add(const RationalNumber &rhs) const;
    RationalNumber sub(const RationalNumber &rhs) const;
    RationalNumber mult(const RationalNumber &rhs) const;
    RationalNumber div(const RationalNumber &rhs) const;
    double sqrt() const;
    string toString() const;
    bool equals(const RationalNumber &rhs) const;
    void setNumerator(int64_t _n);
    void setDenominator(int64_t _d);

private:
    int64_t numerator;
    int64_t denominator;

    int64_t eucGCD(int64_t a, int64_t b) const;
};
