#pragma once
#include "pch.h"

#include "Shader.h"
#include "Mesh.h"

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

namespace Engine {
	
	class Model
	{
	public:
		Model(const char* path);
		void Draw(Shader* shader);

		std::vector<Mesh> m_Meshes;
		std::vector <Texture> m_TexturesLoaded;
	private:
		std::string m_Directory;
		void LoadModel(std::string const path);
		void ProcessNode(aiNode* node, const aiScene* scene);
		Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
		std::vector<Texture> LoadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string name);

		unsigned int TextureFromFile(const char* path, const std::string& directory);
	};

}

