#include "RationalNumberArray.h"
#include <iostream>

using namespace std;

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

RationalNumberArray::RationalNumberArray(const RationalNumberArray &rhs) : RationalNumberArray(rhs.rows, rhs.cols)
{
    for (int i = 0; i < rhs.rows; i++)
    {
        for (int j = 0; j < rhs.cols; j++)
        {
            this->data[i][j] = rhs.getCell(i, j);
        }
    }
}

RationalNumberArray::~RationalNumberArray()
{
    delete[] this->data[0];
    delete[] this->data;
}

string RationalNumberArray::toString()
{
    string out = "";
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->rows; j++)
        {
            out = out + this->data[i][j].toString() + "\t";
        }
        out = out + '\n';
    }
    return out;
}

bool RationalNumberArray::equals(const RationalNumberArray &rhs) const
{
    if (this->rows != rhs.getRows() || this->cols != rhs.getCols())
    {
        return false;
    }
    for (int i = 0; i < rhs.getRows(); i++)
    {
        for (int j = 0; j < rhs.getCols(); j++)
        {
            if (!this->getCell(i, j).equals(rhs.getCell(i, j)))
            {
                return false;
            }
        }
    }
    return true;
}

double RationalNumberArray::getMean() const
{
    double sum = 0;
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            sum += (double)this->data[i][j].getNumerator() / (double)this->data[i][j].getDenominator();
        }
    }
    return sum / (this->rows * this->cols);
}
// -- returns the standard deviation as a double
double RationalNumberArray::getStdDev() const {}
int RationalNumberArray::getRows() const
{
    return this->rows;
}
int RationalNumberArray::getCols() const
{
    return this->cols;
}
// -- set cell value
void RationalNumberArray::setCell(int row, int col, const RationalNumber &value)
{
    this->data[row][col] = value;
}

RationalNumber RationalNumberArray::getCell(int row, int col) const
{
    return this->data[row][col];
}