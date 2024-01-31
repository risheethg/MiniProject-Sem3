#pragma once

#include "Pastry.h"

#include "Renderer/Shader.h"
#include "Renderer/TexturePlane.h"

namespace Engine
{

	struct DrawProps
	{
		glm::vec3 Position;
		glm::vec3 Force;

		DrawProps(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 force = glm::vec3(1.0f))
			: Position(position), Force(force) {}
	};

	class SceneManager
	{
	public:
		SceneManager();
		~SceneManager();

		void RawDraw(Pastry* model);
		void Draw(Pastry* model, glm::vec3 translate = glm::vec3(1.0f), glm::vec3 scale = glm::vec3(1.0f), float rotationDegrees = 0.0f, glm::vec3 rotation = glm::vec3(1.0f));
		void DrawWithProps(Pastry* model, const DrawProps& Props = DrawProps());
		void Push(Pastry* pastry);
		void DrawBackground(TexturePlane* texture);
		void Clear();
	private:
		Shader* ModelShader, * BackgroundShader;
		
		std::vector<Pastry*> m_GameObjects;

		///////////////////////
		//Camera
		glm::vec3 m_CameraPos;
		glm::vec3 m_CameraFront;
		glm::vec3 m_CameraUp;
		//Matrices
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ModelMatrix;
		////////////////////////
	};

}

