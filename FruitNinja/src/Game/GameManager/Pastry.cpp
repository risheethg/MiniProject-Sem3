#include "pch.h"
#include "Pastry.h"

namespace Engine {

	void Pastry::OnUpdate(float dt)
	{
		const float translationSpeed = 0.01f;
		m_Velocity += m_GravityVector * dt;
		m_Position += m_Velocity * dt;

		//Update Model Matrix
		m_ModelMatrix = glm::mat4(1.0f);
		m_ModelMatrix = glm::translate(m_ModelMatrix, m_Position * translationSpeed);
	}

	Pastry::~Pastry()
	{
		
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
		shader->SetVec3("uPos", m_Position);
		shader->SetMat4("uModel", m_ModelMatrix);
		m_Model->Draw(shader);
	}

	void Pastry::ApplyForce(glm::vec3 force)
	{
		m_Velocity = force;
	}

	glm::vec2 Pastry::GetScreenCoordinates() const
	{
		glm::vec4 worldpos = g_ProjectionMatrix * g_ViewMatrix * m_ModelMatrix * glm::vec4(m_Position, 1.0f);
		worldpos /= worldpos.w;
		return { (int)((worldpos.x + 1.0f) * 0.5f * 1280), (int)((1.0f - worldpos.y) * 0.5f * 720) };
	}
}