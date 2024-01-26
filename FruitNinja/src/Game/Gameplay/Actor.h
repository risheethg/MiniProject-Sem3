#pragma once

#include "Events/Event.h"

#include "Renderer/Shader.h"

namespace Engine {

	class Actor
	{
	public:
		virtual void OnUpdate() = 0;
		virtual void OnEvent(Event& event) = 0;
		virtual void Draw(Shader& shader) = 0;
	
		std::string m_Name;
	};

}

