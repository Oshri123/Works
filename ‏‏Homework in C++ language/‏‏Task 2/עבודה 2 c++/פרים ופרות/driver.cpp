#include <iostream>
#include "Number.h"
#include "Digit.h"
#include "Game.h"

using namespace std;
int main()
{
	char new_game;
	do { //loop that reset the game if the user want new game
	Game obj;
	obj.play();
	Game c(obj);//check if the copy constractor work
	cout<<"New game ? [y/n]\n";
	_flushall();
	cin>>new_game;
	}while(new_game == 'y' || new_game == 'Y');
	return 0;
}