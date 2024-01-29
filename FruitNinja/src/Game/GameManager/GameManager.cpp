#include "pch.h"
#include "GameManager.h"

#include "stb_image.h"

namespace Engine {

	GameManager::GameManager()
	{
		stbi_set_flip_vertically_on_load(false);
		m_LoadedModels.push_back(new Model("res/models/gingerbread/Gingerbread.obj"));
		m_LoadedModels.push_back(new Model("res/models/biscuit/Biscuit.obj"));
		stbi_set_flip_vertically_on_load(true);

		m_TBackground = new TexturePlane("res/images/background_res_ref.jpg");
		m_PGingerbread = new Pastry(m_LoadedModels[0], "Gingerbread");
		m_PBiscuit = new Pastry(m_LoadedModels[1], "Biscuit");

		m_SceneManager = new SceneManager();
	}

	GameManager::~GameManager()
	{
		for (Model* model : m_LoadedModels)
		{
			delete model;
		}

		delete m_TBackground;
		delete m_PBiscuit;
		delete m_PGingerbread;
	}

	void GameManager::Run()
	{
		m_SceneManager->Clear();

		///Push to the game manager to render along with a uniform for it's location
		m_SceneManager->DrawBackground(m_TBackground);
		//m_SceneManager->Draw(m_PBiscuit, {5.0f, 0.0f, 0.0f});
		//m_SceneManager->Draw(m_PGingerbread, { -10.0f, 0.0f, 0.0f });
		m_SceneManager->Draw(m_PGingerbread);
		//m_SceneManager->Draw(m_PMacaron, 0.0f);
	}
}