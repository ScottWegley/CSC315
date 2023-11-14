#include "RationalNumberArray.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    cout << "Test\n";
    RationalNumberArray rna = RationalNumberArray(3, 5);
    return 0;
}

RationalNumberArray::RationalNumberArray(int rows, int cols) : rows(rows), cols(cols)
{
    if (rows <= 0)
    {
        throw "Cannot create an array with 0 or negative rows";
    }
    if (cols <= 0)
    {
        throw "Cannot create an array with 0 or negative columns";
    }

    this->data = new RationalNumber *[rows];

    for (int i = 0; i < rows; i++)
    {
        if (i == 0)
        {
            this->data[0] = new RationalNumber[rows * cols];
        }
        else
        {
            this->data[i] = this->data[i - 1] + cols;
        }
        for (int j = 0; j < cols; j++)
        {
            this->data[i][j] = RationalNumber(0, 1);
        }
    }
}

RationalNumberArray::RationalNumberArray(const RationalNumberArray &rhs):RationalNumberArray(rhs.rows,rhs.cols) {
    for(int i = 0; i < rhs.rows; i++){
        for(int j = 0; j < rhs.cols; j++){
            this->data[i][j] = rhs.getCell(i,j);
        }
    }
}

RationalNumberArray::~RationalNumberArray()
{
    delete[] this->data[0];
    delete[] this->data;
}

string RationalNumberArray::toString() {}

bool RationalNumberArray::equals(const RationalNumberArray &rhs) const {}

double RationalNumberArray::getMean() const {}
// -- returns the standard deviation as a double
double RationalNumberArray::getStdDev() const {}
int RationalNumberArray::getRows() const {}
int RationalNumberArray::getCols() const {}
// -- set cell value
void RationalNumberArray::setCell(int row, int col, RationalNumber &value) {}

RationalNumber RationalNumberArray::getCell(int row, int col) const {
    return this->data[row][col];
}