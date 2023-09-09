//
//  HelloWorld.h
//  HelloWorld

// -- pre-compiler guard to prevent circular includes
//    can also use #pragma once
#ifndef HelloWorld_h
#define HelloWorld_h

// -- some common standard include files
//    <> tells the pre-compiler to search the system directories
//    "" tells the pre-compiler to search the current directories
#include <string>
#include <cmath>
#include <iostream>

// -- set the default namespace, avoids having to do std:: on objects/methods
using namespace std;

class HelloWorld {

// -- set up a public section
//    can include member variables and functions
//    can have multiple public sections, they do not have to be contiguous in the file
 public:
    // -- default constructor
    HelloWorld();
    // -- overload constructyor
    HelloWorld(string message);
    // -- copy constructor
    HelloWorld(const HelloWorld &message);
    // -- destructor
    ~HelloWorld();

    // -- additional methods (message handlers)
    // -- methods can be declared in the header file and define in the source file

    // -- there is no built-in toString function, you must write your own and call it
    //    when needed
    string toString();
    
    // -- methods can be declared and defined in the header file
    //    usually reserved for short methods or special cases (templates -- more later)
    string getMessage() {
        // -- this is a pointer in C++ (a reference in Java)
        return this->message;
    }
    void setMessage(string message) {
        this->message = message;
    }
    
// -- set up a private section
//    can include member variables and functions
//    can have multiple private sections, they do not have to be contiguous in the file
private:
    string message;
    
}; // -- don't forget the semi-colon
#endif /* HelloWorld_h */
