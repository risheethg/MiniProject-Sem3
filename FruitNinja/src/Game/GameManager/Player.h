#pragma once

#include "Actor.h"
#include "Events/MouseEvent.h"

namespace Engine {

	class Player 
	{
	public:
		Player()
			: m_XPos(0), m_YPos(0), m_Velocity(0.0f) {}
		~Player();
		void OnEvent(MouseMoveEvent& event);
		void OnUpdate(float dt);
		void Draw(Shader* shader);

		glm::vec2 GetScreenCoordinates() const;
	private:
		float m_XPos, m_YPos, m_Velocity;


	};

}

