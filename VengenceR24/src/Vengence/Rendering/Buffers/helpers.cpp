#include "helpers.h"

void vUnbind_Buffers(VertexArrayObject* vao, VertexBufferObject* vbo, ElementBufferObject* ebo)
{
	vao->Unbind();
	vbo->Unbind();
	ebo->Unbind();
}