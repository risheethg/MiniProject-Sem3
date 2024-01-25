#include "pch.h"
#include "Mesh.h"

#include <glad/glad.h>

namespace Engine {

	void Mesh::SetUpMesh()
	{
		glCreateVertexArrays(1, &m_VertexArray);
		
		glCreateBuffers(1, &m_VertexArray);
		glCreateBuffers(1, &m_IndexBuffer);

		glBindVertexArray(m_VertexArray);

		glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, m_Vertices.size() * sizeof(Vertex), &m_Vertices[0], GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(unsigned int), &m_Indices[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(Vertex)-sizeof(Vertex::Normal)));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(Vertex) - sizeof(Vertex::TexCoords)));

		glBindVertexArray(0);
	}

	void Mesh::Draw(Shader& shader)
	{
		unsigned int diffuseNr = 1;
		unsigned int specularNr = 1;

		for (unsigned int i = 0; i < m_Textures.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i);
			
			std::string number;
			std::string name = m_Textures[i].type;

			if (name == "texture_difuse")
			{
				number = std::to_string(diffuseNr++);
			}
			else if (name == "texture_specular")
			{
				number = std::to_string(specularNr++);
			}
			
			//temp fix to fix covnersion error
			std::string val = "material" + name = number;
			shader.SetInt(val, i);
			glBindTexture(GL_TEXTURE_2D, m_Textures[i].id);
		}
	}

}