#include "Battleships.h"

int Battleships::courrentShip=0;//Resetting the static variable
Battleships::Battleships()//The constructor set the length of all the ships
{
	courrentShip++;//counting the number of ships that build
	switch (courrentShip)// build all ship at the suitable length
	{
	case 1:
		length=5;
		break;
	case 2:
		length=4;
		break;
	case 3:
		length=3;
		break;
	case 4:
		length=2;
		break;
	case 5:
		length=3;
		break;

	default: // if the value of "courrent ship" <=0 or > 5 we build 1 ship on size 5
		length=5;
		courrentShip=1;
		break;
	}
}
int Battleships::Getlength(){return length;}//get the length of the private variable
int Battleships::GetCourrentShips(){return courrentShip;}//get the value of the private variable