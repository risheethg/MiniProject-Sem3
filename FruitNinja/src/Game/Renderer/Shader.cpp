#include "pch.h"
#include "Shader.h"

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
			NONE = -1, VERTEX = 0, FRAGMENT = 1
		};

		std::string line;
		std::stringstream ss[2];
		ShaderType type = ShaderType::NONE;

		while (getline(stream, line))
		{
			if (line.find("#shader") != std::string::npos) 
			{
				if (line.find("vertex") != std::string::npos)
				{
					type = ShaderType::VERTEX;
				} 
				else if (line.find("fragment") != std::string::npos)
				{
					type = ShaderType::FRAGMENT;
				}
			} 
			else 
			{
				ss[(int)type] << line << "\n";
			}
		}

		return { ss[0].str(), ss[1].str() };
	}

	unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
	{
		unsigned int id = glCreateShader(type);
		const char* src = source.c_str();

		glShaderSource(id, 1, &src, NULL);
		glCompileShader(id);
		
		int status;
		glGetShaderiv(id, GL_COMPILE_STATUS, &status);
		if (status == GL_FALSE)
		{
			ENGINE_CORE_ERROR("Failed to compile {0} shader!", (type == GL_VERTEX_SHADER) ? "Vertex" : "Fragment");
			
			int length, num;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char* log = (char*)alloca(sizeof(char) * length);
			
			glGetShaderInfoLog(id, length, &num, log);
			ENGINE_ERROR("{0} Shader Error Log : {1}\n", (type == GL_VERTEX_SHADER) ? "Vertex" : "Fragment", log);
			glDeleteProgram(id);
		}
		return id;
	}

	unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
	{
		unsigned int shader = glCreateProgram();
		unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
		unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

		glAttachShader(shader, vs);
		glAttachShader(shader, fs);
		glLinkProgram(shader);
		glValidateProgram(shader);

		glDeleteShader(vs);
		glDeleteShader(fs);

		return shader;
	}

	void Shader::SetInt(const std::string& name, int value) const
	{
		glUniform1i(glGetUniformLocation(m_RendererID, name.c_str()), value);
	}

	void Shader::SetFloat(const std::string& name, float value) const
	{
		glUniform1f(glGetUniformLocation(m_RendererID, name.c_str()), value);
	}

}