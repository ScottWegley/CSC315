#include <iostream>
#include "DynamicClass.cpp"
using namespace std;

int main()
{
    // Declare a pointer to an int.
    int *p;

    // Dynamic Allocation
    p = new int[5];

    // Initialize memory
    for (int i = 0; i < 5; i++)
    {
        p[i] = i;
    }

    // Print the memory
    for (int i = 0; i < 5; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    // Return dynamic memory to available memory pool.
    delete[] p;

    // Pointer to a DyanmicClass
    DynamicClass *dc;

    // Dynamic Allocation with default constructor
    dc = new DynamicClass();
    cout << dc->toString() << endl;
    delete dc;

    // Dynamic allocation with over constructor.
    dc = new DynamicClass(27);
    cout << dc->toString() << endl;
    for (int i = 0; i < dc->getX(); i++)
    {
        cout << dc->getP()[i] << " ";
    }
    cout << endl;
    
    delete dc;

    // Dynamic allocation for array with default constructor
    dc = new DynamicClass[3];
    for (int i = 0; i < 3; i++)
    {
        cout << dc[i].toString() << endl;
    }
    delete[] dc;

    return 0;
}