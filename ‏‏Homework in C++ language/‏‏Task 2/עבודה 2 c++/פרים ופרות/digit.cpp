#include <iostream>
#include "Digit.h"
using namespace std;
Digit::Digit():value(0){}//the Ctor reset the value

bool Digit:: equal(const int num )const//function that check if the value of num and value are equal
{
	return (num==value);
}
int  Digit::getValue() const//function that get the private variable
{
	return value;
}
void  Digit::setValue( const int digit) // function that set the variable value with 'digit'
 {
	 value=digit;
}

