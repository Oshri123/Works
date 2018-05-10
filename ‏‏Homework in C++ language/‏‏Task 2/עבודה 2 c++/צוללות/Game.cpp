#include "Battleships.h"
#include "Game.h"
#include <ctime>

int Game::occupied=0;//Resetting the static variable
Game::Game(int number_of_ships)//The constructor get the number of ships from the user and allocates memory to the pointer "ships"
{
	if(number_of_ships<=0||number_of_ships>5)//check if the user insert '0' to number_of_ships
		number_of_ships=1;

	ships= new Battleships[number_of_ships];

	switch ( number_of_ships ) //set the static variable occupied
	{
	
	case 1:
		occupied=5;
		break;
	case 2:
		occupied=9;
		break;
	case 3:
		occupied=12;
		break;
	case 4:
		occupied=14;
		break;
	case 5:
		occupied=17;
		break;
	default :
		occupied=5;
		break;
	}
}
Game::~Game()
{
	delete[] ships; //Release mamory
} 
void Game::ClearBoard() //Function to reset the game board
{
	for(int i=0;i<M;i++)
		for(int j=0;j<M;j++)
			board[i][j]='_';
}
int Game::ChecklPlaceVertical(int line, int collum,int size)//An assistance function that checks whether a ship can be put vertical
{

	int	k,godel=(line+size+1);

	if (line==0)//check if have deviation at the array
		k=line;
	else k=line-1;

	if (line==9)//check if have deviation at the array
		godel--;

	for(int i=k;  i < godel ;i++)
		if( (board[i][collum]=='S') || (board[i][collum-1]=='S')  || (board[i][collum+1]=='S') )
			return 0;

	return 1;

}
int Game::ChecklPlaceHorizontal(int line, int collum,int size)//An assistance function that checks whether a ship can be put horizontal
{
	int k,godel = collum+size+1 ;

	if (collum==0)//check if have deviation at the array
		k=collum;
	else k=collum-1;

	if (collum==9)//check if have deviation at the array
		godel--;

	for(int i=k ; i < godel ;i++)
		if( (board[line][i]=='S') || (board[line-1][i]=='S') || (board[line+1][i]=='S') )
			return 0;

	return 1;
}
int Game::CheckPlace(int line, int collum,int size,int choice)//The main function that checks whether a ship can be put vertical or horizontal
{
	if( ( (line+size)> M) || ((collum+size)> M) )// check if there is enough space to place the ship starting from the current place
		return 0;

	if(choice==1)//If drawn 1 to choice , the function of the vertical activated
		if(ChecklPlaceVertical(line,collum,size))
			return 1;
		else return 0;

		if(choice==2)//If drawn 2 to choice , the function of the horizontal activated
			if( ChecklPlaceHorizontal(line,collum,size) )
				return 1;

			else return 0;// if there is not enough space returned 0
}
void Game::BuildBoard()//Function that used to place the ships on the board

{
	srand(time(NULL));
	int CourrentShips=ships->GetCourrentShips();//Finding amount of ships
	for(int i=0; i<CourrentShips ; i++)//loop that drawn random numbers to place the ships on the board
	{
		int choice = (rand()%2+1);//random number for place the ship vertical or horizontal
		int line = (rand()%9+0);//random number for the number of the line on the board
		int collum=(rand()%9+0);//random number for the number of the collum on the board
		if(CheckPlace(line,collum,ships[i].Getlength(),choice))//activate the function that checks whether a ship can be put
		{
			if(choice==1)
				for(int j=line; j<line+ships[i].Getlength() ; j++)
					board[j][collum]='S';

			else if (choice==2)
				for(int j=collum; j<collum+ships[i].Getlength() ; j++)
					board[line][j]='S';
		}
		else i--;
	}
}
void Game::Printboard()//A function that prints the current board after all attempts to compromise
{
	cout<<"   ";
	for(char i='A';i<'K';i++)
		cout<<i<<"  ";
	cout<<endl<<endl;
	for(int i=0; i<M;i++)
	{
		if(i==9)
			cout<<i+1<<" ";
		else cout<<i+1<<"  ";
		for (int j=0;j<M;j++)
		{
			if (board[i][j]=='S')
				cout<<"_"<<"  ";
			else 
				cout<<board[i][j]<<"  ";
		}
		cout<<endl<<endl;
	}
}
void Game::PrintOriginalBoard()//function that print the original board , before using
{
	cout<<"   ";
	for(char i='A';i<'K';i++)
		cout<<i<<"  ";
	cout<<endl<<endl;
	for(int i=0; i<M;i++)
	{
		if(i==9)
			cout<<i+1<<" ";
		else cout<<i+1<<"  ";
		for (int j=0;j<M;j++)
			cout<<board[i][j]<<"  ";
		cout<<endl<<endl;
	}
}
int Game::CheckHit(int line,char collum) //The functio get row and col and the copy board and update the board
{
	if(board[line][collum]=='@'||board[line][collum]=='X')
		return 2;

	if(board[line][collum]=='S') //We have hit
	{
		occupied--;
		board[line][collum]='@';
		return 1;
	}
	else
	{ //Not hit
		board[line][collum]='X';

		return 0;
	}
}
int Game::CheckSunk_Vertical(int line,char collum) //An assistance function that gets row and col and check if battleship sunk (place vertical). 
{
	while(board[line][collum]!='_' && board[line][collum]!='X' && line<9)
	{
		line++;
		if(board[line][collum]=='S') //Not sunk
			return 0;
	}
	line--;
	while(board[line][collum]=='@'&& line>0 )
	{
		line--;
		if(board[line][collum]=='S')//Not sunk
			return 0;
	}
	return 1;  //Battleship sunk

}
int Game::CheckSunk_horizontal(int line,char collum)  //An assistance function that gets row and col and check if battleship sunk(place horizontal).
{
	while( (board[line][collum]!= '_' ) && (board[line][collum]!='X') && (collum<9) )
	{
		collum++;
		if(board[line][collum]=='S')  //Not sunk
			return 0;
	}
	collum--;
	while(board[line][collum]=='@' && collum>0)  //Not sunk
	{
		collum--;
		if(board[line][collum]=='S')
			return 0;
	}
	return 1;  //Battleship sunk

}
int Game::CheckSunk(int line,char collum)// The main function that check if The submarine was sunk
{
	int flag;

	if(line==0)
	{
		if(board[line+1][collum]=='S'||board[line+1][collum]=='@')//check if the sunk is horizontal or vretical and there is no deviation at the array
			flag=1;
		else flag=2;
	}
	else if(line==9)
	{
		if(board[line-1][collum]=='S'||board[line-1][collum]=='@')//check if the sunk is horizontal or vretical and there is no deviation at the array
		flag=1;

	else flag=2;
	}
	else if((board[line-1][collum]=='S'||board[line-1][collum]=='@')|| (board[line+1][collum]=='S'||board[line+1][collum]=='@') )//check if the sunk is horizontal or vretical
		flag=1;
	else flag=2;

	if(flag==1)//if flag 1 its mean the sunk is vertical and activate the assistance function
		return CheckSunk_Vertical(line,collum);
	if(flag==2)//if flag 2 its mean the sunk is horizontal and activate the assistance function
		return CheckSunk_horizontal(line,collum);


}
int Game::play()//The function runs the game and runs all the desired functions
{
	int y,y2=-1,count=0;
	char hint ,x,x2;
	ClearBoard();//activate the function that clean the board before the first use
	BuildBoard();//activate the function that build the board

	cout<<"Do you want a hint? [y/n]\n"; 
	_flushall();
	cin>>hint;
	if(hint=='y'||hint=='Y')
	{
		PrintOriginalBoard();
		cout<<"Menorize the board and ";	
	}
	do{
		system("pause");//Freezing the screen
		system("cls");//clean the screen after all Any legal attempt

		do{
			cout<<"Enter guss: x y < to exit use 0 0 >\t* x:{ A-J OR a-j } y:{ 1-10 } *\n";
			cin>>x2;
			cin>>y2;

			_flushall();
			if(cin.fail())//Testing user has not entered any char input
			{
				cin.clear();
				y2=-1;
			}

			if( (x2-48)==0 && y2==0)//check if the user want to exit
			{
				cout<<"You have chosen to exit the game, Bye Bye..\n";
				ClearBoard();
				return 0;
			}
		}while( ((y2<=0||y2>10)|| (x2<'A'||x2>'J') && (x2<'a'||x2>'j')) && (cout<<"Your choice unable!\n") );//Testing user has not entered any invalid input


		if(x2>='A' && x2<='J')//Adjusting the values ​​of user to the Board Game
		{
			y=y2-1;
			x=x2-65;
		}
		else if(x2>='a' && x2<='j')//Adjusting the values ​​of user to the Board Game
		{
			y=y2-1;
			x=x2-97;
		}

		int hit_or_miss=CheckHit(y,x);//check if its hit or miss

		count++;//counting the amount of rounds the user play

		if(hit_or_miss==1)// if we have hit we check if the ship sunk
		{
			cout<<"Hit!!!\n";
			if(CheckSunk(y,x)==1)
				cout<<"Buttleship sunk!!!\n";
			Printboard();
		}
		else if(hit_or_miss==2)
		{
			cout<<"This place has already damaged!\n";
						Printboard();

		}
		else if(hit_or_miss==0)
		{
			cout<<"Miss!!!\n";
						Printboard();
		}
	}while(occupied!=0);//Stopping conditions . As long as all the ship dont sunk 
	cout<<"WIN!!!!\n";
	cout<<"You had "<<count<<" round totals.\n";
	Printboard();// print the board after game over 

	//ClearBoard();
	return 0;
}