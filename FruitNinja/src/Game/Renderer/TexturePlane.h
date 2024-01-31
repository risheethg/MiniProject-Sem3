#pragma once

#include "Shader.h"

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

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

		///Camera
		glm::vec3 m_CameraPos;
		glm::vec3 m_CameraFront;
		glm::vec3 m_CameraUp;

		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;

	};

}

