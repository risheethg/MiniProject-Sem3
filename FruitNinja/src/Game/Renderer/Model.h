#pragma once
#include "pch.h"

#include "Shader.h"
#include "Mesh.h"

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

namespace Engine {

	class Model
	{
	public:
		Model(char* path);
		void Draw(Shader& shader);
	private:
		std::vector<Mesh> m_Meshes;
		std::string m_Directory;
		std::vector <Texture> m_TexturesLoaded;

		void LoadModel(std::string path);
		void ProcessNode(aiNode* node, const aiScene* scene);
		Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
		std::vector<Texture> LoadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string name);

		unsigned int TextureFromFile(const char* path, const std::string& directory);
	};

}

