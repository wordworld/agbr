// https://doc.yonyoucloud.com/doc/wiki/project/modern-opengl-tutorial/tutorial2.html
#ifndef AGBR_DRAW_POINT_H
#define AGBR_DRAW_POINT_H

#include <GL/glew.h>
#include <maths/vertex.h>

namespace dm_point {
    GLuint VBO;
    GLfloat vertices[] = {0, 0, 0};

    void dm_init() {
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
    }

    void dm_draw() {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glDrawArrays(GL_POINTS, 0, 1);
        glDisableVertexAttribArray(0);
    }
}

#endif //AGBR_DRAW_POINT_H
