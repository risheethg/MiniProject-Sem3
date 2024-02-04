#include "pch.h"
#include "GameManager.h"

#include "stb_image.h"

#include "Application.h"

namespace Engine {

	float GameManager::s_DeltaTime = 0;

	GameManager::GameManager()
	{
		/// Load Resources///////
		stbi_set_flip_vertically_on_load(false);
		m_LoadedModels.push_back(new Model("res/models/gingerbread/Gingerbread.obj"));
		m_LoadedModels.push_back(new Model("res/models/biscuit/Biscuit.obj"));
		m_LoadedModels.push_back(new Model("res/models/donut/Donut.obj"));
		m_LoadedModels.push_back(new Model("res/models/macaron/macaron.obj"));
		stbi_set_flip_vertically_on_load(true);
		
		m_TBackground = new TexturePlane("res/images/background_cubemap.jpg");
		////////////////////////

		///Create Player//////
		m_Player = new Player();
		///////////////////////

		//Initialize Scene Manager
		m_SceneManager = new SceneManager();

		//Test models
		TestPastry = new Pastry(m_LoadedModels[0]);

		//Delta Time Initialization
		m_LastFrame = 0;

		//Set initial spawn timer 
		m_Timer = new Timer();
		m_Timer->Start();
		m_TimeBetweenSpawn = 2;
	}

	GameManager::~GameManager()
	{
		/// Delete resources from memory /////
		//Delete Models
		for (Model* model : m_LoadedModels)
		{
			delete model;
		}

		for (auto GameObject : m_GameObjects)
		{
			delete GameObject;
		}

		//Delete Textures
		delete m_TBackground;
		////////////////////////////////////

		///Delete SceneManager
		delete m_SceneManager;
		
		///Delete Miscelaneous
		delete m_Timer;
		delete TestPastry;
	}

	/// Core /////////////////////////
	void GameManager::OnUpdate()
	{
		///Calulate Delta Time
		m_CurrentFrame = (float)(glfwGetTime());
		s_DeltaTime = m_CurrentFrame - m_LastFrame;
		m_LastFrame = m_CurrentFrame;
		///Clear Background
		m_SceneManager->Clear();

		///Draw Skybox
		m_SceneManager->DrawBackground(m_TBackground);
		
		///Spawn object every 2 seconds
		m_Timer->HasElapsedCallback(m_TimeBetweenSpawn, [this]() { Spawn(); });

		///Update Game Objects
		for (auto GameObject : m_GameObjects)
		{
			if (m_Player->GetScreenCoordinates() == GameObject->GetScreenCoordinates())
			{
				ENGINE_TRACE("Collision Occured!")
			}
			//ENGINE_TRACE("Pastry at {0}, {1}", GameObject->GetScreenCoordinates().x, GameObject->GetScreenCoordinates().y);
			GameObject->OnUpdate(s_DeltaTime);
		}

		m_Player->OnUpdate(s_DeltaTime);
		//ENGINE_TRACE("Player at {0}, {1}", m_Player->GetScreenCoordinates().x, m_Player->GetScreenCoordinates().y);
	}

	void GameManager::OnEvent(Event& event)
	{
		m_Player->OnEvent((MouseMoveEvent&)event);
	}

	void GameManager::Render()
	{
		for (auto GameObject : m_GameObjects)
		{
			m_SceneManager->Draw(GameObject);
		}
	}
	//////////////////////////////////
    
	/// Helper /////////////////////////
	void GameManager::Spawn() {
		ENGINE_TRACE("Spawn has been called!");
		//m_DrawProps = GenerateRandomValues();
		//int randomModel = Random::GetModel(4);
		m_GameObjects.push_back(new Pastry(m_LoadedModels[Random::GetModel(4)], GenerateRandomValues()));
	}

	DrawProps GameManager::GenerateRandomValues()
	{
		m_GeneratedSpawnPosition = Random::GetPosition(30);
		m_GeneratedAnimationVector = Random::GetAnimation(3);
		return {m_GeneratedSpawnPosition, m_GeneratedAnimationVector};
	}
	////////////////////////////////////
}