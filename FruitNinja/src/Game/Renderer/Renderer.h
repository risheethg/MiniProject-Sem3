#pragma once
#include "pch.h"

#include "Model.h"
#include "Shader.h"

#include "glm.hpp"

namespace Engine {

	class Renderer
	{
	public:
		static void Init();
		void Shutdown();

		void DrawBackground();

		static void Clear();
		static void Clear(glm::vec4 color);
	private:
		unsigned int BackgroundTexture, VertexBuffer, IndexBuffer, VertexArray;
		Shader* backgroundshader;
	};

}

