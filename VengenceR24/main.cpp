#include <iostream>
#include "./src/Vengence/Core/vEngine.h"

GLfloat vertices[] = {
	// Positions         // Colors
	 0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // Top Right
	 0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // Bottom Right
	-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  // Bottom Left
	-0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f   // Top Left 
};

GLuint indices[] = {
	0, 1, 3, // First Triangle
	1, 2, 3  // Second Triangle
};


int main()
{
    VengenceEngine* engine = new VengenceEngine();
    engine->Initialize();
    //engine->DrawWireFrame(true);

    Shader cshader("./default.vert", "./default.frag");
    cshader.Activate();

    VAO vao;
    vao.Bind();

    VBO vbo(vertices, sizeof(vertices));
    EBO ebo(indices, sizeof(indices));

    vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
    vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

    // Unbind to prevent accidental modification
    vao.Unbind();
    vbo.Unbind();
    // ebo.Unbind(); // <-- Remove this line

    while (!engine->ShouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

        vao.Bind();
        ebo.Bind(); // Bind EBO before drawing
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // Unbind the EBO after drawing
        ebo.Unbind();

        engine->SwapAndProcess();
    }

    delete engine; // Clean up
    return 0;
}
