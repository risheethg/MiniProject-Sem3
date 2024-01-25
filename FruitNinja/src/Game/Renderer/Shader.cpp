#include "pch.h"
#include "Shader.h"

#include <glad/glad.h>

namespace Engine {

	Shader::Shader(const std::string& filepath)
	{
		ShaderSource source = ParseShader(filepath);
		m_RendererID = CreateShader(source.VertexSource, source.FragmentSource);
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_RendererID);
	}

	void Shader::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void Shader::Unbind() const
	{
		glUseProgram(0);
	}

	ShaderSource Shader::ParseShader(const std::string& filepath)
	{
		std::ifstream stream(filepath);

		enum class ShaderType {
			NONE = -1, VERTEX = 0, FRAGMENT
		};

		std::string line;
		std::stringstream ShaderSource[2];
		ShaderType type = ShaderType::NONE;

		while (getline(stream, line))
		{
			if (line.find("#shader") != std::string::npos) 
			{
				if (line.find("vertex") != std::string::npos)
				{
					type = ShaderType::VERTEX;
				}
			} else if (line.find("#shader") != std::string::npos) 
			{
				if (line.find("fragment") != std::string::npos)
				{
					type = ShaderType::FRAGMENT;
				}
			} else {
				ShaderSource[(int)type] << line << "\n";
			}
		}

		return { ShaderSource[0].str(), ShaderSource[1].str() };
	}

	unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
	{
		unsigned int id = glCreateShader(type);
		const char* src = source.c_str();

		glShaderSource(type, 1, &src, NULL);

		int status;
		glGetShaderiv(type, GL_COMPILE_STATUS, &status);
		if (status != GL_TRUE)
		{
			ENGINE_CORE_ERROR("Failed to compile {0} shader!", (type == GL_VERTEX_SHADER) ? "Vertex" : "Fragment");
			
			int length, num;
			glGetShaderiv(type, GL_INFO_LOG_LENGTH, &length);
			char* log = (char*)malloc(sizeof(char) * length);
			
			glGetShaderInfoLog(type, length, &num, log);
			printf("Error Log : %s\n", log);
		}
		return id;
	}

	unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
	{
		int shader = glCreateProgram();
		int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
		int  fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

		glAttachShader(shader, vs);
		glAttachShader(shader, fs);

		glDeleteShader(vs);
		glDeleteShader(fs);

		return shader;
	}

	void Shader::SetInt(std::string& name, int value) const
	{
		glUniform1i(glGetUniformLocation(m_RendererID, name.c_str()), value);
	}

}