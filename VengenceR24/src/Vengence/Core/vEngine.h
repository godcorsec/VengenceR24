#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>

#include "../Logging/Logging.h"


struct vkScreenProperties
{
	GLFWwindow* Window;
	GLFWwindow* Shared;
	GLFWmonitor* Monitor;
	int Width;
	int Height;
	int xPos;
	int yPos;
};

class VengenceEngine
{
public:
	VengenceEngine();
	~VengenceEngine();

	void Initialize();
	void Render();
	bool ShouldClose();

private:
	vkScreenProperties* ScreenProperties;
	void GetWindowPosition(int* x, int* y);
};