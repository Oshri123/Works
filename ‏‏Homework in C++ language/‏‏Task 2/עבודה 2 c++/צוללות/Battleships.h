#include <iostream>
#ifndef Battleships_H
#define Battleships_H
using namespace std;

class Battleships{

private:
	int length;
	static int courrentShip;
public:
	Battleships();
	int Getlength();
	int GetCourrentShips();
};
#endif