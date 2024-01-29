#include "pch.h"
#include "SceneManager.h"

namespace Engine {

	SceneManager::SceneManager()
	{
		ModelShader = new Shader("res/shaders/pastryshader.glsl");
		BackgroundShader = new Shader("res/shaders/backgroundshader.glsl");

		glEnable(GL_DEPTH_TEST);

		m_CameraPos = glm::vec3(0.0f, 0.0f, 6.0f);
		m_CameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
		m_CameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

		m_ProjectionMatrix = glm::perspective(glm::radians(45.0f), (float)1280 / (float)720, 1.0f, 100.0f);
		m_ViewMatrix = glm::lookAt(m_CameraPos, m_CameraPos + m_CameraFront, m_CameraUp);
		m_ModelMatrix = glm::mat4(1.0f);
		m_ModelMatrix = glm::translate(m_ModelMatrix, glm::vec3(0.0f, -0.5f, 3.5f)); ///Change it up
		m_ModelMatrix = glm::scale(m_ModelMatrix, glm::vec3(0.3f, 0.3f, 0.3f));
		m_ModelMatrix = glm::rotate(m_ModelMatrix, glm::radians(-90.0f), glm::vec3(0.0f, -0.0f, 0.3f));
	}

	SceneManager::~SceneManager()
	{
		delete ModelShader;
		delete BackgroundShader;
	}

	void SceneManager::Draw(Pastry* model)
	{
		ModelShader->Bind();
		ModelShader->SetMat4("uProjection", m_ProjectionMatrix);
		ModelShader->SetMat4("uView", m_ViewMatrix);
		ModelShader->SetMat4("uModel", m_ModelMatrix);
		model->Draw(ModelShader);
		ModelShader->Unbind();
	}
	
	/*
	void SceneManager::Draw(Pastry* model, glm::vec3 translate, glm::vec3 scale, float rotate)
	{
		ModelShader->Bind();
		ModelShader->SetMat4("uProjection", m_ProjectionMatrix);
		ModelShader->SetMat4("uView", m_ViewMatrix);
		m_ModelMatrix = glm::translate(m_ModelMatrix, translate);
		m_ModelMatrix = glm::scale(m_ModelMatrix, scale);
		m_ModelMatrix = glm::rotate(m_ModelMatrix, glm::radians(rotate), glm::vec3(0.0f, 1.0f, 0.0f));
		ModelShader->SetMat4("uModel", m_ModelMatrix);
		model->Draw(ModelShader);
		ModelShader->Unbind();
	}
	*/

	void SceneManager::DrawBackground(TexturePlane* texture)
	{
		BackgroundShader->Bind();
		texture->Draw(BackgroundShader);
		BackgroundShader->Unbind();
	}
	void SceneManager::Clear()
	{
		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}