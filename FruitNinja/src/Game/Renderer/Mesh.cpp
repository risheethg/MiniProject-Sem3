#include "pch.h"
#include "Mesh.h"

namespace Engine {

	Mesh::Mesh(std::vector<Vertex> v, std::vector<unsigned int> i, std::vector<Texture> t)
	{
		this->m_Vertices = v;
		this->m_Indices = i;
		this->m_Textures = t;

		SetUpMesh();
	}

	Mesh::~Mesh()
	{
		/*glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		glDeleteBuffers(1, &m_VertexBuffer);
		glDeleteBuffers(1, &m_IndexBuffer); */
	}

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

		// set the vertex attribute pointers
		// vertex Positions
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
		// vertex normals
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
		// vertex texture coords
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
		// vertex tangent
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Tangent));
		// vertex bitangent
		glEnableVertexAttribArray(4);
		glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Bitangent));
		// ids
		glEnableVertexAttribArray(5);
		glVertexAttribIPointer(5, 4, GL_INT, sizeof(Vertex), (void*)offsetof(Vertex, m_BoneIDs));
		// weights
		glEnableVertexAttribArray(6);
		glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, m_Weights));
		
		glBindVertexArray(0);
	}

	void Mesh::Draw(Shader* shader)
	{
		unsigned int diffuseNr = 1;
		unsigned int specularNr = 1;
		unsigned int normalNr = 1;
		unsigned int heightNr = 1;

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
			else if (name == "texture_normal")
			{
				number = std::to_string(normalNr++);
			}
			else if (name == "texture_height")
			{
				number = std::to_string(heightNr++);
			}
			
			shader->SetInt((name + number).c_str(), i);
			glBindTexture(GL_TEXTURE_2D, m_Textures[i].id);
		}
		glBindVertexArray(m_VertexArray);
		
		glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(m_Indices.size()), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		glActiveTexture(GL_TEXTURE0);
	}
}