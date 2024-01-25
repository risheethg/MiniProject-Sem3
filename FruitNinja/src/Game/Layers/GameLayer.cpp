#include "pch.h"
#include "GameLayer.h"

#include "Log.h"

namespace Engine {

	GameLayer::GameLayer()
	{
		//Initialize game rendering 
	}
	
	GameLayer::~GameLayer()
	{
		//
	}

	void GameLayer::OnUpdate()
	{

	}

	void GameLayer::OnEvent(Event& e)
	{
		ENGINE_TRACE("{0} : From Game Layer", e.ToString());
	}

}