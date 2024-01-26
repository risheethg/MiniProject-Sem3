#include "pch.h"
#include "Renderer.h"

#include "Log.h"

#include "stb_image.h"

#include <glad/glad.h>

namespace Engine
{

	void Renderer::Clear()
	{
		glClearColor(.0f, 1.0f, .0f, 1.0f); ///Blue
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::Clear(glm::vec4 color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void DrawBackground()
	{
		glBindTexture(GL_TEXTURE_2D, BackgroundTexture);
		glBindVertexArray(VertexArray);
		backgroundshader->Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		backgroundshader->Unbind();
	}

	void SetUpBackground()
	{
		stbi_set_flip_vertically_on_load(true);
		Shader backgroundshader("res/shaders/backgroundshader.glsl");

		float vertices[] =
		{   //Positions     Texture Coords
			1.0f,  1.0f,	1.0f, 1.0f,
			1.0f, -1.0f,	1.0f, 0.0f,
			-1.0f, -1.0f,	0.0f, 0.0f,
			-1.0f, 1.0f,	0.0f, 1.0f
		};

		unsigned int indices[] =
		{
			0, 1, 2,
			2, 0, 3
		};
		
		glCreateVertexArrays(1, &VertexArray);
		glCreateBuffers(1, &VertexBuffer);
		glCreateBuffers(1, &IndexBuffer);

		glBindVertexArray(VertexArray);

		glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBuffer);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (const void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (const void*)(2 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glGenTextures(1, &BackgroundTexture);
		glBindTexture(GL_TEXTURE_2D, BackgroundTexture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int Width, Height, Channels;
		unsigned char* data = stbi_load("res/images/background_res_ref.jpg", &Width, &Height, &Channels, NULL);
		ENGINE_ASSERT(data, "Failed to load background image!");
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		stbi_image_free(data);

		backgroundshader.Bind();
		backgroundshader.SetInt("backgroundTexture", 0);
	}

	void Renderer::Shutdown()
	{
		delete backgroundshader;
	}

}