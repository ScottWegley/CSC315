#include "RationalNumberArray.h"
#include <iostream>
#include <cmath>

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
    for (int i = 0; i < rhs.getRows(); i++)
    {
        for (int j = 0; j < rhs.getCols(); j++)
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
    for (int i = 0; i < getRows(); i++)
    {
        for (int j = 0; j < getCols(); j++)
        {
            out = out + this->data[i][j].toString() + "\t";
        }
        out = out + '\n';
    }
    return out;
}

bool RationalNumberArray::equals(const RationalNumberArray &rhs) const
{
    if (getRows() != rhs.getRows() || getCols() != rhs.getCols())
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
    for (int i = 0; i < getRows(); i++)
    {
        for (int j = 0; j < getCols(); j++)
        {
            sum += (double)getCell(i, j).getNumerator() / (double)getCell(i, j).getDenominator();
        }
    }
    return sum / (getRows() * getCols());
}
// -- returns the standard deviation as a double
double RationalNumberArray::getStdDev() const
{
    double mean = this->getMean();
    double stdDev = 0;
    for (int i = 0; i < getRows(); i++)
    {
        for (int j = 0; j < getCols(); j++)
        {
            double cNum = (double)getCell(i, j).getNumerator() / (double)getCell(i, j).getDenominator();
            stdDev += pow(cNum - mean, 2);
        }
    }
    return sqrt(stdDev / (getRows() * getCols()));
}

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
    if (row < 0 || col < 0)
    {
        throw "Cannot access a cell where one dimension is less than zero.";
    }
    this->data[row][col] = value;
}

RationalNumber RationalNumberArray::getCell(int row, int col) const
{
    return this->data[row][col];
}