///////////////////////////
////////Entry Point///////

#include "Game/Core.h"

int main()
{
	Engine::Game* game = new Engine::Game;
	game->Run();
	delete game;

	return 0;
}

////////////////////////
////////////////////////