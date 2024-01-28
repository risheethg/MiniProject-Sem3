#include "pch.h"
#include "GameManager.h"

namespace Engine {

	GameManager::GameManager()
	{
		m_LoadedModels.push_back(new Model("res/models/backpack/backpack.obj"));
		m_LoadedModels.push_back(new Model("res/models/macaron/macaron.obj"));

		m_TBackground = new TexturePlane("res/images/background_res_ref.jpg");
		m_PBiscuit = new Pastry(m_LoadedModels[0], "Biscuit");
		m_PMacaron = new Pastry(m_LoadedModels[1], "Macaron");

		m_SceneManager = new SceneManager();
	}

	GameManager::~GameManager()
	{
		for (Model* model : m_LoadedModels)
		{
			delete model;
		}

		delete m_TBackground;
	}

	void GameManager::Run()
	{
		m_SceneManager->Clear();

		///Push to the game manager to render along with a uniform for it's location
		//m_SceneManager->DrawBackground(m_TBackground);
		m_SceneManager->Draw(m_PBiscuit, 0.0f);
		//m_SceneManager->Draw(m_PMacaron, 0.0f);
	}
}