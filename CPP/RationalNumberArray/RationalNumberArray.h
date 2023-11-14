#pragma RationalNumberArray

#include <iostream>
#include <string>
#include "RationalNumber.h"

using namespace std;

class RationalNumberArray
{
private:
    RationalNumber **data;
    int rows;
    int cols;

public:
    // -- constructs array[rows][cols]
    RationalNumberArray(int rows, int cols);
    // -- constructs a copy of the argument
    RationalNumberArray(const RationalNumberArray &rhs);
    // -- deletes all dynamic memory
    virtual ~RationalNumberArray();
    // -- returns the array as a string
    string toString();
    // -- compares two arrays for equality
    bool equals(const RationalNumberArray &rhs) const;
    // -- returns the mean value as a double
    double getMean() const;
    // -- returns the standard deviation as a double
    double getStdDev() const;
    int getRows() const;
    int getCols() const;
    // -- set cell value
    void setCell(int row, int col, const RationalNumber &value);
    RationalNumber getCell(int row, int col) const;
};