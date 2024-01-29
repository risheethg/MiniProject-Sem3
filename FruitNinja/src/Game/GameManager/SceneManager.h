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

		void Draw(Pastry* model);
		//void Draw(Pastry* model, glm::vec3 translate = {1.0f, 1.0f, 1.0f}, glm::vec3 scale = {1.0f, 1.0f, 1.0f}, float rotate = 0.0f);
		void DrawBackground(TexturePlane* texture);
		void Clear();
	private:
		Shader* ModelShader, * BackgroundShader;
		
		///Camera
		glm::vec3 m_CameraPos;
		glm::vec3 m_CameraFront;
		glm::vec3 m_CameraUp;

		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ModelMatrix;
	};

}

