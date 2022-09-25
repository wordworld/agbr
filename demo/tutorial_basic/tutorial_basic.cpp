// http://www.opengl-tutorial.org/cn/beginners-tutorials/

// Include standard headers
#include <stdio.h>
// Include GLEW. Always include it before gl.h and glfw3.h, since it's a bit
// magic.
#include <GL/glew.h>
// Include GLFW
#include <GLFW/glfw3.h>

#include <libpp/macros.h>

#include "draw_point.h"
#include "draw_triangle.h"

using namespace dm_triange;
// using namespace  dm_point;


int main() {
    // Initialise GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glewExperimental = GL_TRUE;
    // Open a window and create its OpenGL context
    GLFWwindow *window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, PP_STRINGIFY_E(APP_NAME), NULL, NULL);
    if (window == NULL) {
        fprintf(stderr, "Failed to open GLFW window\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return -1;
    }
    // Ensure we can capture the escape key being pressed below
    //glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    dm_init();
    do {
        // Draw nothing, see you in tutorial 2 !
        dm_draw();
        // Swap buffers
        glfwSwapBuffers(window);
        /* Poll for and process events */
        glfwPollEvents();
    } // Check if the ESC key was pressed or the window was closed
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0);
    return 0;
}