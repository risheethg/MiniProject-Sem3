#pragma once
#include "pch.h"

#include "Shader.h"

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

namespace Engine {

	struct Vertex
	{
		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec2 TexCoords;
		glm::vec3 Tangent;
		glm::vec3 Bitangent;
		int m_BoneIDs[4];
		float m_Weights[4];
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
		Mesh(std::vector<Vertex> v, std::vector<unsigned int> i, std::vector<Texture> t);
		//	: m_Vertices(v), m_Indices(i), m_Textures(t) { SetUpMesh(); }
		~Mesh();

		std::vector<Vertex> m_Vertices;
		std::vector<unsigned int> m_Indices;
		std::vector<Texture> m_Textures;

		unsigned int m_VertexArray;

		void Draw(Shader* shader);
	private:
		unsigned int m_VertexBuffer, m_IndexBuffer;

		void SetUpMesh();
	};

}

