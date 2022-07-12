//
// Created by fstone on 2022/7/5.
//

#include <GLFW/glfw3.h>
#include <libpp/macros.h>

int main(void) {
    if (!glfwInit())
        return -1;
    auto window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, PP_STRINGIFY_E(APP_NAME), NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
