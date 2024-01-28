#pragma once

#include "Shader.h"

namespace Engine {

	class TexturePlane
	{
	public:
		TexturePlane(const std::string& path);
		
		void Draw(Shader* shader);
	private:
		int m_Width, m_Height, m_Channels;
		unsigned int m_Texture, m_VertexBuffer, m_IndexBuffer, m_VertexArray;
		unsigned char* m_Data;
	};

}

