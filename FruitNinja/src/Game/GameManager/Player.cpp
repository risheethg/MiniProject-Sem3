#include "pch.h"
#include "Player.h"

namespace Engine {

	void Player::OnUpdate(float dt)
	{
		m_Velocity = sqrt((m_XPos * m_XPos) - (m_YPos * m_YPos)) * dt;
	}

	Player::~Player()
	{

	}

	void Player::OnEvent(MouseMoveEvent& event)
	{
		if (event.GetEventType() == EventType::MouseMove)
		{
			m_XPos = (float)event.GetXPos();
			m_YPos = (float)event.GetYPos();
		}

	}

	void Player::Draw(Shader* shader)
	{

	}

	glm::vec2 Player::GetScreenCoordinates() const
	{
		auto playerPos = glm::vec4(m_XPos, m_YPos, 0.0f, 0.0f) * glm::mat4(1.0f) * g_ViewMatrix * g_ProjectionMatrix;
		return glm::vec2(playerPos.x, playerPos.y);
	}

}