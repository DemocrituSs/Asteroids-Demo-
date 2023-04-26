#include "Game.h"

int main()
{
	Game game;

	game.Initialize();
	game.Runloop();
	game.Shutdown();

	return 0;
}