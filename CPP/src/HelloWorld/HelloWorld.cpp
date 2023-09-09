//
//  HelloWorld.cpp
//  HelloWorld

#include "HelloWorld.h"

using namespace std;


HelloWorld::HelloWorld()
// -- initialize member varialbe before full construction
: message("<no name>")
{
    // -- can do this instead of an initializer
    // this->message = "<no name>";
    cout << "default constructor" << endl;
}

// -- overload constructor
HelloWorld::HelloWorld(string message)
: message(message)
{
    // -- can do this instead of an initializer
    // this->message = message;
    cout << "overload constructor" << endl;
}

// -- copy constructor
HelloWorld::HelloWorld(const HelloWorld &src)
: message(src.message)
{
    // -- can do this instead of an initializer
    // this->message = src.message;
    cout << "copy constructor" << endl;
}

// -- destructor
HelloWorld::~HelloWorld()
{
    cout << "destructing " << message << endl;
}

string HelloWorld::toString()
{
   return "Hello, " +  message;
}
