//
//  main.cpp
//  HelloWorld

// -- system header file
#include <iostream>
// -- project header file
#include "HelloWorld.h"

using namespace std;

// -- global (non-class method) function to show pass-by-value
void passbyvalue(HelloWorld hw)
{

}

// -- global (non-class method) function to show pass-by-reference
void passbyreference(HelloWorld &hw)
{

}

// -- global (non-class method) function to show pass-by-pointer
void passbypointer(HelloWorld* hw)
{

}

// -- The main() function is the application entry point.
//    It is global, it does not belong to any class and
//    there can only be one of them
int main(int argc, const char * argv[]) {
    
    cout << endl << "Demonstrate objects" << endl;
    HelloWorld hw0;
    HelloWorld hw1("Dr. Reinhart");
    HelloWorld hw2(hw1);
    HelloWorld *pHw = new HelloWorld("pointer");

    cout << hw0.toString() << endl;
    cout << hw1.toString() << endl;
    cout << hw2.toString() << endl;
    hw2.setMessage("Prof. Reinhart");
    cout << hw2.toString() << endl;

    cout << pHw->toString() << endl;
    
    cout << endl << "Demonstrate array of objects" << endl;
    // -- array of objects always used default constructor
    HelloWorld array[5];
    
    // -- the number of elements in an array of objects can be calculated using
    //    sizeof(array) / sizeof(array[0])
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
        array[i].setMessage("location " + to_string(i));
    }
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
        cout << array[i].toString() << endl;
    }
    
    cout << endl << "Demonstrate pointer to array of objects" << endl;
    // -- array of objects always used default constructor
    HelloWorld *pArray = new HelloWorld[3];
    // -- no way to compute the number of elements in an array of pointers to objects
    for (int i = 0; i < 3; ++i) {
        pArray[i].setMessage("pointer " + to_string(i));
    }
    for (int i = 0; i < 3; ++i) {
        cout << pArray[i].toString() << endl;
    }
    cout << endl;
   
    // -- array of objects always used default constructor
    HelloWorld** ppArray = new HelloWorld*[3];
    // -- no way to compute the number of elements in an array of pointers to objects
    for (int i = 0; i < 3; ++i) {
        ppArray[i] = new HelloWorld("pointer " + to_string(i));
    }
    for (int i = 0; i < 3; ++i) {
        cout << ppArray[i]->toString() << endl;
    }
    cout << endl;

    // -- various global function calls
    //    notice which ones call the copy constructor
    cout << "pass by value" << endl;
    passbyvalue(hw0);
    cout << endl;
    cout << "pass by reference" << endl;
    passbyreference(hw0);
    cout << endl;
    cout << "pass by pointer" << endl;
    passbypointer(&hw0);
    cout << endl;

    cout << endl << "Demonstrate object destruction" << endl;
    // use delete to destruct individual dynamic objects
    delete pHw;
    // -- use delete [] to destruct an array of objects
    delete[] pArray;

    for (int i = 0; i < 3; ++i) {
        delete ppArray[i];
    }
    delete[] ppArray;

    // -- other objects will merely go out of scope
    cout << "Destruction of out of scope objects" << endl;

    return 0;
}
