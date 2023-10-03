#pragma once
class Interface
{
public:
	// -- an interface is [essentially] a class that 
	//    contains only pure-virtual functions
	virtual void Function01() = 0;
	virtual void Function01(int n) = 0;
	virtual void Function02() = 0;
};
