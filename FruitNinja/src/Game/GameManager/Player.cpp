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
		return { m_XPos, m_YPos };
	}

}