#pragma once
#include "pch.h"

#include "SceneManager.h"

#include "Renderer/Model.h"
#include "Renderer/TexturePlane.h"

namespace Engine {

	enum class PastryModel
	{
		NONE = -1,
		BISCUIT, MACARON,
	};

	class GameManager
	{
	public:
		GameManager();
		~GameManager();

		void Run();
	private:
		std::vector<Model*> m_LoadedModels;
		std::vector<Model*>::iterator Begin() { return m_LoadedModels.begin(); }
		std::vector<Model*>::iterator End() { return m_LoadedModels.end(); }

		TexturePlane* m_TBackground;
		Pastry* m_PMacaron;
		Pastry* m_PBiscuit;

		SceneManager* m_SceneManager;
	};

}

