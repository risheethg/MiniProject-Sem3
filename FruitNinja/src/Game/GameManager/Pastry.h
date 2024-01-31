#pragma once

#include "Actor.h"

#include "Renderer/Model.h"

namespace Engine {

	class Pastry : public Actor
	{
	public:
		Pastry(Model* model, const std::string& name)
			: m_Model(model), m_Name(name) {
			m_ModelMatrix = glm::mat4(1.0f);
			m_ModelMatrix = glm::translate(m_ModelMatrix, glm::vec3(0.0f, 6.0f, 0.0f));
		}
		
		virtual void OnUpdate(float dt) override;
		virtual void OnEvent(Event& event) override;
		virtual void Draw(Shader* shader) override;
		std::string m_Name;
	private:
		glm::mat4 m_ModelMatrix = glm::scale(m_ModelMatrix,glm::vec3(0.5f, 0.5f, 0.5f));
		glm::vec3 m_AnimationVector = glm::vec3(0.1f, 0.3f, 0.4f);
		const glm::vec3 m_GravityVector = glm::vec3(0.0f, -9.8f, 0.0f); 
		Model* m_Model;
	};

}

