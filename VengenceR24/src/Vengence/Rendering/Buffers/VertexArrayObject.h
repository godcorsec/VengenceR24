#pragma once
#define VAO VertexArrayObject

#include "VertexBufferObject.h"

class VertexArrayObject
{
public:
	GLuint Identifier;

	VertexArrayObject();
	
	void Bind();
	void Unbind();
	void LinkAttrib(VertexBufferObject& vbo, GLuint layout, GLuint totalComponents, GLenum type, GLsizeiptr stride, void* offset);
	void Delete();
};