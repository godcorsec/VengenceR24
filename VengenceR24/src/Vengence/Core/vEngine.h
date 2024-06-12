#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>

#include "../Logging/Logging.h"
#include "vCallbacks.h"
#include "../Rendering/ShaderClass.h"
#include "../Rendering/Buffers/BUFFERS.h"


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
    void SwapAndProcess();
    bool ShouldClose();
    void DrawWireFrame(bool value)
    {
        if(value) { glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); }
        else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

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
