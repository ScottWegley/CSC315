#include "RationalNumberArray.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    cout << "Test\n";
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
            this->data[i][j] = RationalNumber(j + i * cols + 1, 1);
        }
    }
}


RationalNumberArray::~RationalNumberArray(){
    delete[] this->data[0];
    delete[] this->data;
}
