#pragma DynamicArray

#include <iostream>
#include <string>

using namespace std;

template <typename T> class DynamicArray
{
private:
    T **data;
    int rows;
    int cols;

public:
    // -- constructs array[rows][cols]
    DynamicArray(int rows, int cols);
    // -- constructs a copy of the argument
    DynamicArray(const DynamicArray &rhs);
    // -- deletes all dynamic memory
    virtual ~DynamicArray();
    // -- returns the array as a string
    string toString();
    int getRows() const;
    int getCols() const;
    // -- set cell value
    void setCell(int row, int col, const T &value);
    T getCell(int row, int col) const;
};