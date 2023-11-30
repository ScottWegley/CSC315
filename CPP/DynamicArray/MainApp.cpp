#include <iostream>
#include "DynamicArray.h"

int main(int argc, char **argv)
{
    DynamicArray<int> *dmi = new DynamicArray<int>(2, 3);
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            dmi->setCell(i, j, i * 3 + j);
        }
    }
    cout << dmi->toString() << endl;
    DynamicArray<double> *dmd = new DynamicArray<double>(2, 3);
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            dmd->setCell(i, j, (double)(i * 3 + j) / 6.0);
        }
    }
    cout << dmd->toString() << endl;
    DynamicArray<double> *dmdcopy = new DynamicArray<double>(*dmd);
    cout << dmdcopy->toString() << endl;
    DynamicArray<string> *dms = new DynamicArray<string>(2, 3);
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            dms->setCell(i, j, "value: " + to_string(i * 3 + j));
        }
    }
    cout << dms->toString() << endl;
    return 0;
}