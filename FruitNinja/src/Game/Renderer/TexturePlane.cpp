#include "pch.h"
#include "TexturePlane.h"

namespace Engine {

	TexturePlane::TexturePlane(const std::string& path)
	{
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

		glCreateVertexArrays(1, &m_VertexArray);
		glCreateBuffers(1, &m_VertexBuffer);
		glCreateBuffers(1, &m_IndexBuffer);

		glBindVertexArray(m_VertexArray);

		glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (const void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (const void*)(2 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glGenTextures(1, &m_Texture);
		glBindTexture(GL_TEXTURE_2D, m_Texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		unsigned char* data = stbi_load(path.c_str(), &m_Width, &m_Height, &m_Channels, NULL);
		ENGINE_ASSERT(data, "Failed to load background image!");
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		stbi_image_free(data);
	}

	void TexturePlane::Draw(Shader* shader)
	{
		glBindTexture(GL_TEXTURE_2D, m_Texture);
		glBindVertexArray(m_VertexArray);
		shader->Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		shader->Unbind();
	}
}