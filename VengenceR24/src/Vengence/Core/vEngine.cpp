#include "vEngine.h"

VengenceEngine::VengenceEngine()
{
    ScreenProperties = new vkScreenProperties();
}

VengenceEngine::~VengenceEngine()
{
    delete ScreenProperties;
    glfwTerminate();
}

void VengenceEngine::Initialize()
{
    if (!glfwInit())
    {
        // Initialization failed
        vLogging::error("Failed To Initialize GLFW");

        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    ScreenProperties->Width = 800;
    ScreenProperties->Height = 800;
    ScreenProperties->Window = glfwCreateWindow(ScreenProperties->Width, ScreenProperties->Height, "Vengence24", NULL, NULL);
    if (!ScreenProperties->Window)
    {
        // Window creation failed
        vLogging::error("Failed To Create GLFW Window.");
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(ScreenProperties->Window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        // GLAD initialization failed
        vLogging::error("Failed To Initialize GLAD.");
        return;
    }

    glViewport(0, 0, ScreenProperties->Width, ScreenProperties->Height);
}

void VengenceEngine::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f); // Change to 0.3f instead of 75.0f which is out of range for colors
    glfwSwapBuffers(ScreenProperties->Window);
    glfwPollEvents();
}

bool VengenceEngine::ShouldClose()
{
    return glfwWindowShouldClose(ScreenProperties->Window);
}

void VengenceEngine::GetWindowPosition(int* x, int* y)
{
    glfwGetWindowPos(ScreenProperties->Window, x, y);
}
