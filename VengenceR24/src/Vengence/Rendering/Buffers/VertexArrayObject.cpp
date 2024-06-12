#include "VertexArrayObject.h"

VertexArrayObject::VertexArrayObject()
{
	glGenVertexArrays(1, &Identifier);
}

void VertexArrayObject::Bind()
{
	glBindVertexArray(Identifier); // Bind to its own identifier, not 0
}

void VertexArrayObject::LinkAttrib(VertexBufferObject& vbo, GLuint layout, GLuint totalComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	vbo.Bind();
	glVertexAttribPointer(layout, totalComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	vbo.Unbind();
}

void VertexArrayObject::Delete()
{
	glDeleteVertexArrays(1, &Identifier);
}

void VertexArrayObject::Unbind()
{
	glBindVertexArray(0);
}