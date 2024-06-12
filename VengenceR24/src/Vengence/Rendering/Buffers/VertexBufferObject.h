#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define VBO VertexBufferObject  // allows me to use either VBO() or VertexBufferObject()

class VertexBufferObject
{
public:
	GLuint Identifier;

	VertexBufferObject(GLfloat* vertices, GLsizeiptr size);

	void Bind();
	void Unbind();
	void Delete();
};