#pragma once

#define EBO ElementBufferObject

#include <glad/glad.h>
#include <GLFW/glfw3.h>


class ElementBufferObject
{
public:
	GLuint Identifier;

	ElementBufferObject(GLuint* indices, GLsizeiptr size);
	void Bind();
	void Unbind();
	void Delete();
};