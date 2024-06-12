#include "ElementBufferObject.h"


ElementBufferObject::ElementBufferObject(GLuint* indices, GLsizeiptr size)
{
	glGenBuffers(1, &Identifier);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Identifier);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

void ElementBufferObject::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Identifier);
}

void ElementBufferObject::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ElementBufferObject::Delete()
{
	glDeleteBuffers(1, &Identifier);
}