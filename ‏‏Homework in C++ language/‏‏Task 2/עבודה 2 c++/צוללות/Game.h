#include "Battleships.h"
#include <iostream>
#ifndef Game_H
#define Game_H
using namespace std;
#define M 10
class Game {
private:

	char board[M][M];
	Battleships *ships;
	static int occupied;

	void ClearBoard();
	int CheckPlace(int line, int collum,int size,int choice);
	void BuildBoard( );
	void Printboard();
	int CheckHit(int line, char collum);
	int CheckSunk(int line, char collum);
	void PrintOriginalBoard();
	int CheckSunk_Vertical(int line,char collum);
	int CheckSunk_horizontal(int line,char collum);
	int ChecklPlaceVertical(int line, int collum,int size);
	int ChecklPlaceHorizontal(int line, int collum,int size);
public:
		Game(int number_of_ships);
		~Game();
		int play();
	
};
#endif