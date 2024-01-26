#pragma once

#include "Gameplay/Actor.h"

#include "Renderer/Model.h"

namespace Engine {

	class Pastry : public Actor
	{
	public:
		Pastry(Model& model, std::string& name)
			: m_Model(model), m_Name(name) {}
		
		virtual void OnUpdate();
		virtual void OnEvent(Event& event);
		virtual void Draw(Shader& shader);
	private:
		Model m_Model;
		std::string m_Name;
	};

}

