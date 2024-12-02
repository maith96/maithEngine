#define GLEW_STATIC

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
int main() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "MaithEngine", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    printf("%u\n", vertexBuffer);


    //Triangle
    float vertices[] = {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };

    //create VBO
    GLuint vbo;
    glGenBuffers(1, &vbo); //generate 1 buffer
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    while (!glfwWindowShouldClose(window)) {
        //get elapsed time since programm launch 
        float time = (float)glfwGetTime();

        // vary color based on time
        float red = (std::sin(time) + 1.0f) / 2.0f;
        float green = (std::cos(time) + 1.0f) / 2.0f;
        float blue = (std::sin(time * 2.0f) + 1.0f) / 2.0f;

        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(red, green, blue, 1.0f);

        

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}