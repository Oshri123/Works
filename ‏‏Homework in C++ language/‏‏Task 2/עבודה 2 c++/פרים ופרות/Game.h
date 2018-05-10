#include <iostream>
#ifndef Game_H
#define Game_H
#include "Number.h"

class Game
{
private:
	Number* userNumber;
	Number* compNumber;
	int cow();
	int bull();
public:
	Game();
	~Game();
	Game(Game const&other);
	void play();
};
#endif