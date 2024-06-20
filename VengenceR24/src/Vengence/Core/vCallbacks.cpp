#include "vCallbacks.h"


void vCallbacks::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{

	glViewport(0, 0, width, height);
}

void vCallbacks::processInput(GLFWwindow* window, VengenceEngine* engine)
{
    static bool TAB_KEY_PRESSED = false;

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_TAB) == GLFW_PRESS)
    {
        if (!TAB_KEY_PRESSED)
        {
            engine->ScreenProperties->DrawWireframe = !engine->ScreenProperties->DrawWireframe;
            TAB_KEY_PRESSED = true;
        }
    }
    else
    {
        TAB_KEY_PRESSED = false;
    }
}