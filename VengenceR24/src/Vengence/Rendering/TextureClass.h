#pragma once

#include <glad/glad.h>
#include <stb/stb_image.h>

#include "ShaderClass.h"


class Texture
{
public:
	Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);

	GLuint Identifier;
	GLenum Type;
	GLuint Unit;

	// Assigns a texture unit to a texture
	void TextureUnit(Shader& shader, const char* uniform, GLuint unit);
	// Binds a texture
	void Bind();
	// Unbinds a texture
	void Unbind();
	// Deletes a texture
	void Delete();
};