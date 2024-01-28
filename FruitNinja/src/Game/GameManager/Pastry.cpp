#include "pch.h"
#include "Pastry.h"

namespace Engine {

	void Pastry::OnUpdate()
	{
		///Do physics stuff
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
		m_Model->Draw(shader);
	}

}