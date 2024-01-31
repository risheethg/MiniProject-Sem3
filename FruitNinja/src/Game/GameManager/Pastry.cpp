#include "pch.h"
#include "Pastry.h"

namespace Engine {

	void Pastry::OnUpdate(float dt)
	{
		///Gravity
		float translationSpeed = 0.01f;
		m_ModelMatrix = glm::translate(m_ModelMatrix, m_GravityVector * translationSpeed);
		
		//Rotate
		m_ModelMatrix = glm::rotate(m_ModelMatrix,glm::radians(7.0f), m_AnimationVector * translationSpeed);
	}

	void Pastry::OnEvent(Event& event)
	{
		if (event.GetEventType() == EventType::MouseMove)
		{
			///do destroy stuff
		}
	}

	void Pastry::Draw(Shader* shader)
	{
		shader->SetMat4("uModel", m_ModelMatrix);
		m_Model->Draw(shader);
	}

}