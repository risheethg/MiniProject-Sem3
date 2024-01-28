#pragma once

#include "Actor.h"

#include "Renderer/Model.h"

namespace Engine {

	class Pastry : public Actor
	{
	public:
		Pastry(Model* model, const std::string& name)
			: m_Model(model), m_Name(name) {}
		
		virtual void OnUpdate() override;
		virtual void OnEvent(Event& event) override;
		virtual void Draw(Shader* shader) override;
	private:
		Model* m_Model;
		std::string m_Name;
	};

}

