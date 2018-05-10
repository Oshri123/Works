#ifndef Digit_H
#define Digit_H
#include <iostream>
class Digit
{

private: 
	int value;

public:

	Digit();
	bool equal (const int num)const;
	int getValue() const;
	void setValue( const int digit) ;

};
#endif