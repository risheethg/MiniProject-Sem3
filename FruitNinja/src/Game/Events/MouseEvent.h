#pragma once

#include "Events/Event.h"

namespace Engine {

	class MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(float x, float y)
			: m_XPos(x), m_YPos(y) {}
		inline float GetXPos() const { return m_XPos; }
		inline float GetYPos() const { return m_YPos; }

		static EventType GetStaticType() { return EventType::MouseMoved; }
		EventType GetEventType() const override { return GetStaticType(); }
		const char* GetName() const override { return "MouseMoved"; }
		
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << GetXPos() << " ," << GetYPos();
			return ss.str();
		}
	private:
		float m_XPos, m_YPos;
	};

}