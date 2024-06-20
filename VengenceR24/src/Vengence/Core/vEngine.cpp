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
        vLogging::error("Failed To Initialize GLFW");
        return;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    ScreenProperties->Width = 800;
    ScreenProperties->Height = 800;
    ScreenProperties->FrameCount = 0;
    ScreenProperties->DrawWireframe = false;
    ScreenProperties->Window = glfwCreateWindow(ScreenProperties->Width, ScreenProperties->Height, "Vengence24", NULL, NULL);
    if (!ScreenProperties->Window)
    {
        vLogging::error("Failed To Create GLFW Window.");
        glfwTerminate();
        return;
    }



    glfwMakeContextCurrent(ScreenProperties->Window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        vLogging::error("Failed To Initialize GLAD.");
        return;
    }

    VengenceEngine::SetVSync(true);

    glfwSetFramebufferSizeCallback(ScreenProperties->Window, vCallbacks::framebuffer_size_callback);

    glViewport(0, 0, ScreenProperties->Width, ScreenProperties->Height);
}

bool VengenceEngine::ShouldClose()
{
    return glfwWindowShouldClose(ScreenProperties->Window);
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

void VengenceEngine::SwapAndProcess()
{
    glfwSwapBuffers(ScreenProperties->Window);
    glfwPollEvents();
}

void VengenceEngine::Render()
{
    VengenceEngine::Update();

    double fps = VengenceEngine::GetFPS();
    if (fps != 0.0) {
        VengenceEngine::SetWindowTitle("Vengence24: FPS: " + std::to_string(fps) + "  W: " + std::to_string(ScreenProperties->Width) + "  H: " + std::to_string(ScreenProperties->Height));
    }

    if (ScreenProperties->DrawWireframe)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }


    //glfwSwapBuffers(ScreenProperties->Window);
    //glfwPollEvents();
}

void VengenceEngine::UpdateCamera(Camera* camera)
{
    camera->width = ScreenProperties->Width;
    camera->height = ScreenProperties->Height;
}

//GET FUNCTIONS
double VengenceEngine::GetFPS()
{
    double CurrentTime = glfwGetTime();
    ScreenProperties->FrameCount++;

    if (CurrentTime - DeltaTime >= 1.0)
    {
        double fps = ScreenProperties->FrameCount / (CurrentTime - DeltaTime);
        DeltaTime = CurrentTime;
        ScreenProperties->FrameCount = 0;
        return fps;
    }

    return 0.0;
}
void VengenceEngine::GetWindowPosition(int* x, int* y)
{
    glfwGetWindowPos(ScreenProperties->Window, x, y);
    
}
void VengenceEngine::GetWindowSize(int* width, int* height)
{
    glfwGetWindowSize(ScreenProperties->Window, &ScreenProperties->Width, &ScreenProperties->Height);
}


//SET FUNCTIONS

void VengenceEngine::SetFullscreen(bool value)
{
    if (value) ScreenProperties->Fullscreen = true;
    else ScreenProperties->Fullscreen = false;
}

void VengenceEngine::SetWindowTitle(std::string value)
{
    glfwSetWindowTitle(ScreenProperties->Window, value.c_str());
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

void VengenceEngine::Update()
{
    VengenceEngine::GetWindowPosition(&ScreenProperties->xPos, &ScreenProperties->yPos);
    VengenceEngine::GetWindowSize(&ScreenProperties->Width, &ScreenProperties->Height);

    vCallbacks::processInput(ScreenProperties->Window, this);
}