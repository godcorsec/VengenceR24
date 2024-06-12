#include "vEngine.h"

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

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

    VengenceEngine::SetVSync(false);

    glfwSetFramebufferSizeCallback(ScreenProperties->Window, vCallbacks::framebuffer_size_callback);

    glViewport(0, 0, ScreenProperties->Width, ScreenProperties->Height);
    vLogging::info("Loaded Vengence With 0 Errors.");
}

bool VengenceEngine::ShouldClose()
{
    return glfwWindowShouldClose(ScreenProperties->Window);
}

void VengenceEngine::GetWindowPosition(int* x, int* y)
{
    glfwGetWindowPos(ScreenProperties->Window, x, y);
    
}

void VengenceEngine::SetVSync(bool value)
{
    if (value) ScreenProperties->VSync = true;
    else ScreenProperties->VSync = false;

    if (ScreenProperties->VSync)
    {
        glfwSwapInterval(1);
    }
    else
    {
        glfwSwapInterval(0);
    }
}

void VengenceEngine::SetFullscreen(bool value)
{
    if (value) ScreenProperties->Fullscreen = true;
    else ScreenProperties->Fullscreen = false;
}

double VengenceEngine::GetFPS()
{
    double CurrentTime = glfwGetTime();
    ScreenProperties->FrameCount++;

    if (CurrentTime - OldTime >= 1.0)
    {
        double fps = ScreenProperties->FrameCount / (CurrentTime - OldTime);
        OldTime = CurrentTime;
        ScreenProperties->FrameCount = 0;
        return fps;
    }

    return 0.0;
}

void VengenceEngine::SetWindowTitle(std::string value)
{
    glfwSetWindowTitle(ScreenProperties->Window, value.c_str());
}


void VengenceEngine::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

    double fps = VengenceEngine::GetFPS();
    if (fps != 0.0) {
        VengenceEngine::SetWindowTitle("Vengence24: FPS: [ " + std::to_string(fps) + " ]");
    }

    Shader programShader("ea.v", "er");


    glfwSwapBuffers(ScreenProperties->Window);
    glfwPollEvents();
}

void VengenceEngine::CompileShaders()
{
    std::vector<std::pair<const char*, const char*>> shaderPaths = {
        {"shader.vert", "shader.frag"},
        {"shader2.vert", "shader2.frag"}
    };

    for (const auto& paths : shaderPaths)
    {
        VengenceEngine::Shaders.emplace_back(paths.first, paths.second);
    }
}