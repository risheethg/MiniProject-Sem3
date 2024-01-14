///////////////////////////
////////Entry Point///////
#include "pch.h"
#include "Game/Core.h"

int main()
{
	Engine::Application* game = new Engine::Application;
	game->Run();
	delete game;

	return 0;
}

////////////////////////
////////////////////////