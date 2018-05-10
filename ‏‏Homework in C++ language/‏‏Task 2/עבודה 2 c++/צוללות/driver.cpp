#include "Battleships.h"
#include "Game.h"
                                            //campus :beer-sheva ,name:oshri nachmani, ID:204566194
void main()
{
	int number_of_batlleships;
	cout<<"How many battleships do you want to place on board?\n";
	cin>>number_of_batlleships;// input the number of ships from the user
	Game obj(number_of_batlleships);
	_flushall();
		if(cin.fail())
		{
			cin.clear();
			number_of_batlleships=0;
		}
	obj.play();//play the game 
	
}
