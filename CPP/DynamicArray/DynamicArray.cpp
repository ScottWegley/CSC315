#include <iostream>
#include <cmath>
#include <sstream>
#include "DynamicArray.h"

using namespace std;

template <typename T>
DynamicArray<T>::DynamicArray(int rows, int cols) : rows(rows), cols(cols)
{
    if (rows <= 0)
    {
        throw "Cannot create an array with 0 or negative rows";
    }
    if (cols <= 0)
    {
        throw "Cannot create an array with 0 or negative columns";
    }

    this->data = new T *[rows];
    this->data[0] = new T[rows * cols];
    for (int i = 1; i < rows; i++)
    {
        this->data[i] = this->data[i - 1] + cols;
    }
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray &rhs) : DynamicArray(rhs.rows, rhs.cols)
{
    for (int i = 0; i < rhs.getRows(); i++)
    {
        for (int j = 0; j < rhs.getCols(); j++)
        {
            this->data[i][j] = rhs.getCell(i, j);
        }
    }
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] this->data[0];
    delete[] this->data;
}

template <typename T>
string DynamicArray<T>::toString()
{
    stringstream s;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            s << data[i][j] << "\t";
        }
        s << "\n";
    }
    return s.str();
}

template <typename T>
int DynamicArray<T>::getRows() const
{
    return this->rows;
}

template <typename T>
int DynamicArray<T>::getCols() const
{
    return this->cols;
}

// -- set cell value
template <typename T>
void DynamicArray<T>::setCell(int row, int col, const T &value)
{
    if (row < 0 || col < 0)
    {
        throw "Cannot access a cell where one dimension is less than zero.";
    }
    this->data[row][col] = value;
}

template <typename T>
T DynamicArray<T>::getCell(int row, int col) const
{
    return this->data[row][col];
}