#include "Game.h"
#include "Digit.h"
#include "Number.h"

Game::Game()//Ctor that allocate memory
{
	userNumber=new Number;
	compNumber=new Number;

}
Game::~Game()//Dtor that free memory
{
	delete userNumber;
	delete compNumber;
}
Game::Game(Game const&other)//CopyConstactor 
{
	userNumber=new Number;
	compNumber=new Number;

	for(int i=0;i<4;i++)//loop that copies pointer cells
	{
		(userNumber->getNumber())[i].setValue((other.userNumber->getNumber()[i]).getValue());
		(compNumber->getNumber())[i].setValue((other.compNumber->getNumber()[i]).getValue());
	}
}
int Game::bull()//the function check if the user have same digit like the computer number they are at same location
{
	int count=0;

	for (int i=3;i>=0;i--)
	{
		if ( (userNumber->getNumber() )[i].equal( compNumber->Location(i) ) )
			count++;
	}
	return count;// Returns the number of times that Bull's-eye 
}
int Game::cow()//the function check if the user have same digit like the computer number and they are at differnte location
{
	int count=0;
	for(int i=3;i>=0;i--)
		for (int j=3;j>=0;j--)
			if( (compNumber->getNumber())[j].equal( (userNumber->getNumber() )[i].getValue() ) )
				count++;

	count=count-bull();
	return count;// Returns the number of times that the conditions are met
}
void Game::play()//the function play the game
{
	compNumber->RandomDigits();
	cout<<"the comuter number is : \n"<<*compNumber;

	int num=0;
do{	do{//loop in loop that check correct inputs and if the user guss the number
	
		cout<<"enter number with 4 digits\n";
		cin>>num;
		_flushall();
		if(cin.fail())//check if the input is 'char' and not 'int'
		{
			cin.clear();
			num=0;
		}
	}while((userNumber->SameDigits(num))&&(cout<<"\n***Eror, your number is ilegal !***\n\n"));
	userNumber->InputFromUser(num);
	cout<<"\t"<<bull()<<"    "<<cow()<<endl;
	
}while((bull()<4)&&(cout<<"you have another try !\n") );
cout<<"Congratulations! You guessed the exact number!\n";
}