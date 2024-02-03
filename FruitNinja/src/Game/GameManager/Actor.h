#pragma once

#include "Events/Event.h"

#include "Renderer/Shader.h"

namespace Engine {

	struct DrawProps;

	class Actor
	{
	public:
		virtual void OnUpdate(float dt) = 0;
		virtual void OnEvent(Event& event) = 0;
		virtual void Draw(Shader* shader) = 0;

		virtual void ApplyForce(glm::vec3 force) = 0;
	
		std::string m_Name;
	};

}

