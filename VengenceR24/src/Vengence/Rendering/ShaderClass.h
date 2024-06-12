#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "../Logging/Logging.h"

class Shader
{
public:
	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();

	GLuint Identifier;
	void Activate();
	void Delete();
	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;

private:
	void CheckCompileErrors(unsigned int shader, std::string type);
};