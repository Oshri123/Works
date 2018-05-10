#include <iostream>
#ifndef Number_H
#define Number_H
 #include "Digit.h"
using namespace std;

class Number 
{
private:

Digit dig[4];

public:

Digit* getNumber(){return dig;};
Number();
void InputFromUser(const int digit);
void RandomDigits();
int Location(const int i) const;
friend ostream& operator << ( ostream& out, const Number& num);
int SameDigits(int num);
};
#endif

