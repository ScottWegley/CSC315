#include <iostream>
#include "Object.h"

using namespace std;

int main()
{
    int arr[] = {0, 1, 2};

    for (int i = 0; i < 3; i++)
    {
        cout << hex << arr[i] << " ";
    }
    cout << endl;

    int *parr;
    parr = new int[3];
    for (int i = 0; i < 3; i++)
    {
        cout << hex << parr[i] << " ";
    }
    cout << endl;

    delete[] parr;

    Object obj;
    Object *pobj = new Object[3];

    

    return 0;
}