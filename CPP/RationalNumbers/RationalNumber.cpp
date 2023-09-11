
#include "RationalNumber.h"

using namespace std;

RationalNumber::RationalNumber()
: numerator(0), denominator(0) {

}

RationalNumber::RationalNumber(int n, int d)
: numerator(n), denominator(d) {
    if(d == 0){
        throw std::invalid_argument("The denominator cannot be 0.");
    }
    if(d < 0){
        this->numerator *= -1;
        this->denominator *= -1;
    }
}

RationalNumber::RationalNumber(const RationalNumber &nrn)
: numerator(nrn.numerator), denominator(nrn.denominator) {
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