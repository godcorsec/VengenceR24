#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>

#include "../Logging/Logging.h"
#include "vCallbacks.h"
#include "../Rendering/ShaderClass.h"


#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>

struct vkScreenProperties
{
    GLFWwindow* Window;
    GLFWwindow* Shared;
    GLFWmonitor* Monitor;
    int Width;
    int Height;
    int xPos;
    int yPos;
    bool VSync;
    bool Fullscreen;
    int FrameCount = 0;
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
    void GetWindowPosition(int* x, int* y);
    void SetVSync(bool value);
    void SetFullscreen(bool value);
    void SetWindowTitle(std::string value);
    void CompileShaders();
    vkScreenProperties* ScreenProperties;
    std::vector<Shader> Shaders;
    double GetFPS();
    double OldTime = glfwGetTime();
};
