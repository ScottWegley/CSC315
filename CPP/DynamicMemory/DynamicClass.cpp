#include "DynamicClass.h"

DynamicClass::DynamicClass() : x(0), p(0){};
DynamicClass::DynamicClass(const int x) : x(x)
{
    p = new int[x];
    for (int i = 0; i < x; i++)
    {
        p[i] = 0;
    }
};
DynamicClass::DynamicClass(const DynamicClass &dc) : x(dc.x){
    p = new int[x];
    for (int i = 0; i < x; i++)
    {
        p = new int[x];
        for(int i = 0; i < x; i++){
            p[i] = dc.p[i];
        }
    }
};
DynamicClass::~DynamicClass(){
    if(p!=0){
        delete[] p;
    }
}