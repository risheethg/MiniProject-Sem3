#pragma once
#include "pch.h"

#include "SceneManager.h"

#include "Renderer/Model.h"
#include "Renderer/TexturePlane.h"

#include "Events/Event.h"

#include "Window/Window.h"

#include "Utility/Random.h"
#include "Utility/Timer.h"

#include "Pastry.h"
#include "Player.h"	

#define MAX_OBJECTS 10

namespace Engine {

	class GameManager
	{
	public:
		GameManager();
		~GameManager();

		void OnUpdate();
		void OnEvent(Event& event);
		void Render();
		
		static float s_DeltaTime;
	private:
		Timer* m_Timer;

		///Vector to store models
		std::vector<Model*> m_LoadedModels;
		std::vector<Model*>::iterator Begin() { return m_LoadedModels.begin(); }
		std::vector<Model*>::iterator End() { return m_LoadedModels.end(); }

		/// Game Objects
		std::vector<Pastry*> m_GameObjects;
		std::vector<Pastry*>::iterator gBegin() { return m_GameObjects.begin(); }
		std::vector<Pastry*>::iterator gEnd() { return m_GameObjects.end(); }

		///Gameplay///////
		float m_TimeBetweenSpawn;
		glm::vec3 m_GeneratedSpawnPosition;
		glm::vec3 m_GeneratedAnimationVector;

		DrawProps m_DrawProps;

		void Spawn();
		DrawProps GenerateRandomValues();
		/////////////////

		TexturePlane* m_TBackground;

		SceneManager* m_SceneManager;

		Pastry* TestPastry;

		Player* m_Player;

		///Delta Time
		float m_CurrentFrame, m_LastFrame;
	};

}

