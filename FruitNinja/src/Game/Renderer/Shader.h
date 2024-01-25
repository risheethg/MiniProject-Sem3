#pragma once

#include "pch.h"	

namespace Engine {

	struct ShaderSource
	{
		std::string VertexSource;
		std::string FragmentSource;
	};

	class Shader
	{
	public:
		Shader(const std::string& filepath);
		~Shader();
		
		void Bind() const;
		void Unbind() const;
		unsigned int GetID() const { return m_RendererID; }

		void SetInt(std::string& name, int value) const;
	private:
		int m_RendererID;
		std::string m_FilePath;

		ShaderSource ParseShader(const std::string& filepath);
		unsigned int CompileShader(unsigned int type, const std::string& source);
		unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	};
		
}

