#pragma once
#include "pch.h"

#include "Shader.h"

#include "glm.hpp"

namespace Engine {

	struct Vertex
	{
		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec2 TexCoords;
	};

	struct Texture
	{
		unsigned int id;
		std::string type;
		std::string path;
	};

	class Mesh
	{
	public:
		Mesh(std::vector<Vertex> v, std::vector<unsigned int> i, std::vector<Texture> t)
			: m_Vertices(v), m_Indices(i), m_Textures(t) { SetUpMesh(); }

		std::vector<Vertex> m_Vertices;
		std::vector<unsigned int> m_Indices;
		std::vector<Texture> m_Textures;

		void Draw(Shader& shader);
	private:
		unsigned int m_VertexBuffer, m_IndexBuffer, m_VertexArray;

		void SetUpMesh();
	};

}

