#pragma once

#include "Actor.h"

namespace Engine {
	
	class Background
	{
	public:
		Background(const std::string& path);
		~Background();

		void Draw();

	private:
		unsigned int BackgroundTexture, VertexBuffer, IndexBuffer, VertexArray;
		std::string name = "Background_Actor";
		Shader* backgroundshader;
	};

}
