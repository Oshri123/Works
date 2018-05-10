#ifndef TicTacToe_H
#define TicTacToe_H
#include <iostream>
enum state {X_win, O_win, draw, not_finished };
using namespace std;
class CTicTacToe{
private:
	char board[3][3];
	char turn;
	bool game_over;
	
	void step();
	state game_state();
	void print();

public:
	CTicTacToe();
	~CTicTacToe();
	void play();
};
#endif
