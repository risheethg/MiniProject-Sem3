#include "pch.h"
#include "SceneManager.h"

namespace Engine {

	SceneManager::SceneManager()
	{
		glEnable(GL_DEPTH_TEST);

		ModelShader = new Shader("res/shaders/pastryshader.glsl");
		BackgroundShader = new Shader("res/shaders/backgroundshader.glsl");
	}

	SceneManager::~SceneManager()
	{
		delete ModelShader;
		delete BackgroundShader;
	}

	void SceneManager::Draw(Pastry* model)
	{
		ModelShader->Bind();
		ModelShader->SetMat4("uProjection", g_ProjectionMatrix);
		ModelShader->SetMat4("uView", g_ViewMatrix);
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

	void SceneManager::SwapBuffers(GLFWwindow* window)
	{
		glfwSwapBuffers(window);
	}
}