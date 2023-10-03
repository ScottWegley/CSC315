#pragma once
#include "Interface.h"

class Implementation : public Interface
{
public:
	// -- must provide constructors
	Implementation();
	Implementation(int x);
	Implementation(Implementation& i);

	virtual ~Implementation();
	
	// -- provide implementations of the pure virtual functions
	//    best to make this virtual (more on this later)
	virtual void Function01();
	virtual void Function01(int n);
	virtual void Function02();

private:
	int x;
};
