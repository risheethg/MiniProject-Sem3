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

		static EventType GetStaticType() { return EventType::MouseMove; }
		EventType GetEventType() const override { return GetStaticType(); }
		const char* GetName() const override { return "MouseMove"; }
		
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMoveEvent: " << GetXPos() << " ," << GetYPos();
			return ss.str();
		}
	private:
		float m_XPos, m_YPos;
	};

}