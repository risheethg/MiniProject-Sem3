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

		m_ProjectionMatrix = glm::perspective(glm::radians(90.0f), (float)1280 / (float)720, 1.0f, 100.0f);
		m_ViewMatrix = glm::lookAt(m_CameraPos, m_CameraPos + m_CameraFront, m_CameraUp);
	}

	SceneManager::~SceneManager()
	{
		delete ModelShader;
		delete BackgroundShader;
	}

	void SceneManager::Push(Pastry* pastry)
	{
		m_GameObjects.push_back(pastry);
	}

	void SceneManager::RawDraw(Pastry* model)
	{
		ModelShader->Bind();
		ModelShader->SetMat4("uProjection", m_ProjectionMatrix);
		ModelShader->SetMat4("uView", m_ViewMatrix);
		ModelShader->SetMat4("uModel", m_ModelMatrix);
		model->Draw(ModelShader);
		ModelShader->Unbind();
	}
	
	void SceneManager::Draw(Pastry* model, glm::vec3 translate, glm::vec3 scale, float rotationDegrees, glm::vec3 rotation)
	{
		ModelShader->Bind();
		ModelShader->SetMat4("uProjection", m_ProjectionMatrix);
		ModelShader->SetMat4("uView", m_ViewMatrix);
		m_ModelMatrix = glm::translate(m_ModelMatrix, translate);
		m_ModelMatrix = glm::scale(m_ModelMatrix, scale);
		m_ModelMatrix = glm::rotate(m_ModelMatrix, glm::radians(rotationDegrees), rotation);
		ModelShader->SetMat4("uModel", m_ModelMatrix);
		model->Draw(ModelShader);
		ModelShader->Unbind();
	}

	void SceneManager::DrawWithProps(Pastry* model, const DrawProps& Props)
	{
		ModelShader->Bind();
		ModelShader->SetMat4("uProjection", m_ProjectionMatrix);
		ModelShader->SetMat4("uView", m_ViewMatrix);
		m_ModelMatrix = glm::translate(m_ModelMatrix, Props.Position);
		ModelShader->SetMat4("uModel", m_ModelMatrix);
		model->Draw(ModelShader);
		ModelShader->Unbind();
	}

	void SceneManager::DrawBackground(TexturePlane* texture)
	{
		BackgroundShader->Bind();
		texture->Draw(BackgroundShader);
		BackgroundShader->Unbind();
	}
	void SceneManager::Clear()
	{
		glClearColor(0.5f, 0.5f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}