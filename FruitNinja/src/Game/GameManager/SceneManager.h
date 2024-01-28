#pragma once

#include "Pastry.h"

#include "Renderer/Shader.h"
#include "Renderer/TexturePlane.h"

#include <glm.hpp>

namespace Engine
{

	class SceneManager
	{
	public:
		SceneManager();
		~SceneManager();

		void Draw(Pastry* model, float xPosition);
		void DrawBackground(TexturePlane* texture);
		void Clear();
	private:
		Shader* ModelShader, * BackgroundShader;
	};

}

