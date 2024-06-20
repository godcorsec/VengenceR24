#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>

#include "../Logging/Logging.h"
#include "vCallbacks.h"
#include "../Rendering/ShaderClass.h"
#include "../Rendering/Buffers/BUFFERS.h"
#include "../Game-Core/vCamera.h"
//#include "../Geometry/GeometryData.h"
#include "../Rendering/TextureClass.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>
#include <unordered_set>

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
    bool DrawWireframe;
    int FrameCount;
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
    void DrawWireframe(bool value);
    vkScreenProperties* ScreenProperties;

private:
    void Update();
    void GetWindowSize(int* width, int* height);
    void GetWindowPosition(int* x, int* y);
    void SetVSync(bool value);
    void SetFullscreen(bool value);
    void SetWindowTitle(std::string value);
    void CompileShaders();
    std::vector<Shader> Shaders;
    double GetFPS();
    double DeltaTime = glfwGetTime();
};
