// http://www.opengl-tutorial.org/cn/beginners-tutorials/tutorial-2-the-first-triangle/
#ifndef AGBR_DRAW_TRIANGLE_H
#define AGBR_DRAW_TRIANGLE_H

#include <GL/glew.h>
#include <maths/vertex.h>

namespace dm_triange {

    void dm_init() {
    }

    void dm_draw() {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        //添加数据
        float vertices[] = {
                -0.5f, -0.5f, 0.0f, // left
                0.5f, -0.5f, 0.0f, // right
                0.0f, 0.5f, 0.0f,// top
                0.5f, 0.5f, 0.0f
        };

        unsigned int VBO;
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        unsigned int VAO;
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
        glEnableVertexAttribArray(0);

        //调用几何着色器命令
        glDrawArrays(GL_TRIANGLES, 0, 3);//绘制0,1,2连城的三角
    }
}
#endif //AGBR_DRAW_TRIANGLE_H
