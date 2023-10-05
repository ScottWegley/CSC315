#pragma once
#include <string>

using namespace std;
class DynamicClass
{
public:
    DynamicClass();
    DynamicClass(const int x);
    DynamicClass(const DynamicClass &dc);

    int getX() { return x; };
    int *getP() { return p; }

    string toString() { return "DynamicClass: x = " + to_string(getX()); };

    ~DynamicClass();
private:
    int x;
    int *p;
};