#include "ShaderClass.h"

Shader::~Shader(){}

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vertShaderFile;
	std::ifstream fragShaderFile;

	// Ensure ifstream objects can throw exceptions:
	vertShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fragShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		vertShaderFile.open(vertexPath);
		fragShaderFile.open(fragmentPath);
		std::stringstream vertShaderStream, fragShaderStream;

		vertShaderStream << vertShaderFile.rdbuf();
		fragShaderStream << fragShaderFile.rdbuf();

		vertShaderFile.close();
		fragShaderFile.close();

		vertexCode = vertShaderStream.str();
		fragmentCode = fragShaderStream.str();
	}
	catch (std::ifstream::failure& e)
	{
		vLogging::error("ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ:", e.what(), "\nFile Path: ", vertexPath);
	}

	const char* vertShaderCode = vertexCode.c_str();
	const char* fragShaderCode = fragmentCode.c_str();

	unsigned int vertex, fragment;

	// VERTEX SHADER

	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vertShaderCode, NULL);
	glCompileShader(vertex);
	Shader::CheckCompileErrors(vertex, "VERTEX");

	// FRAGMENT SHADER

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fragShaderCode, NULL);
	glCompileShader(fragment);
	Shader::CheckCompileErrors(fragment, "FRAGMENT");

	Shader::Identifier = glCreateProgram();
	glAttachShader(Shader::Identifier, vertex);
	glAttachShader(Shader::Identifier, fragment);
	glLinkProgram(Shader::Identifier);
	Shader::CheckCompileErrors(Shader::Identifier, "PROGRAM");

	// Delete shaders as they're already linked into the program and are no longer needed.
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Shader::Activate()
{
	glUseProgram(Shader::Identifier);
}

void Shader::Delete()
{
	glDeleteProgram(Shader::Identifier);
}

void Shader::SetFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(Shader::Identifier, name.c_str()), value);
}

void Shader::SetBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(Shader::Identifier, name.c_str()), (int)value);
}

void Shader::SetInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(Shader::Identifier, name.c_str()), value);

}

void Shader::CheckCompileErrors(unsigned int shader, std::string type)
{
	int Success;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &Success);
		if (!Success)
		{
			glGetShaderInfoLog(shader, sizeof(infoLog), NULL, infoLog);
			vLogging::error("ERROR::SHADER_COMPILATION_ERROR of type:", type, "\n", infoLog);
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &Success);
		if (!Success)
		{
			glGetProgramInfoLog(shader, sizeof(infoLog), NULL, infoLog);
			vLogging::error("ERROR::PROGRAM_LINKING_ERROR of type:", type, "\n", infoLog);

		}
	}
}