#include "pch.h"
#include "SceneManager.h"

namespace Engine {

	SceneManager::SceneManager()
	{
		ModelShader = new Shader("res/shaders/pastryshader.glsl");
		BackgroundShader = new Shader("res/shaders/backgroundshader.glsl");

		glEnable(GL_DEPTH_TEST);
	}

	SceneManager::~SceneManager()
	{
		delete ModelShader;
		delete BackgroundShader;
	}

	void SceneManager::Draw(Pastry* model, float xPosition)
	{
		ModelShader->Bind();
		ModelShader->SetFloat("uPosition", xPosition);
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
		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}