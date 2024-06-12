#include "VertexBufferObject.h"

VertexBufferObject::VertexBufferObject(GLfloat* vertices, GLsizeiptr size)
{
	glGenBuffers(1, &Identifier);
	glBindBuffer(GL_ARRAY_BUFFER, Identifier);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void VertexBufferObject::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, Identifier);
}

void VertexBufferObject::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBufferObject::Delete()
{
	glDeleteBuffers(1, &Identifier);
}