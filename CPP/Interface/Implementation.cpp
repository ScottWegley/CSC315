#include <iostream>
#include "Implementation.h"

using namespace std;

Implementation::Implementation() : x(0)
{
  cout << "Implementation default constructor" << endl;
}

Implementation::Implementation(int x) : x(x)
{
	cout << "Implementation overload constructor" << endl;
}

Implementation::Implementation(Implementation& i) : x(i.x)
{
	cout << "Implementation copy constructor" << endl;
}

Implementation::~Implementation()
{
  cout << "Implementation destructor" << endl;
}

void Implementation::Function01()
{
  cout << "Implementation Function01()" << endl;
}

void Implementation::Function01(int n)
{
  cout << "Implementation Function01(int n)" << endl;
}

void Implementation::Function02()
{
  cout << "Implementation Function02()" << endl;
}
