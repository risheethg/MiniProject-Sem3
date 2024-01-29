#pragma once
#include "pch.h" 

#include "Shader.h"

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

namespace Engine {
    using namespace std;

#define MAX_BONE_INFLUENCE 4

    struct Vertex {
       
        glm::vec3 Position;
        glm::vec3 Normal;
        glm::vec2 TexCoords;
        glm::vec3 Tangent;
        glm::vec3 Bitangent;
        int m_BoneIDs[MAX_BONE_INFLUENCE];
        float m_Weights[MAX_BONE_INFLUENCE];
    };

    struct Texture {
        unsigned int id;
        string type;
        string path;
    };

    class Mesh {
    public:
        // mesh Data
        vector<Vertex>       vertices;
        vector<unsigned int> indices;
        vector<Texture>      textures;
        unsigned int VAO;

        // constructor
        Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);

        // render the mesh
        void Draw(Shader* shader);

    private:
        // render data 
        unsigned int VBO, EBO;

        // initializes all the buffer objects/arrays
        void setupMesh();
    };

}
