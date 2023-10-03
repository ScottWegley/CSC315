#pragma once
#include <iostream>

using namespace std;

class Object
{
public:
    int x;

public:
    Object() {}
    Object(int _x) : x(_x) {}
    ~Object() { cout << " Destructing an object" << endl; }
};