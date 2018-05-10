#include "CTicTacToe.h"
#define _CRT_SECURE_NO_WARNINGS

CTicTacToe::CTicTacToe() : game_over(false), turn('X') //constructor. reset variables
{
	for (int i = 0; i < 3; i++) //full the board with empty places
	{
		for (int j = 0; j < 3; j++)
			board[i][j] = ' ';
	}
}
CTicTacToe::~CTicTacToe(){}
void CTicTacToe::step() //placing X or O
{
	int x, y;
	cout << "Enter 2 Koardinntot from 1 to 3" << endl;
	do{
		cin >> x >> y;
	} while ( ( (x<1) || (x>3) || (y<1) || (y>3)|| (board[x-1][y-1]!=' ')) && (cout << "EROR!!\nEnter 2 Koardinntot from 1 to 3" << endl));//Input test- if the koardinatot is not correct or if the place is not empty

	board[x-1][y-1] = turn; //after the input is correct , placing X or O in the place
	if (turn == 'X') //change the turn
		turn = 'O';
	else turn = 'X';
}
state CTicTacToe::game_state()//check the geme state - who win
{
	int status1 = 0, status2 = 0, status3 = 0, status4 = 0;
	bool flag=0;//check if there is empty space in the board
	char ezer = 'X'; //check if X is win
	for (int num = 0; num < 2; num++) //repeat 2 times if X win or O win
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if ((i == j) && (board[i][j] == ezer))// check the main diagonal in the board
					status1++;
				if ((i + j == 2) && (board[i][j] == ezer))//check the secondary diagonal in the board 
					status2++;
				if (board[i][j] == ezer)//check the columns
					status3++;
				if (board[j][i] == ezer)//check the rows
					status4++;
				if (board[i][j] == ' ')//if there is some empty place in the board
					flag = 1;
			}
			if  ((status3 == 3) || (status4 == 3))//if X or O win acording to the column or the row
				if (ezer == 'X') //if it X
				{
					game_over = true; //the game is over-X is win
					return X_win;
				}
				else if (ezer == 'O') //if it O
				{
					game_over = true; //the game is over-O is win
					return O_win;
				}

			status3 = 0, status4 = 0; //reset. to check the next column and row
		}
		if ((status1 == 3) || (status2 == 3))//if X or O win acording to the diagonals
			if (ezer == 'X')//if it X
			{
				game_over = true;//the game is over-X is win
				return X_win;
			}
			else if (ezer == 'O')//if it O
			{
				game_over = true;//the game is over-O is win
				return O_win;
			}
		status1 = 0, status2 = 0;//reset. to check if O win
		ezer = 'O'; //check if O win
	}
	if (flag)//Check if the game is not over yet
		return not_finished;
	else //if the game ended in a draw
	{
		game_over = true;
	    return draw;
	}
}
void CTicTacToe::print() //print the board
{
	cout << endl;
	cout << endl;
	cout << "		******************" << endl; // to do frame to the board
	for (int i = 0; i < 3; i++)
	{
		cout << "		*";//frame
		for (int j = 0; j < 3; j++)
		{
			if (j == 2) //if it the last number in the column to creat a frame
			{
				cout << board[i][j] <<"*";
			}
			else cout << board[i][j] << "  |	";

		}
		
			cout << endl;
	}
	cout << "		******************"; //frame
	cout << endl;
	cout << endl;
}
void CTicTacToe::play()
{
	print(); //print the board
	cout << "'" << turn << "'is start!" << endl; //tell who is play now
	while (!game_over) //while the game is not finished
	{
		step(); //placing X or O
		print(); //print the board
		switch (game_state()) //acording to the game state put the correctly output
		{
		case X_win:
			cout << "The winner is 'X' !" << endl;
			break;
		case O_win:
			cout << "The winner is 'O' !" << endl;
			break;
		case draw:
			cout << "It is draw!" << endl;
			break;
		case not_finished: //it the game is continue tell who is play now
			cout << "Now the player is :'" << turn << "'" << endl;
			break;
		}
	}
	print(); //print the board
	cout << "The game is over!" << endl;

}
