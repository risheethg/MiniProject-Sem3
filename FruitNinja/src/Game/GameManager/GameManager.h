#pragma once
#include "pch.h"

#include "SceneManager.h"

#include "Renderer/Model.h"
#include "Renderer/TexturePlane.h"


#include "Window/Window.h"

#include "Utility/Random.h"
#include "Utility/Timer.h"

#include "Pastry.h"

namespace Engine {

	enum class PastryModel
	{
		NONE = -1,
		GINGERBREAD, BISCUIT, DONUT, MACARON
	};

	class GameManager
	{
	public:
		GameManager();
		~GameManager();

		void OnUpdate();
		void Render();
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
		float m_SpawnPosition;
		float m_SpawnForce;
		glm::vec3 m_GravityVector;

		void Spawn();
		DrawProps GenerateRandomValues();
		/////////////////

		TexturePlane* m_TBackground;

		SceneManager* m_SceneManager;

		Pastry* TestPastry;

		///Delta Time
		float s_DeltaTime;
		float m_StartTime;
		float m_CurrentTime;
		float m_LastTime;
	};

}

