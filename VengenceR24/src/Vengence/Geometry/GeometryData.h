#pragma once

#include <GLFW/glfw3.h>
#include <cstddef>

namespace GeometryData
{
	extern GLfloat vertices[];
	extern GLuint indices[];
	extern GLfloat lightVertices[];
	extern GLuint lightIndices[];

	std::size_t get_sizeof_vertices();
	std::size_t get_sizeof_indices();
	std::size_t get_sizeof_lightVertices();
	std::size_t get_sizeof_lightIndices();
}