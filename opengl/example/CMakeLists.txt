# agbr/opengl/example/CMakeLists.txt
INCLUDE(../../cmake/FileBaseList.cmake)

# library
link_libraries(
        ${OPENGL_LIBRARIES}
        glewd
        glfw3
)

# src
LIST(APPEND SRC_LIST ${maths})

# targets
FileBaseList(${CMAKE_CURRENT_SOURCE_DIR}/ *.cpp example_list)
MESSAGE("example_list: ${example_list}")
FOREACH (demo ${example_list})
    add_executable(${demo} ${demo}.cpp ${SRC_LIST})
ENDFOREACH (demo)