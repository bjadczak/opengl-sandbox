#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<vector>

#include "Objects\shaderClass.h"
#include "Objects\Mesh.h"
#include "Objects\Vertex.h"
#include "Objects\Texture.h"
#include "Objects\Camera.h"
#include "Objects\Model.h"

#define ARRAY_LENGTH(array) (sizeof((array))/sizeof((array)[0]))

const unsigned int screenWidth = 800;
const unsigned int screenHeight = 800;

int main()
{
    // Init GLFW
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // End Init GLFW

    // Create window and set as current context
    GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGLSandbox", NULL, NULL);
    if (window == NULL)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    // Create window and set as current context

    // Enable VSync
    glfwSwapInterval(0);

    // Init GLAD
    gladLoadGL();

    // Set viewport of OpenGL in the Window
    glViewport(0, 0, screenWidth, screenHeight);

    // Generates Shader object using shaders defualt.vert and default.frag
    Shader shaderProgram("Source\\Shaders\\default.vert", "Source\\Shaders\\default.frag");


    // Take care of all the light related things
    glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
    glm::mat4 lightModel = glm::mat4(1.0f);
    lightModel = glm::translate(lightModel, lightPos);

    shaderProgram.Activate();
    glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
    glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

    glEnable(GL_DEPTH_TEST);

    Camera camera(screenWidth, screenHeight, glm::vec3(0.0f, 0.0f, 2.0f));

    Model mapModel("Source\\Models\\map\\scene.gltf", "Source\\Models\\map\\");
    Model bunnyModel("Source\\Models\\bunny\\scene.gltf", "Source\\Models\\bunny\\");

    // Window loop
    while (!glfwWindowShouldClose(window))
    {
        // Set color of background
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        camera.Inputs(window);
        camera.updateMatrix(45.0f, 0.1f, 100.0f);

        // Draw a model
        mapModel.Draw(shaderProgram, camera);
        bunnyModel.Draw(shaderProgram, camera);

        // Swap buffers
        glfwSwapBuffers(window);
        // Any events?
        glfwPollEvents();
    }

    // Delete all the objects
    shaderProgram.Delete();

    // Termination
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}