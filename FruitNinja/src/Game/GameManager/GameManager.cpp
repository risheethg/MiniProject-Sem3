#include "pch.h"
#include "GameManager.h"

#include "stb_image.h"

#include "Application.h"

namespace Engine {

	struct DrawProps;

	GameManager::GameManager()
	{
		///Load Resources///////
		stbi_set_flip_vertically_on_load(false);
		m_LoadedModels.push_back(new Model("res/models/gingerbread/Gingerbread.obj"));
		m_LoadedModels.push_back(new Model("res/models/biscuit/Biscuit.obj"));
		m_LoadedModels.push_back(new Model("res/models/donut/Donut.obj"));
		m_LoadedModels.push_back(new Model("res/models/macaron/macaron.obj"));
		stbi_set_flip_vertically_on_load(true);
		
		m_TBackground = new TexturePlane("res/images/background_cubemap.jpg");
		////////////////////////

		///Initialize Scene Manager
		m_SceneManager = new SceneManager();

		///Test models
		TestPastry = new Pastry(m_LoadedModels[0], "Test Model");

		///Physics and Game Update stuff
		m_GravityVector = glm::vec3(0.0f, -9.8f, 0.0f);

		//Delta Time Initialization
		s_DeltaTime = 0;
		m_StartTime = glfwGetTime();

		//Set initial spawn timer 
		m_Timer = new Timer();
		m_Timer->Start();
		m_TimeBetweenSpawn = 2;
	}

	GameManager::~GameManager()
	{
		///Delete Resources from memory/////
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

		///Delete TestPastry
		delete TestPastry;
	}

	void GameManager::OnUpdate()
	{
		///Clear Background
		m_SceneManager->Clear();
		///Draw Skybox
		m_SceneManager->DrawBackground(m_TBackground);
		
		m_Timer->HasElapsedCallback(m_TimeBetweenSpawn, [this]() { Spawn(); });

		//m_SceneManager->RawDraw(TestPastry);

		for (auto GameObject : m_GameObjects)
		{
			GameObject->OnUpdate(s_DeltaTime);
		}
	}

	void GameManager::Render()
	{
		for (auto GameObject : m_GameObjects)
		{
			m_SceneManager->DrawWithProps(GameObject, GenerateRandomValues());
		}
	}
	
	void GameManager::Spawn() {
		ENGINE_TRACE("Spawn has been called!")
		int randomModel = Random::GetModel(4);
		m_GameObjects.push_back(new Pastry(m_LoadedModels[randomModel], ""));
	}

	DrawProps GameManager::GenerateRandomValues()
	{
		m_SpawnPosition = Random::GetPosition(5);
		m_SpawnForce = Random::GetSpawnForce(5);
		return { glm::vec3((float)(m_SpawnPosition), 0.0f , 0.0f), glm::vec3(0.0f, m_SpawnForce, 0.0f)};
	}

}