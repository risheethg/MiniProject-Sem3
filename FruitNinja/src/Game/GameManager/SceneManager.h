#pragma once

#include "Pastry.h"

#include "Renderer/Shader.h"
#include "Renderer/TexturePlane.h"

namespace Engine
{
	class SceneManager
	{
	public:
		SceneManager();
		~SceneManager();

		void Draw(Pastry* model);
		void DrawBackground(TexturePlane* texture);
		
		void Clear();
		void SwapBuffers(GLFWwindow* window);
	private:
		/// Shaders
		Shader* ModelShader, * BackgroundShader;
	};

}

