#include "pch.h"
#include "Game.h"

#include "Log.h"

namespace Engine {

	Game::Game()
	{
		Init();
	}

	Game::~Game()
	{
		Shutdown();
	}

	void Game::Init()
	{
		/*
		glfw.init()
		window.init()
		sound.init()
		*/
		
		Log::Init();
		ENGINE_CORE_WARN("Logger Initialized!")
		ENGINE_TRACE("Game Initialized!")
	}

	void Game::Shutdown()
	{
		/*
		glfw.shutdown()
		window.shutdown()
		sound.shutdown()
		*/
	}

	void Game::Run()
	{
		while (m_Running)
		{
			/*
				window.update()
			*/
		}
	}
}